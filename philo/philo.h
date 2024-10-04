/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 12:07:38 by selango           #+#    #+#             */
/*   Updated: 2024-10-02 12:07:38 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct lock	t_lock;
typedef struct philo
{
	pthread_t		thread;
	int				philo_id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			end_time;
	int				philo_nbr;
	int				nbr_meals_fed;
	int				*dead;
	t_lock			*lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
}					t_philo;

typedef struct lock
{
	int				dead_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	t_philo			*philo;
}					t_lock;

/*utilis*/
int					ft_isdigit(char c);
size_t				get_current_time(void);
long				ft_atol(const char *s);
int					ft_usleep(size_t millisecond);
/* parse the value*/
void				parse_input(t_philo *philo, char **argv);

/* error msg printing */
void				error_msg(char *error);
/*init the data */
void				data_init(t_philo *philo);

/*thread creation*/
int					dead_loop(t_philo *philo);
void				*philo_state(void *pointer);

/*routine action by philo*/
void				print_state(char *str, t_philo *philo, int id);
void				think(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				eat(t_philo *philo);

/*monitor system*/
int					philo_dead(t_philo *philo);
int					checker_philo_dead(t_philo *philo);

#endif