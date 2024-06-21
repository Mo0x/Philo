/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:51:05 by mgovinda          #+#    #+#             */
/*   Updated: 2024/06/18 15:19:00 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_list	*create_node(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void lst_addback(t_list *parent, t_list *new)
{
	if (!parent)
		return ;
	else
	{
		while(parent->next)
			parent = parent->next;
		parent->next = new;
	}
}

static void	init_variables(t_list **tmp, \
					t_list **prev, \
					t_list **next, \
					t_list **head)
{
	*tmp = *head;
	*next = NULL;
	*prev = NULL;
}

int	lst_del_one(t_list **head, t_list *to_del)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	init_variables(&tmp, &prev, &next, head);
	while (tmp)
	{
		if (tmp->next == to_del)
			prev = tmp;
		if (tmp == to_del)
		{
			if (tmp->next)
				next = tmp->next;
			free(to_del);
			if (prev)
				prev->next = next;
			else
				*head = next;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	clear_alloc(t_list **head)
{
	t_list	*tmp;
	int		i = 0;

	printf("head %p", head);
	while (head)
	{
		tmp = (*head)->next;
		free((*head)->data);
		free(*head);
		*head = tmp;
		printf("int i = %d", i);
		i++;
	}
}

