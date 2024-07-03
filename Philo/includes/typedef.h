/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:28:23 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/02 17:13:26 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H

# define TYPEDEF_H

typedef struct s_args
{
	int				n_philo;
	int				death_timer;
	int				eat_timer;
	int				sleep_timer;
	int				minimum_eat;
}					t_args;

struct	s_philo_room;

typedef struct s_philo
{
	pthread_t		thread;
	int				n_philo;
	int				id;
	int				eating;
	int				meal_count;
	size_t			last_meal;
	size_t			death_timer;
	size_t			eat_timer;
	size_t			sleep_timer;
	size_t			start;
	int				n_philos;
	int				minimum_eat;
	int				*dead;
	pthread_mutex_t	*meal_m;
	pthread_mutex_t	*dead_m;
	pthread_mutex_t	*write_m;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_philo_room
{
	int				dead;
	pthread_mutex_t	dead_m;
	pthread_mutex_t	meal_m;
	pthread_mutex_t	write_m;
	t_philo			**philos;
}					t_philo_room;

#endif