/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:23:28 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/17 15:44:03 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_error_argc(void)
{
	char	*s;

	s = "invalid number of arguments\n";
	write(2, s, ft_strlen(s));
}

void	ft_eq(char *msg)
{
	write(2, "error:", 6);
	write(2, msg, ft_strlen(msg));
}