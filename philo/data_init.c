/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-03 11:51:52 by selango           #+#    #+#             */
/*   Updated: 2024-10-03 11:51:52 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// initialising philo.
void init_philo(t_philo *philo)
{
    int i ;
    i =0;
    int philo_count = philo[0].philo_nbr;
    while (i < philo_count)
    {
        philo[i].philo_id = i+1;
        philo[i].eating = 0;
        philo[i].meals_eaten  =0;
        philo[i].start_time = get_current_time();
        philo[i].last_meal = get_current_time();
        philo[i].write_lock = &philo[i].lock->write_lock;
        philo[i].meal_lock = &philo[i].lock->meal_lock;
        philo[i].dead_lock = &philo[i].lock->dead_lock;
        philo[i].l_fork =&philo[i].lock->forks[i];
        if(i == 0)
            philo[i].r_fork = &philo[i].lock->forks[philo_count -1 ];
        else
            philo[i].r_fork = &philo[i].lock->forks[i -1];
        i++;
    }
}

//init forks  
void init_forks(t_philo *philo)
{
    int i;
    i =0;
    int philo_count =  philo[0].philo_nbr;
    while(i < philo_count)
    {
        pthread_mutex_init(&philo[i].lock->forks[i],NULL);
        i++;
    }
}
void init_lock(t_philo *philo)
{
    philo->lock->philo = philo;
    philo->lock->dead_flag = 0;
    pthread_mutex_init(&philo->lock->write_lock,NULL);
    pthread_mutex_init(&philo->lock->meal_lock,NULL);
    pthread_mutex_init(&philo->lock->dead_lock,NULL);
}
void data_init(t_philo *philo)
{
    init_philo(philo);
    init_forks(philo);
    init_lock(philo);
}
