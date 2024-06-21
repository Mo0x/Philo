/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:28:23 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/17 15:18:20 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	ALLOC_SIZE 1024

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

typedef struct s_args
{
	int	n_philo;
	int	death_timer;
	int	eat_timer;
	int	sleep_timer;
	int	minimum_eat;
}	t_args;