/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:34:05 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/03 19:14:44 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		last = dlstnew(0);
		last->value = NULL;
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
	return (new);
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
