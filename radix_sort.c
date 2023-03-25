/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:59:32 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:59:33 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *main, t_stack *temp)
{
	int	pow;
	int	j;
	int	*a;

	a = main->stack;
	pow = 0;
	while (pow < main->max_bits)
	{
		j = 0;
		if (is_already_sorted(main))
			break ;
		while (j < main->max_len)
		{
			if (a[main->top] & (1 << pow))
				rotate(main, 1);
			else
				push(temp, main, 0);
			j++;
		}
		while (temp->top >= 0)
			push(main, temp, 1);
		pow++;
	}
}
