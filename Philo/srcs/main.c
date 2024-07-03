/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:13:57 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 16:29:19 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
Think = print X is thinking
Sleep = sleep length of sleep_timer and then print X is sleeping;
Eat = lock the right fork lock fork with pthread_mutex_lock write "X has taken
a fork, repeat for left fork, then eat_timer then print X is eating then drop
the forks."
*/
int	main(int argc, char **argv)
{
	t_args			*args;
	t_philo_room	*room;
	pthread_mutex_t	*forks;
	int				flag;

	forks = NULL;
	flag = 0;
	if (argc < 5 || argc > 6)
		return (ft_error_argc());
	else
	{
		args = init_t_args();
		if (!args)
			return (-1);
		if (ft_parser(argc, argv, args))
			return (ft_freed_from_desire(NULL, args, NULL, NULL));
	}	
	room = ft_init(&forks, args);
	if (!room)
		return (-1);
	flag = ft_do_the_thread_thing(room, forks, args);
	if (flag)
		return (flag);
	ft_freed_from_desire(NULL, args, room, forks);
	return (flag);
}
