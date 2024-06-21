/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:15:44 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/18 15:16:21 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "typedef.h"

/*alloc*/
void	*alloc(int size, void *ptr, int type);
void	*walloc(int size);
void	wfree(void *ptr);
void	wclear(void);

/*list*/
t_list	*create_node(void *data);
void 	lst_addback(t_list *parent, t_list *new);
int		lst_del_one(t_list **head, t_list *to_del);
void	clear_alloc(t_list **head);

/*utils*/
int	ft_strlen(char *s);
int	ft_atoi_overflow(const char *str, int *error);

/*error*/
void ft_error_argc(void);
void	ft_eq(char *msg);

/*parser*/
t_args	*init_t_args(void);
void	ft_parser(int argc, char **argv, t_args *args);

#endif