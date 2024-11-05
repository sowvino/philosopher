/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-03 13:56:04 by selango           #+#    #+#             */
/*   Updated: 2024-10-03 13:56:04 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*check if the philo is dead*/

int	philo_dead(t_philo *philo)
{
	size_t	time_die;
	size_t	last_meal;

	time_die = philo->time_to_die;
	last_meal = philo->last_meal_time;
	pthread_mutex_lock(philo->meal_lock);
	if ((philo->eating == 0) || ((get_current_time() - last_meal) >= time_die))
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}
/*checks if any of the philo is dead*/
void	dead_checker(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	*philo->dead = 1;
	philo->lock->dead_flag = 1;
	print_state("is died", philo, philo->philo_id);
	pthread_mutex_unlock(philo->dead_lock);
}

int	checker_philo_dead(t_philo *philo)
{
	int	i;
	int	philo_count;

	i = 0;
	philo_count = philo[0].philo_nbr;
	while (i < philo_count)
	{
		if (philo_dead(philo))
		{
            dead_checker(philo);
            return(1);
		}
		i++;
	}
	return (0);
}
/*checks if all the philo ate the num of meals*/
int	checker_philo_ate(t_philo *philo)
{
	int	completed_eating;
	int	i;

	completed_eating = 0;
	i = 0;

	if (philo[0].nbr_meals_fed == -1)
		return (0);
	while (i < philo[0].nbr_meals_fed)
	{
		pthread_mutex_lock(philo->meal_lock);
		if (philo[i].meals_eaten >= philo[i].nbr_meals_fed)
		{
			completed_eating++;
		}
		pthread_mutex_unlock(philo->meal_lock);
		i++;
	}
	if (completed_eating == philo[0].philo_nbr)
	{
		dead_checker(philo);
	}
	return (0);
}

void *monitor(void *pointer)
{
    t_philo *philo;
    philo = (t_philo *) pointer;
    while(1)
    {
        if(checker_philo_dead(philo) == 1 || checker_philo_ate(philo) == 1)
            break;
    }
    return(pointer);

}
