/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:14:09 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/06 20:59:27 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution(int len, t_dlist **a, t_dlist **b)
{
	send_half(len, a, b);
}



void	send_half(int len, t_dlist **src, t_dlist **dst)
{
	int	median;
	int	nb;

	median = (len % 2) + (len / 2);
	nb = 0;
	while (nb < median)
	{
		if ((*src)->index < median)
		{
			pa_pb(dst, src);
			nb++;
		}
		else
			ra_rb(src);
	}
}

// void	solution(int len, t_dlist **a, t_dlist **b)
// {
// 	int	median;
// 	int	nb;
// 	int counter = 0;
// 	t_dlist *first;
// 	t_dlist *second;
// 	int		index_first;
// 	int		index_second;
// 	median = (len % 2) + (len / 2);
// 	nb = 0;
// 	while (nb < median)
// 	{
// 		first = *a;
// 		second = (*a)->prev->prev;
// 		index_first = 0;
// 		index_second = 0;
// 		while (first->index >= median)
// 		{
// 			first = first->next;
// 			index_first++;
// 		}
// 		while (second->index >= median)
// 		{
// 			second = second->next;
// 			index_second++;
// 		}
// 		if (index_first <= index_second)
// 		{
// 			while ((*a)->index >= median)
// 			{
// 				ra_rb(a);
// 				counter++;
// 			}
// 			pa_pb(b, a);
// 			nb++;
// 		}
// 		else
// 		{
// 			while ((*a)->index >= median)
// 			{
// 				rra_rrb(a);
// 				counter++;
// 			}
// 			pa_pb(b, a);
// 			nb++;
// 		}
// 	}
// 	printf("counter = %d\n", counter);
// }
