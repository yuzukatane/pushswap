/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:14:09 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/08 12:43:11 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


////////////////////////////
//2,3,5の時、初めから揃ってる時
////////////////////////////


void	solution(int len, t_dlist **a, t_dlist **b)
{
	int	limit;
	int	label;

	if (len <= 6)
	{
		sort_up_to_six(len, a, b);
	}
	else
	{
		limit = send_half_small(len, b, a);
		label = 0;
		while (label != SORTED)
		{
			find_three(limit, a, b);
			
			// printf("a: \n");
			// printlst(a, 1);
			// printf("\n");
			// printf("b: \n");
			// printlst(b, 1);
			// printf("\n");
			label = (*a)->label;
			limit = 0;
			// printf("label = %d\n", label);
			while (label != SORTED && label == (*a)->label)
			{
				pa_pb(b, a);
				limit++;
			}
			// printf("a: \n");
			// printlst(a, 1);
			// printf("\n");
			// printf("b: \n");
			// printlst(b, 1);
			// printf("\n");
		}
	}
}

void	find_three(int len, t_dlist **a, t_dlist **b)
{
	int	j;

	j = 0;
	if (len <= 3)
	{
		sort_three(b);
		while (j < len)
		{
			pa_pb(a, b);
			ra_rb(a);
			j++;
		}
		return ;
	}

	len = send_half_large(len, a, b);

	// printf("a: \n");
	// printlst(a, 1);
	// printf("\n");
	// printf("b: \n");
	// printlst(b, 1);
	// printf("\n");
	
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
			i++;
		}
		else
			ra_rb(src);
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
			i++;
		}
		else
			ra_rb(src);
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

void	sort_three(t_dlist **lst)
{
	if ((*lst)->next->next->value == NULL)
		sort_two(lst);
	else if (*((*lst)->next->value) < *((*lst)->value) && *((*lst)->value) < *((*lst)->next->next->value))
		sa_sb(lst);
	else if (*((*lst)->next->next->value) < *((*lst)->next->value) && *((*lst)->next->value) < *((*lst)->value))
	{
		sa_sb(lst);
		rra_rrb(lst);
	}
	else if (*((*lst)->next->value) < *((*lst)->next->next->value) && *((*lst)->next->next->value) < *((*lst)->value))
		ra_rb(lst);
	else if (*((*lst)->value) < *((*lst)->next->next->value) && *((*lst)->next->next->value) < *((*lst)->next->value))
	{
		sa_sb(lst);
		ra_rb(lst);
	}
	else if (*((*lst)->next->next->value) < *((*lst)->value) && *((*lst)->value) < *((*lst)->next->value))
		rra_rrb(lst);
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
	(*lst)->next->next->label = SORTED;
}

void	sort_two(t_dlist **lst)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	//いらない？	
	else if (*((*lst)->value) > *((*lst)->next->value))
		sa_sb(lst);
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
}

void	sort_three_reverse(t_dlist **lst)
{
	if ((*lst)->next->next->value == NULL)
		sort_two_reverse(lst);
	else if (*((*lst)->next->value) > *((*lst)->value) && *((*lst)->value) > *((*lst)->next->next->value))
		sa_sb(lst);
	else if (*((*lst)->next->next->value) > *((*lst)->next->value) && *((*lst)->next->value) > *((*lst)->value))
	{
		sa_sb(lst);
		rra_rrb(lst);
	}
	else if (*((*lst)->next->value) > *((*lst)->next->next->value) && *((*lst)->next->next->value) > *((*lst)->value))
		ra_rb(lst);
	else if (*((*lst)->value) > *((*lst)->next->next->value) && *((*lst)->next->next->value) > *((*lst)->next->value))
	{
		sa_sb(lst);
		ra_rb(lst);
	}
	else if (*((*lst)->next->next->value) > *((*lst)->value) && *((*lst)->value) > *((*lst)->next->value))
		rra_rrb(lst);
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
	(*lst)->next->next->label = SORTED;
}

void	sort_two_reverse(t_dlist **lst)
{
	if ((*lst)->value == NULL || (*lst)->next->value == NULL)
		return ;
	//いらない？	
	else if (*((*lst)->value) < *((*lst)->next->value))
		sa_sb(lst);
	(*lst)->label = SORTED;
	(*lst)->next->label = SORTED;
}

void	sort_up_to_six(int len, t_dlist **a, t_dlist **b)
{
	int	i;

	if (len <= 3)
		sort_three(a);
	else
	{

		send_half_small(len, b, a);
		sort_three(a);
		sort_three_reverse(b);
		
		i = 0;
		while (i < ((len / 2) + (len % 2)))
		{
			pa_pb(a, b);
			i++;
		}

	}
}
