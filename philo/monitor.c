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

int philo_dead(t_philo *philo)
{
    size_t time_die;
    time_die = philo->time_to_die;

    size_t time_meal;
    time_meal = philo->last_meal;

    pthread_mutex_lock(philo->meal_lock);

    if((philo->eating == 0) || ((get_current_time() - philo->last_meal) >= time_die)) 
    {
        pthread_mutex_unlock(philo->meal_lock);
        return(1);
    }
    pthread_mutex_unlock(philo->meal_lock);
    return(0);
}

int checker_philo_dead(t_philo *philo)
{
    int i ;
    i =0;
    while (i < philo[i].philo_nbr)
    {
        if(philo_dead(philo))
        {
            pthread_mutex_lock(philo->dead_lock);
            *philo->dead =1;
            philo->lock->dead_flag =1;
            print_state("is died",philo,philo->philo_id);
            pthread_mutex_unlock(philo->dead_lock);
        }
        i++;
    }
    return(0);
}

