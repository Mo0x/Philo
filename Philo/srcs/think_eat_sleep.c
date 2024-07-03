/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_eat_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:00:11 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/02 17:47:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_think(t_philo *philo)
{
	wwrite("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	wwrite("is sleeping", philo);
	ft_time_out(philo->sleep_timer);
}

int	ft_eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->r_fork) < 0)
		return (-1);
	wwrite("has taken a fork", philo);
	if (philo->n_philos == 1)
	{
		ft_time_out(philo->death_timer);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	if (pthread_mutex_lock(philo->l_fork) < 0)
		return (-1);
	wwrite("has taken a fork", philo);
	philo->eating = 1;
	wwrite("is eating", philo);
	pthread_mutex_lock(philo->meal_m);
	philo->last_meal = give_me_time();
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_m);
	ft_time_out(philo->eat_timer);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}
