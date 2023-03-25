/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:59:01 by msumset           #+#    #+#             */
/*   Updated: 2023/03/25 16:59:02 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack{
	int	*stack;
	int	max_len;
	int	top;
	int	max_bits;

}	t_stack;

void	error(char *msg);
void	free_dptr(char **ptr);
void	check_arguements(int ac, char **av);
t_stack	*init_main_stack(int ac, char **av);
t_stack	*init_temp_stack(t_stack *main);
int		check_duplicate(t_stack *stack);
int		is_already_sorted(t_stack *stack);
void	push(t_stack *alan, t_stack *gonderen, int is_pa);
void	rotate(t_stack *stack, int is_ra);
void	swap(t_stack *stack, int is_a);
void	reverse_rotate(t_stack *stack, int is_a);
void	radix_sort(t_stack *main, t_stack *temp);
void	ft_sort_three(t_stack *main, t_stack *temp);
int		find_smallest(t_stack *main);
void	ft_sort_five(t_stack *main, t_stack *temp);
void	ft_sort_four(t_stack *main, t_stack *temp);
void	free_all(t_stack *main, t_stack *temp);

#endif