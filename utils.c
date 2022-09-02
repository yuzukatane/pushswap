/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:34:05 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/02 23:12:19 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		last = ft_dlstnew(0);
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
		(*lst)->prev->prev = new;
		(*new).next = (*lst)->prev;
		(*new).prev = *lst;
	}
}

t_dlist	*ft_dlstnew(int value)
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
	return (new);
}
