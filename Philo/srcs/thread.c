/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:58:35 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 16:36:43 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* TODO do the watch thing, and pphilo thingy*/

int	not_dead_yet(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_m);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_m), 1);
	pthread_mutex_unlock(philo->dead_m);
	return (0);
}

void	*philo_thingy(void *philo_holder)
{
	t_philo	*philo;
	int		error;

	error = 0;
	philo = (t_philo *)philo_holder;
	if (philo->id % 2 == 0)
		ft_time_out(1);
	while (!not_dead_yet(philo))
	{
		error = ft_eat(philo);
		if (error)
			return (NULL);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (philo_holder);
}

int	ft_do_the_thread_thing(t_philo_room *room, pthread_mutex_t *forks,
		t_args *args)
{
	pthread_t	watcher;
	int			i;

	i = -1;
	if (pthread_create(&watcher, NULL, &do_the_watch_thing, room) != 0)
		return (ft_freed_from_desire("Error watcher creation", args, room, \
				forks));
	while (++i < args->n_philo)
	{
		if (pthread_create(&room->philos[i]->thread, NULL, &philo_thingy,
				room->philos[i]) != 0)
			return (ft_freed_from_desire("Error philo creation", args, room, \
					forks));
	}
	i = -1;
	if (pthread_join(watcher, NULL) != 0)
		ft_freed_from_desire("Error join", args, room, forks);
	while (++i < args->n_philo)
	{
		if (pthread_join(room->philos[i]->thread, NULL) != 0)
			return (ft_freed_from_desire("Error join philo", args, room, \
					forks));
	}
	return (0);
}
