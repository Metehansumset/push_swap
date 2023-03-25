/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:57:03 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:57:10 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_split(char **split)
{
	int		i;
	int		j;
	char	*str;

	if (!split[0])
		error("Error\n");
	i = 0;
	while (split[i])
	{
		str = split[i];
		j = 0;
		if (str[j] == '+' || str[j] == '-')
			j++;
		if (!str[j])
			error("Error\n");
		while (str[j])
		{
			if (!ft_isdigit(str[j]))
				error("Error\n");
			j++;
		}
		i++;
	}
}

int	check_numbers(char **split)
{
	int			i;
	long long	num;

	i = 0;
	while (split[i])
	{
		num = ft_atoll(split[i]);
		if (num > INT_MAX || num < INT_MIN)
			error("Error\n");
		i++;
	}
	return (0);
}

int	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;
	int	*arr;

	arr = stack->stack;
	i = 0;
	while (i < stack->max_len)
	{
		j = i;
		while (++j < stack->max_len)
		{
			if (arr[i] == arr[j])
			{
				free(stack->stack);
				free(stack);
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int	is_already_sorted(t_stack *stack)
{
	int	*arr;
	int	top;

	top = stack->top;
	arr = stack->stack;
	while (top > 0)
	{
		if (arr[top] > arr[top - 1])
			return (0);
		top--;
	}
	return (1);
}

void	check_arguements(int ac, char **av)
{
	int		i;
	char	**split;

	if (ac == 1)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		check_split(split);
		check_numbers(split);
		free_dptr(split);
		i++;
	}
}
