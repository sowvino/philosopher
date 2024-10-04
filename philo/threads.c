/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-03 13:33:16 by selango           #+#    #+#             */
/*   Updated: 2024-10-03 13:33:16 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// dead_loop initialising
int     dead_loop(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if(philo->lock->dead_flag == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return(1);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return(0);
}

// philo_routine actions
void *philo_state(void *pointer)
{
    t_philo *philo;
    philo = (t_philo *)pointer;
    if((philo->philo_id)% 2 == 0)
        ft_usleep(2);
    while(!dead_loop(philo))
    {
        eat(philo);
        ft_sleep(philo);
        think(philo);
    }
    return(pointer);
}

