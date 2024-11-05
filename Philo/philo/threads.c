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

int dinner_start(t_philo *philo)
{
    pthread_t observer;
    int i;
    i =0;

    if(pthread_create(&observer,NULL,&monitor,philo) != 0)
        destroy_all("Thread error creation",philo);
    while(i < philo[0].philo_nbr)
    {
        if(pthread_create(&philo[i].thread,NULL,&philo_state,&philo[i])!= 0)
            destroy_all("Thread error creation",philo);
        i++;
    }
    i = 0;
    if(pthread_join(observer,NULL) != 0)
        destroy_all("Thread join error",philo);
    while(i < philo[0].philo_nbr)
    {
        if(pthread_join(philo[i].thread,NULL)!= 0)
            destroy_all("Thread join error",philo);
        i++;
    }
    return(0);
}
