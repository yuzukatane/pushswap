/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:26:39 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/18 15:28:26 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_up_to_six(int len, t_dlist **a, t_dlist **b)
{
	int	i;

	if (len <= 3)
		sort_three(a, 'a');
	else
	{
		send_half_small(len, b, a);
		sort_three(a, 'a');
		sort_three_reverse(b, 'b');
		i = 0;
		while (i < ((len / 2) + (len % 2)))
		{
			pa_pb(a, b, 'a');
			i++;
		}
	}
}

int	is_sorted(t_dlist **lst)
{
	t_dlist	*head;

	head = *lst;
	while ((*lst)->next->value != NULL)
	{
		if (((*lst)->index + 1 != (*lst)->next->index))
		{
			*lst = head;
			return (FAIL);
		}
		*lst = (*lst)->next;
	}
	*lst = head;
	return (SUCCESS);
}

int	send_half_small(int len, t_dlist **dst, t_dlist **src)
{
	int	median;
	int	i;

	median = (len % 2) + (len / 2);
	i = 0;
	while (i < median)
	{
		if ((*src)->index < median)
		{
			pa_pb(dst, src, 'b');
			i++;
		}
		else
			ra_rb(src, 'a');
	}
	return (median);
}
