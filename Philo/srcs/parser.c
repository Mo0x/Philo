/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:20:08 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 16:50:57 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_args	*init_t_args(void)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->n_philo = 0;
	args->death_timer = 0;
	args->eat_timer = 0;
	args->sleep_timer = 0;
	args->minimum_eat = 0;
	return (args);
}

int	ft_parser(int argc, char **argv, t_args *args)
{
	int	error;

	error = 0;
	args->n_philo = ft_atoi_overflow(argv[1], &error);
	if (error || args->n_philo < 1)
		return (ft_eq("Error inputs\n"));
	args->death_timer = ft_atoi_overflow(argv[2], &error);
	if (error || args->death_timer < 1)
		return (ft_eq("Error inputs\n"));
	args->eat_timer = ft_atoi_overflow(argv[3], &error);
	if (error || args->eat_timer < 1)
		return (ft_eq("Error inputs\n"));
	args->sleep_timer = ft_atoi_overflow(argv[4], &error);
	if (error || args->sleep_timer < 1)
		return (ft_eq("Error inputs\n"));
	if (argc == 6)
	{
		args->minimum_eat = ft_atoi_overflow(argv[5], &error);
		if (error || args->minimum_eat < 0)
			return (ft_eq("Error inputs\n"));
	}
	else
		args->minimum_eat = -1;
	return (0);
}
