/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:18:08 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 16:38:07 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_time_out(size_t ms)
{
	size_t	start;

	start = give_me_time();
	while (give_me_time() - start < ms)
		usleep(500);
	return (0);
}

void	wwrite(char *s, t_philo *philo)
{
	size_t	t;

	pthread_mutex_lock(philo->write_m);
	t = give_me_time() - philo->start;
	if (!not_dead_yet(philo))
		printf("%zu %d %s\n", t, philo->id, s);
	pthread_mutex_unlock(philo->write_m);
}

void	init_freed(int *i, int *keep, t_args *args)
{
	*i = -1;
	*keep = args->n_philo;
}

int	ft_freed_from_desire(char *s, t_args *args, t_philo_room *room,
		pthread_mutex_t *forks)
{
	int	i;
	int	keep;

	init_freed(&i, &keep, args);
	free(args);
	if (room)
	{
		while (++i < keep)
			free(room->philos[i]);
		free(room->philos);
		pthread_mutex_destroy(&room->dead_m);
		pthread_mutex_destroy(&room->meal_m);
		pthread_mutex_destroy(&room->write_m);
		free(room);
	}
	i = -1;
	if (forks)
	{
		while (++i < keep)
			pthread_mutex_destroy(&forks[i]);
		free(forks);
	}
	if (s)
		write(2, s, ft_strlen(s));
	return (-1);
}
