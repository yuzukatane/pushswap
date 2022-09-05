/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:49:43 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/05 22:49:13 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_dlist **dest, t_dlist **src)
{
	if ((*src)->value == NULL)
		return ;
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	(*dest)->prev->next = *src;
	(*src)->prev = (*dest)->prev;
	(*dest)->prev = *src;
	*src = (*src)->next;
	(*dest)->prev->next = *dest;
	*dest = (*dest)->prev;
}

void	swap_rotate(t_dlist **lst, int flag)
{
	t_dlist	*head;
	t_dlist	*tail;
	t_dlist	*tmp;

	if (flag == ROTATE)
		*lst = (*lst)->prev;
	else if (flag == REVERSE_ROTATE)
		*lst = (*lst)->prev->prev;
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->prev = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->prev->next = *lst;
	(*lst)->next->prev = *lst;
	if ((*lst)->value == NULL)
		(*lst) = (*lst)->next;
	if (flag == SWAP)
		*lst = (*lst)->prev;
}