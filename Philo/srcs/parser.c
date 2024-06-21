/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:20:08 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/17 15:59:19 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_args	*init_t_args(void)
{
	t_args	*args;

	args = walloc(sizeof(t_args));
	args->n_philo = 0;
	args->death_timer = 0;
	args->eat_timer = 0;
	args->sleep_timer = 0;
	args->minimum_eat = 0;
	return (args);
}

void	ft_parser(int argc, char **argv, t_args *args)
{
	int	error;

	error = 0;
	args->n_philo = ft_atoi_overflow(argv[1], &error);
	if (error)
		return (ft_eq("overflow detected\n"));
	args->death_timer = ft_atoi_overflow(argv[2], &error);
	if (error)
		return (ft_eq("overflow detected\n"));
	args->eat_timer = ft_atoi_overflow(argv[3], &error);
	if (error)
		return (ft_eq("overflow detected\n"));
	args->sleep_timer = ft_atoi_overflow(argv[4], &error);
	if (error)
		return (ft_eq("overflow detected\n"));
	if (argc == 6)
	{
		args->minimum_eat = ft_atoi_overflow(argv[5], &error);
		if(error)
			return (ft_eq("overflow detected\n"));
	}
	else
		args->minimum_eat = -1;
}
