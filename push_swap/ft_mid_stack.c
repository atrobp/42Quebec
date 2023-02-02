/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:18:41 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/12 22:26:26 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_reversed_order(t_struct *s)
{
	int	i;

	i = 0;
	while (i + 1 <= s->stackb_size)
	{
		if (s->stackb[i] < s->stackb[i + 1])
			return (0);
		i += 1;
	}
	return (1);
}

void	ft_putback(t_struct *s)
{
	int	pa;

	pa = 0;
	while (s->stackb_size >= 0)
	{
		while (s->stacka[0] < s->stackb[0])
		{
			ft_r_rotate_a("ra", s);
			printf("ra\n");
			pa += 1;
		}
		while (pa > 0 && s->stacka[s->stacka_size - 1] > s->stackb[0])
		{
			ft_r_rotate_a("rra", s);
			printf("rra\n");
			pa -= 1;
		}
		ft_push_a("pa", s);
		printf("%s\n", s->temp_b);
	}
}

int	ft_islower100(t_struct *s, int call)
{
	int	i;

	i = 0;
	while (i < s->stacka_size)
	{
		if (s->tab[i] < call * 20)
			return (1);
		i += 1;
	}
	return (0);
}

void	ft_mid_algo(t_struct *s, int call)
{
	if (ft_check_stack(s->stacka_size, 'o', s) == 1
		&& call * 20 <= 100)
	{
		while (ft_islower100(s, call) != 0)
		{
			if (s->tab[0] < call * 20)
				ft_push_b("pb", s);
			else
				ft_r_rotate_a("ra", s);
			printf("%s\n", s->temp_a);
			ft_bstuff(s);
			while (s->temp_b[0])
			{
				printf("%s\n", s->temp_b);
				ft_bstuff(s);
			}
		}
		ft_mid_algo(s, call += 1);
	}
	ft_astuff(s);
}

void	ft_algo_formid(t_struct *s)
{
	ft_mid_algo(s, 1);
	ft_putback(s);
}
