/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:15 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/26 11:21:16 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_printcomb(t_struct *s)
{
	char	*s1;
	char	*s2;

	s1 = s->temp_a;
	s2 = s->temp_b;
	if (s1[0] && s2[0])
	{
		if (s1[0] && s2[0] == 's')
			printf("ss\n");
		if (s1[0] == 'r' && s2[0] == 'r'
			&& s1[1] != 'r' && s2[1] != 'r')
			printf("rr");
		if (s1[0] == 'r' && s2[0] == 'r'
			&& s1[1] == 'r' && s2[1] == 'r')
			printf("rrr");
		else
			printf("%s\n%s\n", s1, s2);
	}
	else if (s1[0])
		printf("%s\n", s1);
	else if (s2[0])
		printf("%s\n", s2);
}

void	ft_bstuff(t_struct *s)
{
	s->temp_b[0] = 0;
	if (s->stackb_size > 0)
	{
		if (s->stackb[0] < s->stackb[s->stackb_size])
			ft_r_rotate_b("rb", s);
		else if (s->stackb[s->stackb_size] > s->stackb[0])
			ft_r_rotate_b("rrb", s);
		else if (s->stackb[0] < s->stackb[1])
			ft_swap("sb", s->stackb, s);
		else if (s->stackb[s->stackb_size - 1] > s->stackb[0])
		{
			ft_r_rotate_b("rrb", s);
			printf("rrb\n");
			ft_swap("sb", s->stackb, s);
		}
	}
}

void	ft_astuff(t_struct *s)
{
	s->temp_a[0] = 0;
	if (ft_check_stack(s->stacka_size, 'o', s) == 1)
	{
		if (s->stacka[1] < s->stacka[0])
			ft_swap("sa", s->stacka, s);
		else if (s->stacka[s->stacka_size - 1] < s->stacka[0])
			ft_r_rotate_a("rra", s);
		else if (s->stacka[0] > s->stacka[s->stacka_size - 1])
			ft_r_rotate_a("ra", s);
		else if (s->stacka[s->stacka_size - 1] < s->stacka[1])
			ft_r_rotate_a("rra", s);
		else if (s->stacka[2] < s->stacka[1])
			ft_r_rotate_a("ra", s);
		else
			ft_push_b("pb", s);
		ft_bstuff(s);
		ft_printcomb(s);
		if (s->temp_a[0] || s->temp_b[0])
			ft_astuff(s);
	}
}

void	ft_algofor5(t_struct *s)
{
	if (ft_check_stack(s->stacka_size, 'o', s) == 1)
	{
		while (ft_check_stack(s->stacka_size, 'o', s) == 1)
		{
			ft_astuff(s);
		}
		while (s->stackb_size >= 0)
		{
			ft_push_a("pa", s);
			printf("pa\n");
		}
		ft_algofor5(s);
	}
}
