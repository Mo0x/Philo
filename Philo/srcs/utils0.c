/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:24:56 by mgovinda          #+#    #+#             */
/*   Updated: 2024/07/02 17:14:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <limits.h>

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (2048);
}

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (*s++)
		ret++;
	return (ret);
}

static int	ft_overflow(int neg, unsigned long long num, int *error)
{
	if ((neg == 1 && num > LONG_MAX) || (neg == -1 && num > \
			-(unsigned int)LONG_MIN))
		*error = 1;
	return (*error);
}

int	ft_atoi_overflow(const char *str, int *error)
{
	unsigned long long	num;
	int					neg;
	int					i;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (ft_overflow(neg, num, error))
			break ;
		i++;
	}
	return (num * neg);
}

size_t	give_me_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday error\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
