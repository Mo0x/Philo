/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:23:28 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/03 15:50:06 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error_argc(void)
{
	char	*s;

	s = "invalid number of arguments\n";
	write(2, s, ft_strlen(s));
	return (-1);
}

int	ft_eq(char *msg)
{
	write(2, "Error:", 6);
	write(2, msg, ft_strlen(msg));
	return (-1);
}
