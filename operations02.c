/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:47:52 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/06 10:43:11 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_dlist **lst)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, ROTATE);
}

void	rr(t_dlist **a, t_dlist **b)
{
	ra_rb(a);
	ra_rb(b);
}

void	rra_rrb(t_dlist **lst)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, REVERSE_ROTATE);
}

void	rrr(t_dlist **a, t_dlist **b)
{
	rra_rrb(a);
	rra_rrb(b);
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
