/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:57:57 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:57:59 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_len(int ac, char **av)
{
	char	**split;
	int		len;
	int		i;
	int		j;

	i = 1;
	len = 0;
	while (i < ac)
	{
		j = -1;
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		while (split[++j])
			len++;
		free_dptr(split);
		i++;
	}
	return (len);
}

int	fill_stack(int ac, char **av, t_stack *stack)
{
	char	**split;
	int		i;
	int		j;
	int		top;

	i = 1;
	top = stack->top;
	while (i < ac)
	{
		j = -1;
		split = ft_split(av[i], ' ');
		if (!split)
		{
			free(stack->stack);
			free(stack);
			error("Error\n");
		}		
		while (split[++j])
			stack->stack[top--] = ft_atoll(split[j]);
		free_dptr(split);
		i++;
	}
	return (0);
}

int	create_stack(int ac, char **av, t_stack *stack)
{
	int		*arr;
	int		len;

	len = count_stack_len(ac, av);
	if (len < 2)
		exit(EXIT_FAILURE);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
	{
		free(stack);
		error("Error\n");
	}
	stack->max_len = len;
	stack->top = len - 1;
	stack->stack = arr;
	fill_stack(ac, av, stack);
	return (0);
}

t_stack	*init_temp_stack(t_stack *main)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
	{
		free(main->stack);
		free(main);
		error("Error\n");
	}
	temp->max_len = main->max_len;
	temp->stack = (int *)malloc(sizeof(int) * temp->max_len);
	if (!temp->stack)
	{
		free(main->stack);
		free(main);
		free(temp);
		error("Error\n");
	}
	ft_bzero(temp->stack, sizeof(int) * temp->max_len);
	temp->top = -1;
	return (temp);
}

t_stack	*init_main_stack(int ac, char **av)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error("Error\n");
	create_stack(ac, av, stack);
	if (check_duplicate(stack) == -1)
		error("Error\n");
	if (is_already_sorted(stack))
	{
		free(stack->stack);
		free(stack);
		exit(EXIT_SUCCESS);
	}
	return (stack);
}
