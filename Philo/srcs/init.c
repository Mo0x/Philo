/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:05:22 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 16:31:05 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*ft_create_thrilo(t_args *args, int i, t_philo_room *room)
{
	t_philo	*ret;

	ret = malloc(sizeof(t_philo));
	if (!ret)
		return (NULL);
	ret->id = i;
	ret->eating = 0;
	ret->meal_count = 0;
	ret->n_philo = args->n_philo;
	ret->death_timer = args->death_timer;
	ret->eat_timer = args->eat_timer;
	ret->sleep_timer = args->sleep_timer;
	ret->start = give_me_time();
	ret->last_meal = give_me_time();
	ret->n_philos = args->n_philo;
	ret->minimum_eat = args->minimum_eat;
	ret->dead = &room->dead;
	ret->meal_m = &room->meal_m;
	ret->dead_m = &room->dead_m;
	ret->write_m = &room->write_m;
	return (ret);
}

t_philo	**ft_init_thrilosophers(t_args *args, t_philo_room *room,
		pthread_mutex_t *forks)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * args->n_philo);
	if (!philos)
		return (NULL);
	while (i < args->n_philo)
	{
		philos[i] = ft_create_thrilo(args, i, room);
		if (!philos[i])
			return (NULL);
		philos[i]->l_fork = &forks[i];
		if (i == 0)
			philos[i]->r_fork = &forks[philos[i]->n_philo - 1];
		else
			philos[i]->r_fork = &forks[i - 1];
		i++;
	}
	return (philos);
}

t_philo_room	*ft_init_room(t_args *args, pthread_mutex_t *forks)
{
	t_philo_room	*room;

	room = malloc(sizeof(t_philo_room));
	if (!room)
		return (NULL);
	room->dead = 0;
	if (pthread_mutex_init(&(room->dead_m), NULL) < 0)
		return (NULL);
	if (pthread_mutex_init(&(room->meal_m), NULL) < 0)
		return (NULL);
	if (pthread_mutex_init(&(room->write_m), NULL) < 0)
		return (NULL);
	room->philos = ft_init_thrilosophers(args, room, forks);
	if (!room->philos)
		return (NULL);
	return (room);
}

pthread_mutex_t	*ft_init_forks(int tot)
{
	int				i;
	pthread_mutex_t	*ret;

	i = -1;
	ret = malloc(sizeof(pthread_mutex_t) * tot);
	if (!ret)
		return (NULL);
	while (++i < tot)
		pthread_mutex_init(&ret[i], NULL);
	return (ret);
}

t_philo_room	*ft_init(pthread_mutex_t **forks, t_args *args)
{
	t_philo_room	*room;

	*forks = ft_init_forks(args->n_philo);
	if (!(*forks))
		return (NULL);
	room = ft_init_room(args, *forks);
	if (!room)
		return (NULL);
	return (room);
}
