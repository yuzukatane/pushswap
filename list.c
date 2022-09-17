/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:21:21 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/17 17:38:08 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		last = dlstempty();
		*lst = new;
		(*lst)->next = last;
		(*lst)->prev = last;
		last->next = *lst;
		last->prev = *lst;
	}
	else
	{
		(*lst)->prev->prev->next = new;
		new->prev = (*lst)->prev->prev;
		(*lst)->prev->prev = new;
		new->next = (*lst)->prev;
	}
}

void	dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->prev = *lst;
		(*lst)->next = new;
		(*lst)->prev = new;
		
		*lst = new;
	}
}

t_dlist	*dlstnew(int value)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->value = malloc(sizeof(int));
	if (new->value == NULL)
		return (NULL);
	*(new->value) = value;
	new->next = new;
	new->prev = new;
	new->index = -1;
	new->label = 0;
	return (new);
}

t_dlist	*dlstempty(void)
{
	t_dlist	*empty;

	empty = malloc(sizeof(t_dlist));
	if (empty == NULL)
		return (NULL);
	
	empty->value = NULL;
	empty->next = empty;
	empty->prev = empty;
	empty->index = -1;
	empty->label = -1;
	return (empty);
}

void	dlstclear(t_dlist **lst)
{
	t_dlist	*tmp;

	while ((*lst)->value != NULL)
	{
		tmp = (*lst)->next;
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
}




// int	send_half_large(int len, t_dlist **dst, t_dlist **src)
// {
// 	int	i;
// 	int	median;
// 	int	first_index;

// 	if ((*dst)->prev->prev->label == 0)
// 		first_index = 0;
// 	else if ((*dst)->prev->prev->label == -1)
// 		first_index = (*dst)->prev->prev->index + 1;
// 	median = (len % 2) + (len / 2);
// 	i = 0;
// 	while ((median + i) < len)
// 	{
// 		if ((*src)->index >= (median + first_index))
// 		{
// 			pa_pb(dst, src);
// 			ft_printf("pa\n");
// 			small_or_large(((median / 2) + first_index + median), dst);
// 			i++;
// 		}
// 		else
// 		{
// 			ra_rb(src);
// 			ft_printf("rb\n");
// 		}
// 	}
// 	i = 0;
// 	if (2 < (median / 2))
// 		while (i < (median / 2))
// 		{
// 			rra_rrb(dst);
// 			ft_printf("rra\n");
// 			i++;
// 		}
// 	return (median);
// }

// void	small_or_large(int median, t_dlist **lst)
// {
// 	if (median < 3)
// 		return ;
// 	if ((*lst)->index < median)
// 	{
// 		(*lst)->label++;
// 		ra_rb(lst);
// 		ft_printf("ra\n");
// 	}
// }