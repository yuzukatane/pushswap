/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:49:43 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/05 15:29:29 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist **lst)
{
	//nullガードいる？
	//if -> sa sb でやってもいいかも
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->prev = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->prev->next = *lst;
	(*lst)->next->prev = *lst;
	*lst = (*lst)->prev;
}

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

void	swap_for_rotate(t_dlist **lst)
{
	t_dlist	*head;
	t_dlist	*tail;
	t_dlist	*tmp;


	head = (*lst)->next->next;
	tail = (*lst)->prev;
	tmp = *lst;
	(*lst)->prev = (*lst)->next;
	(*lst)->prev->next = *lst;
	(*lst)->prev->prev = tail;
	*lst = tmp;
	(*lst)->next = head;
	head->prev = *lst;
	tail->next = (*lst)->prev;
	
	if ((*lst)->value == NULL)
	{
		*lst = (*lst)->next;
	}
}

