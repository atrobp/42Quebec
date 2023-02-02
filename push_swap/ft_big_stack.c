/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:05:00 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/26 13:25:48 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putback500(t_struct *s)
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

int	ft_islower500(t_struct *s, int call)
{
	int	i;

	i = 0;
	while (i < s->stacka_size)
	{
		if (s->tab[i] < call * 50)
			return (1);
		i += 1;
	}
	return (0);
}

void	ft_big_algo(t_struct *s, int call)
{
	if (ft_check_stack(s->stacka_size, 'o', s) == 1
		&& call * 50 <= 500)
	{
		while (ft_islower500(s, call) != 0)
		{
			if (s->tab[0] < call * 50)
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
		ft_big_algo(s, call += 1);
	}
}

void	ft_algo_forbig(t_struct *s)
{
	ft_big_algo(s, 1);
	ft_putback500(s);
}
