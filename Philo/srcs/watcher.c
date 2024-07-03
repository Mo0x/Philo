/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:19:15 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/02 17:57:56 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	rip_philo(t_philo *philo, size_t death_timer)
{
	pthread_mutex_lock(philo->meal_m);
	if (give_me_time() - philo->last_meal >= death_timer && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_m), 1);
	pthread_mutex_unlock(philo->meal_m);
	return (0);
}

int	am_i_dead(t_philo_room *room)
{
	int	i;

	i = 0;
	while (i < room->philos[0]->n_philo)
	{
		if (rip_philo(room->philos[i], room->philos[i]->death_timer))
		{
			wwrite("died", room->philos[i]);
			pthread_mutex_lock(room->philos[i]->dead_m);
			room->dead = 1;
			pthread_mutex_unlock(room->philos[i]->dead_m);
			return (1);
		}
		i++;
	}
	return (0);
}

int	did_they_eat(t_philo_room *room)
{
	int	i;
	int	done_eating;

	i = -1;
	done_eating = 0;
	if (room->philos[0]->minimum_eat == -1)
		return (0);
	while (++i < room->philos[0]->n_philo)
	{
		if (pthread_mutex_lock(room->philos[i]->meal_m) < 0)
			return (-1);
		if (room->philos[i]->meal_count >= room->philos[i]->minimum_eat)
			done_eating++;
		pthread_mutex_unlock(room->philos[i]->meal_m);
	}
	if (done_eating == room->philos[0]->n_philo)
	{
		pthread_mutex_lock(room->philos[0]->dead_m);
		room->dead = 1;
		pthread_mutex_unlock(room->philos[0]->dead_m);
		return (1);
	}
	return (0);
}

void	*do_the_watch_thing(void *room_v)
{
	t_philo_room	*room;

	room = (t_philo_room *)room_v;
	while (1)
	{
		if (am_i_dead(room) == 1 || did_they_eat(room) == 1 || \
		did_they_eat(room) == -1)
			break ;
	}
	return (room);
}
