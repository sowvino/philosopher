/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 13:56:08 by selango           #+#    #+#             */
/*   Updated: 2024-11-05 13:56:08 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*destroy all the thread*/
void	destroy_all(char *str, t_philo *philo)
{
	int i ;
    int philo_count;
    philo_count = philo[0].philo_nbr;
    i =0;
    if (str)
		printf("%s", str);
    pthread_mutex_destroy(philo->dead_lock);
    pthread_mutex_destroy(philo->write_lock);
    pthread_mutex_destroy(philo->meal_lock);
    while(i < philo_count)
    {
        pthread_mutex_destroy(&philo->lock->forks[i]);
        i++;
    }
}
