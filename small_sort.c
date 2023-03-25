/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:59:49 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:59:50 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *main)
{
	int	top;
	int	min;

	top = main->top;
	min = main->stack[top];
	while (--top >= 0)
		if (main->stack[top] < min)
			min = main->stack[top];
	return (min);
}

int	find_smallest_index(t_stack *main)
{
	int	top;
	int	min;

	top = main->top;
	min = find_smallest(main);
	while (top >= 0)
	{
		if (main->stack[top] == min)
			return (top);
		top--;
	}
	return (-1);
}

void	push_smallest(t_stack *main, t_stack *temp)
{
	int	min;
	int	small;

	min = find_smallest_index(main);
	small = find_smallest(main);
	while (1)
	{
		if (main->stack[main->top] == small)
		{
			push(temp, main, 0);
			break ;
		}
		else if (min >= 2)
			rotate(main, 1);
		else if (min < 2)
			reverse_rotate(main, 1);
	}
}

void	ft_sort_four(t_stack *main, t_stack *temp)
{
	push_smallest(main, temp);
	ft_sort_three(main, temp);
	push(main, temp, 1);
}

void	ft_sort_five(t_stack *main, t_stack *temp)
{
	push_smallest(main, temp);
	push_smallest(main, temp);
	ft_sort_three(main, temp);
	push(main, temp, 1);
	push(main, temp, 1);
}
