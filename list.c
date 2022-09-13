/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:21 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/13 11:36:53 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		last = dlstempty();
		*lst = new;
		(*lst)->next = last;
		(*lst)->prev = last;
		last->next = *lst;
		last->prev = *lst;
	}
	else
	{
		(*lst)->prev->prev->next = new;
		new->prev = (*lst)->prev->prev;
		(*lst)->prev->prev = new;
		new->next = (*lst)->prev;
	}
}

void	dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->prev = *lst;
		(*lst)->next = new;
		(*lst)->prev = new;
		
		*lst = new;
	}
}


t_dlist	*dlstnew(int value)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->value = malloc(sizeof(int));
	if (new->value == NULL)
		return (NULL);
	*(new->value) = value;
	new->next = new;
	new->prev = new;
	new->index = -1;
	new->label = 0;
	return (new);
}

t_dlist	*dlstempty(void)
{
	t_dlist	*empty;

	empty = malloc(sizeof(t_dlist));
	if (empty == NULL)
		return (NULL);
	
	empty->value = NULL;
	empty->next = empty;
	empty->prev = empty;
	empty->index = -1;
	empty->label = -1;
	return (empty);
}

void	dlstclear(t_dlist **lst)
{
	t_dlist	*tmp;

	while ((*lst)->value != NULL)
	{
		tmp = (*lst)->next;
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
}
