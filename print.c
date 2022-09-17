/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuzu <kyuzu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:24:12 by kyuzu             #+#    #+#             */
/*   Updated: 2022/09/17 17:33:02 by kyuzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Makefine載ってないよ

void	check_and_print(t_buf *buffer, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (buffer->index + len >= 1024)
	{
		while (buffer->index < 1024)
		{
			buffer->array[buffer->index] = '\0';
			buffer->index++;
		}
		
	}
	while (str[i] != '\0')
	{
		buffer->array[buffer->index] = str[i];
		i++;
		buffer->index++;
	}
}

void	check_buf(t_buf *buffer)
{
	int	i;
	char *to_find = "\nra\nrra";

	i = 0;
	ft_strnstr(buffer->array, to_find, 1024);
}
