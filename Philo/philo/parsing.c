/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 13:23:37 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 13:23:37 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*convert arg to int numbers checklist:
1.actual nbr
2.not > INT_MAX
3.timestamps > 60ms
*/
void    parse_input(t_philo *philo,char **argv)
{
    philo->philo_nbr = ft_atol(argv[1]);
    if(philo->philo_nbr > 200)
    {
        error_msg("Please enter the philo number less than 200\n");
    }
    philo->time_to_die = ft_atol(argv[2]);
    philo->time_to_eat = ft_atol(argv[3]);
    philo->time_to_sleep =ft_atol(argv[4]);
    if(argv[5])
    {
        philo->nbr_meals_fed = ft_atol(argv[5]);
    }
    else
        philo->nbr_meals_fed = -1;

}
