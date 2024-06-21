/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:13:57 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/18 14:57:29 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	args = init_t_args();
	printf("argc = %d\n", argc);
	if (argc < 5 || argc > 6)
	{
		ft_error_argc();
		return (-1);
	}
	else
		ft_parser(argc, argv, args);
	/* if (ft_create_thrilosophers(args) < 0)
		return (-1); */
	char *test = walloc(13);
	test = "test3000\n";
	printf("%s", test);
	wclear();
}
