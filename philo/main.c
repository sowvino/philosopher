/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 12:52:29 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 12:52:29 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


/*
input [nbr of philo,time_to_die,time_to_eat,time_to_sleep]
./philo [5,800,200,200,optional]
*/

int main(int argc,char **argv)
{
    t_philo philo;
    if(argc == 5 || argc == 6)
    {
        parse_input(&philo,argv);
        data_init(&philo);
        dinner_start(&philo);
        clean(&philo);
    }
    else
    {
        error_msg("Enter correct number of arguments\n");
        return(1);
    }
}