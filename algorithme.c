/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:14:09 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/10 14:17:02 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	solution(int len, t_dlist **a, t_dlist **b)
{
	int	limit;
	int	label;

	if (is_sorted(a) == SUCCESS)
		return ;
	if (len <= 6)
		sort_up_to_six(len, a, b);
	else
	{
		limit = send_half_small(len, b, a);
		label = 0;
		while (label != SORTED)
		{
			find_three(limit, a, b);
			label = (*a)->label;
			limit = 0;
			while (label != SORTED && label == (*a)->label)
			{
				pa_pb(b, a);
				ft_printf("pb\n");
				limit++;
			}
		}
	}
}

void	find_three(int len, t_dlist **a, t_dlist **b)
{
	int	j;

	j = 0;
	if (len <= 3)
	{
		sort_three(b, 'b');
		while (j < len)
		{
			pa_pb(a, b);
			ft_printf("pa\n");
			ra_rb(a);
			ft_printf("ra\n");
			j++;
		}
		return ;
	}

	len = send_half_large(len, a, b);
	find_three(len, a, b);
}

int	send_half_large(int len, t_dlist **dst, t_dlist **src)
{
	int	i;
	int	median;
	int	first_index;

	if ((*dst)->prev->prev->label == 0)
		first_index = 0;
	else if ((*dst)->prev->prev->label == -1)
		first_index = (*dst)->prev->prev->index + 1;
	median = (len % 2) + (len / 2);
	i = 0;
	while ((median + i) < len)
	{
		if ((*src)->index >= (median + first_index))
		{
			if (3 < median)
				(*src)->label++;
			pa_pb(dst, src);
			ft_printf("pa\n");
			i++;
		}
		else
		{
			ra_rb(src);
			ft_printf("rb\n");
		}
	}
	return (median);
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
			(*src)->label = 1;
			pa_pb(dst, src);
			ft_printf("pb\n");
			i++;
		}
		else
		{
			ra_rb(src);
			ft_printf("ra\n");
		}
	}
	return (median);
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


int	is_sorted(t_dlist **lst)
{
	t_dlist	*head;

	head = *lst;

	while ((*lst)->next->value != NULL)
	{
		if (((*lst)->index + 1  !=  (*lst)->next->index))
		{
			*lst = head;
			return (FAIL);
		}
		*lst = (*lst)->next;
	}
	*lst = head;
	return (SUCCESS);
}
