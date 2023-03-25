/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:00:04 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 17:00:05 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *main, t_stack *temp)
{
	int	*s;

	(void)temp;
	s = main->stack;
	if (s[2] > s[1] && s[2] > s[0])
	{
		rotate(main, 1);
		if (s[2] > s[1])
			swap(main, 1);
	}
	else if (s[2] < s[1] && s[2] < s[0] && s[1] > s[0])
	{
		reverse_rotate(main, 1);
		swap(main, 1);
	}
	else if (s[2] < s[1] && s[2] > s[0] && s[1] > s[0])
		reverse_rotate(main, 1);
	else if (s[2] > s[1] && s[2] < s[0] && s[1] < s[0])
		swap(main, 1);
}
