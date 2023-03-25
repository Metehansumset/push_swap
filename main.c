/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:58:11 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:58:12 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_bits(t_stack *main)
{
	int	i;
	int	pow;
	int	max;
	int	*arr;

	i = 0;
	max = -1;
	arr = main->stack;
	while (i < main->max_len)
	{
		pow = 0;
		while (pow < 32)
		{
			if (arr[i] & (1 << pow) && pow > max)
				max = pow;
			pow++;
		}
		i++;
	}
	return (max + 1);
}

int	*sort_with_index(t_stack *main)
{
	int	*ret;
	int	i;
	int	j;
	int	count;
	int	*arr;

	ret = (int *)malloc(sizeof(int) * main->max_len);
	arr = main->stack;
	i = 0;
	j = 0;
	while (i < main->max_len)
	{
		count = 0;
		j = 0;
		while (j < main->max_len)
		{
			if (arr[i] > arr[j])
				count++;
			j++;
		}
		ret[i] = count;
		i++;
	}
	free(main->stack);
	return (ret);
}

void	treat_sort(t_stack *main, t_stack *temp)
{
	if (main->max_len == 2)
	{
		swap(main, 1);
		exit(EXIT_SUCCESS);
	}
	else if (main->max_len == 3)
		ft_sort_three(main, temp);
	else if (main->max_len == 4)
		ft_sort_four(main, temp);
	else if (main->max_len == 5)
		ft_sort_five(main, temp);
	else
		radix_sort(main, temp);
}

int	main(int ac, char **av)
{
	t_stack	*main;
	t_stack	*temp;

	check_arguements(ac, av);
	main = init_main_stack(ac, av);
	temp = init_temp_stack(main);
	main->stack = sort_with_index(main);
	main->max_bits = find_max_bits(main);
	treat_sort(main, temp);
	free_all(main, temp);
	return (0);
}
