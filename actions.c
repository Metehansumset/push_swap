/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:56:42 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:56:44 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int is_a)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = tmp;
	if (is_a)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	reverse_rotate(t_stack *stack, int is_a)
{
	int	i;
	int	*arr;
	int	tmp;

	arr = stack->stack;
	i = 0;
	while (i < stack->top)
	{	
		tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
		i++;
	}
	if (!is_a)
		ft_putstr_fd("rrb\n", 1);
	else
		ft_putstr_fd("rra\n", 1);
}

void	push(t_stack *alan, t_stack *gonderen, int is_pa)
{
	int	*arr;

	alan->stack[++alan->top] = gonderen->stack[gonderen->top--];
	arr = gonderen->stack;
	ft_bzero(arr + gonderen->top + 1, (sizeof(int)));
	if (!is_pa)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
}

void	rotate(t_stack *stack, int is_ra)
{
	int	top;
	int	*arr;
	int	tmp;

	arr = stack->stack;
	top = stack->top;
	while (top > 0)
	{	
		tmp = arr[top];
		arr[top] = arr[top -1];
		arr[top - 1] = tmp;
		top--;
	}
	if (!is_ra)
		ft_putstr_fd("rb\n", 1);
	else
		ft_putstr_fd("ra\n", 1);
}
