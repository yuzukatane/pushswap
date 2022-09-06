/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:46:00 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/06 10:43:35 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_dlist **lst)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	swap_rotate(lst, SWAP);
}

void	ss(t_dlist **a, t_dlist **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	pa_pb(t_dlist **dest, t_dlist **src)
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
