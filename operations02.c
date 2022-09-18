/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:47:52 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/18 15:04:11 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, ROTATE);
	printf("r%c\n", stack);
}

void	rr(t_dlist **a, t_dlist **b)
{
	if ((*a)->value == NULL || (*a)->next->value == NULL)
		return ;
	swap_rotate(a, ROTATE);
	if ((*b)->value == NULL || (*b)->next->value == NULL)
		return ;
	swap_rotate(b, ROTATE);
	printf("rr\n");
}

void	rra_rrb(t_dlist **lst, char stack)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, REVERSE_ROTATE);
	printf("rr%c\n", stack);
}

void	rrr(t_dlist **a, t_dlist **b)
{
	if ((*a)->value == NULL || (*a)->next->value == NULL)
		return ;
	swap_rotate(a, REVERSE_ROTATE);
	if ((*b)->value == NULL || (*b)->next->value == NULL)
		return ;
	swap_rotate(b, REVERSE_ROTATE);
	printf("rrr\n");
}

void	swap_rotate(t_dlist **lst, int flag)
{
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
