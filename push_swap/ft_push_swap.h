/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:15:30 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/11 23:36:22 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_struct
{
	int		*stacka;
	int		stacka_size;
	char	*temp_a;
	int		*stackb;
	int		stackb_size;
	char	*temp_b;
	int		lpivot;
	int		rpivot;
	int		*tab;
	int		origsize;
}		t_struct;

//func in main -- used for stack
void	ft_split(char *str, int *array);
int		ft_atoi(char *str, int *stack);
void	ft_errorfound(int *stack);

//func in validate -- used for stack & args
int		ft_check_args(char **av, int ac, t_struct *s);
int		ft_check_stack(int size, char todo, t_struct *s);

//func in decision maker -- used to check stack & todo stuff with stack
void	ft_decide_next(t_struct *s);

//func in operations -- operation for the algo basically
void	ft_r_rotate_a(char *str, t_struct *s);
void	ft_r_rotate_b(char *str, t_struct *s);
void	ft_swap(char *str, int *stack, t_struct *s);
void	ft_push_b(char *str, t_struct *s);
void	ft_push_a(char *str, t_struct *s);

void	ft_astuff(t_struct *s);
void	ft_printcomb(t_struct *s);
void	ft_bstuff(t_struct *s);

//algo for 25 and lower
void	ft_algofor5(t_struct *s);
void	ft_algo_formid(t_struct *s);
void	ft_algo_forbig(t_struct *s);

void	ft_putback500(t_struct *s);
int		ft_islower500(t_struct *s, int call);
void	ft_big_algo(t_struct *s, int call);

//in other file
void	ft_strcpy(char *src, char *dst);
#endif
