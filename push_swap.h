/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoo <jwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:49:57 by jwoo              #+#    #+#             */
/*   Updated: 2021/05/30 19:00:35 by jwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define SA	0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct	s_stack
{
	int	*a;
	int	*b;
}				t_stack;

void			arr_swap(int *arr, int root, int idx);
void			heapify(int *arr, int num);
void			insert_heap(int *sort, int idx);
void			heap_sort(int *arr, int num);
int				atoi_sign(char *str);
int				ft_atoi(char *str, int *integer);
int				ft_strlen(char *str);
void			ft_memset(int *arr, int c, int len);
int				is_space(char s);
int				factor_num(char *s);
char			**factor_len(char **factor, char *s, int factor_num);
void			factor_split(char **factor, char *s, int factor_num);
char			**ft_split_space(char *s);
void			error_message(char *message);
int				argument_number(int argc, char *argv[]);
void			is_sort(int arg_num, int *stack_a, int *sort);
char			**free_two_dimension(char **word, int num);
void			free_stack(t_stack *stack, int *sort);
int				sa_sb(int *stack);
int				ss(int *stack_a, int *stack_b);
int				pa(int *stack_a, int *stack_b);
int				pb(int *stack_a, int *stack_b);
int				ra_rb(int *stack);
int				rr(int *stack_a, int *stack_b);
int				rra_rrb(int *stack);
int				rrr(int *stack_a, int *stack_b);
void			write_command(int command);
int				is_vaild_operate(t_stack *stack, int command);
void			operate(t_stack *stack, int command);
t_stack			*init_stack_struct(void);
int				*init_stack_a(int argc, char *argv[], int arg_num);
int				*init_sort(int arg_num, int *stack_a);
int				*init_stack_b(int arg_num);
void			sort_two_arg_in_a(t_stack *stack);
void			sort_three_arg_in_a(t_stack *stack);
void			sort_four_arg_in_a(t_stack *stack, int *sort);
void			sort_five_arg_in_a(t_stack *stack, int *sort);
int				find_idx(int *stack, int range, int *sort, int sort_idx);
int				find_idx_reverse(int *stack, int range, int *sort,
				int sort_idx);
int				rotate_b(t_stack *stack, int *sort, int max_idx, int sort_idx);
int				reverse_rotate_b(t_stack *stack, int *sort, int max_idx,
				int sort_idx);
void			slice_three_part(t_stack *stack, int *sort, int start, int end);
void			sort_remain_stack_b(t_stack *stack, int *sort, int sort_idx);
void			sort_remain_stack_a(t_stack *stack, int *sort);
void			push_swap(t_stack *stack, int *sort);

#endif
