/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decision_maker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:06:21 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/11 23:01:05 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(char *str, int *stack, t_struct *s)
{
	int	temp;

	temp = stack[1];
	stack[1] = stack[0];
	stack[0] = temp;
	if (str[1] == 'a')
		ft_strcpy(str, s->temp_a);
	else
		ft_strcpy(str, s->temp_b);
}

void	ft_setnbrs(t_struct *s, int size)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	if (size < s->stacka_size)
	{
		while (i < s->stacka_size)
		{
			if (s->stacka[i] > s->stacka[size])
				pos += 1;
			i += 1;
		}
		s->tab[size] = s->stacka_size - pos;
		ft_setnbrs(s, size += 1);
	}
}

void	ft_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = 0;
}

void	ft_decide_next(t_struct *s)
{
	s->stackb = malloc(sizeof(int) * (s->stacka_size + 1));
	s->tab = malloc(sizeof(int) * (s->stacka_size + 1));
	s->temp_a = malloc(sizeof(char) * 4);
	s->temp_b = malloc(sizeof(char) * 4);
	s->stackb_size = -1;
	if (s->stacka_size < 50)
		ft_algofor5(s);
	else
	{
		ft_setnbrs(s, 0);
		s->origsize = s->stacka_size;
		if (s->stacka_size > 105)
			ft_algo_forbig(s);
		else
			ft_algo_formid(s);
	}
	free(s->tab);
	free(s->stackb);
	free(s->temp_a);
	free(s->temp_b);
}
