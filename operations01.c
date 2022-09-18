/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:46:00 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/18 15:06:01 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, SWAP);
	printf("s%c\n", stack);
}

void	ss(t_dlist **a, t_dlist **b)
{
	if ((*a)->value == NULL || (*a)->next->value == NULL)
		return ;
	swap_rotate(a, SWAP);
	if ((*b)->value == NULL || (*b)->next->value == NULL)
		return ;
	swap_rotate(b, SWAP);
	printf("ss\n");
}

void	pa_pb(t_dlist **dst, t_dlist **src, char stack)
{
	if ((*src)->value == NULL)
		return ;
	(*src)->prev->next = (*src)->next;
	(*src)->next->prev = (*src)->prev;
	(*dst)->prev->next = *src;
	(*src)->prev = (*dst)->prev;
	(*dst)->prev = *src;
	*src = (*src)->next;
	(*dst)->prev->next = *dst;
	*dst = (*dst)->prev;
	printf("p%c\n", stack);
}
