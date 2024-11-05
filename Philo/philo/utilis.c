/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 13:07:22 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 13:07:22 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(char c)
{
    return(c >= '0' && c <= '9');
}
static const char *valid_input (const char *s)
{
    int len;
    const char *number;
    len =0;
    while ((*s == 32) || (*s >= 9 && *s <= 13))
    {
        s++;
    }
    if(*s == '+')
        s++;
    else if(*s == '-')
        error_msg("Only positive values are allowed\n");
    if(!ft_isdigit(*s))
    {
        error_msg("Only digits are allowed\n");
    }
    number  = s;
    while(ft_isdigit(*s))
    {
        len++;
        s++;
    }
    if(len > 10)
        error_msg("Value is high, INT_MAX is the limit");
    return(number); 
}

long	ft_atol(const char *s)
{
	long	result;

	result = 0;
    s = valid_input(s);//check for correct input

	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
    if(result > INT_MAX)
        error_msg("Value is high, INT_MAX is the limit");
	return (result);
}
void error_msg(char *error)
{
    printf("%s\n",error);
    exit(EXIT_FAILURE);
}

size_t get_current_time()
{
    struct timeval time;
    if(gettimeofday(&time,NULL) == -1)  
    {
        error_msg("time_stamp error\n");
    }
    return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

int ft_usleep(size_t millisecond)
{
    size_t start;
    start = get_current_time();
    while((get_current_time() - start ) < millisecond)
        usleep(200);
    return(0);
}
