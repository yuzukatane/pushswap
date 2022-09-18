/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:14:09 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/18 14:50:09 by kyuzu            ###   ########.fr       */
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
			rotate_to_sort(a);
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

void	rotate_to_sort(t_dlist **a)
{
	while (1)
	{
		while ((*a)->index == ((*a)->prev->prev->index + 1))
		{
			(*a)->label = SORTED;
			ra_rb(a);
			ft_printf("ra\n");
		}
		if ((*a)->next->index == ((*a)->prev->prev->index + 1)
			&& (*a)->index == ((*a)->next->index + 1))
		{
			sa_sb(a);
			ft_printf("sa\n");
		}
		else
			break ;
	}
}

void	find_three(int len, t_dlist **a, t_dlist **b)
{
	int	j;
	int	label;

	if (len <= 3)
	{
		sort_three(b, 'b');
		j = -1;
		while (++j < len)
		{
			pa_pb(a, b);
			ft_printf("pa\n");
			ra_rb(a);
			ft_printf("ra\n");
		}
		return ;
	}
	label = (*a)->label + 1;
	while ((*b)->value != NULL)
	{
		(*b)->label = label;
		*b = (*b)->next;
	}
	*b = (*b)->next;
	len = send_half_large(len, a, b);
	find_three(len, a, b);
}

int	send_half_large(int len, t_dlist **dst, t_dlist **src)
{
	int	i;
	int	median;

	median = (len % 2) + (len / 2);
	is_larger(len, median, dst, src);
	i = 0;
	if ((median / 2) > 1)
	{
		while (i < (median / 2))
		{
			rra_rrb(dst);
			ft_printf("rra\n");
			i++;
		}
	}
	return (median);
}

void	is_larger(int len, int median, t_dlist **dst, t_dlist**src)
{
	int	i;
	int	first_index;

	if ((*dst)->prev->prev->label == 0)
		first_index = 0;
	else
		first_index = (*dst)->prev->prev->index + 1;
	i = 0;
	while ((median + i) < len)
	{
		if ((*src)->index >= (median + first_index))
		{
			pa_pb(dst, src);
			ft_printf("pa\n");
			if ((median / 2) > 1)
				small_or_large(((median / 2) + first_index + median), dst);
			i++;
		}
		else
		{
			ra_rb(src);
			ft_printf("rb\n");
		}
	}
}

void	small_or_large(int median, t_dlist **lst)
{
	if ((*lst)->index < median)
	{
		(*lst)->label++;
		ra_rb(lst);
		ft_printf("ra\n");
	}
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
/*
int	send_half_small(int len, t_dlist **dst, t_dlist **src)
{
	int	median;
	int	i;
	int	flag;

	median = (len % 2) + (len / 2);
	i = 0;
	while (i < median)
	{
		if ((*src)->index < median)
		{
			pa_pb(dst, src);
			ft_printf("pb\n");
			i++;
		}
		else
		{
			flag = top_or_bottom(src, median);
			//無限ループになってる！下の行、関数書くまえはifではなくelse で書いてた
			if (flag == TOP)
			{
				while ((*src)->index >= median)
				{
					ra_rb(src);
					ft_printf("ra\n");
				}
			}
			else if (flag == BOTTOM)
			{
				while ((*src)->index >= median)
				{
					rra_rrb(src);
					ft_printf("rra\n");
				}
			}
		}
	}
	return (median);
}

int	top_or_bottom(t_dlist **lst, int median)
{
	t_dlist *top;
	t_dlist *bottom;
	int		index_top;
	int		index_bottom;

	top = *lst;
	bottom = (*lst)->prev->prev;
	index_top = 0;
	index_bottom = 0;
	while (top->index >= median)
	{
		top = top->next;
		index_top++;
	}
	while (bottom->index >= median)
	{
		bottom = bottom->next;
		index_bottom++;
	}
	if (top->index < bottom->index)
		return (TOP);
	return (BOTTOM);
}
*/

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
