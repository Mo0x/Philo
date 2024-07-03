/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:15:44 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 16:30:07 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include "typedef.h"

/*utils*/
int				ft_strlen(char *s);
int				ft_atoi_overflow(const char *str, int *error);
size_t			give_me_time(void);
void			wwrite(char *s, t_philo *philo);
int				ft_freed_from_desire(char *s, t_args *args, t_philo_room *room,
					pthread_mutex_t *forks);
int				ft_time_out(size_t ms);

/*error*/
int				ft_error_argc(void);
int				ft_eq(char *msg);

/*parser*/
t_args			*init_t_args(void);
int				ft_parser(int argc, char **argv, t_args *args);

/*init*/
t_philo_room	*ft_init(pthread_mutex_t **forks, t_args *args);

/*routines*/
void			ft_think(t_philo *philo);
void			ft_sleep(t_philo *philo);
int				ft_eat(t_philo *philo);
int				not_dead_yet(t_philo *philo);
int				ft_do_the_thread_thing(t_philo_room *room,
					pthread_mutex_t *forks, t_args *args);
void			*do_the_watch_thing(void *philo_holder);

#endif