/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:33:53 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/18 14:59:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*	type 1 = alloc
	type 2 = free
	type 3 = clear*/

void	*walloc(int size)
{
	return (alloc(size, NULL, 1));
}

void	wfree(void *ptr)
{
	alloc(0, ptr, 2);
}

void	wclear(void)
{
	alloc(0, NULL, 3);
}

void	*new_alloc(t_list **allocs, int size)
{
	t_list	*new;
	void	*newalloc;

	newalloc = malloc(size);
	if (!newalloc)
		return (NULL);
	new = create_node(newalloc);
	if (!new)
	{
		free(newalloc);
		return (NULL);
	}
	lst_addback(*allocs, new);
	return (newalloc);
}

void	*alloc(int size, void *ptr, int type)
{
	static t_list	*head;

	if (type == 1)
		return (new_alloc(&head, size));
	else if (type == 2)
		lst_del_one(&head, ptr);
	else if (type == 3)
		clear_alloc(head);
	return (NULL); 
}