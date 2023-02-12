/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:23:00 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/26 16:14:56 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_b(char *str, t_struct *s)
{
	int	i;
	int	temp;

	i = -1;
	s->stackb_size += 1;
	temp = s->stackb_size + 1;
	while (--temp > 0)
	{
		s->stackb[temp] = s->stackb[temp - 1];
	}
	s->stackb[temp] = s->stacka[0];
	while (++i < s->stacka_size)
	{
		s->stacka[i] = s->stacka[i + 1];
		s->tab[i] = s->tab[i + 1];
	}
	s->stacka_size -= 1;
	ft_strcpy(str, s->temp_a);
}

void	ft_push_a(char *str, t_struct *s)
{
	int	i;
	int	temp;

	i = -1;
	s->stacka_size += 1;
	temp = s->stacka_size + 1;
	while (--temp > 0)
	{
		s->stacka[temp] = s->stacka[temp - 1];
	}
	s->stacka[temp] = s->stackb[0];
	while (++i < s->stackb_size)
	{
		s->stackb[i] = s->stackb[i + 1];
	}
	s->stackb_size -= 1;
	ft_strcpy(str, s->temp_b);
}

void	ft_rotate_a(t_struct *s)
{
	int	i;
	int	temp;

	i = -1;
	temp = s->stacka[0];
	while (++i + 1 < s->stacka_size)
	{
		s->stacka[i] = s->stacka[i + 1];
		s->tab[i] = s->tab[i + 1];
	}
	s->stacka[i] = temp;
	s->tab[i] = temp;
}

void	ft_r_rotate_a(char *str, t_struct *s)
{
	int			i;
	int			temp;

	if (!str[2])
	{
		ft_rotate_a(s);
	}
	else
	{
		temp = s->stacka[s->stacka_size - 1];
		i = s->stacka_size + 1;
		while (--i > 0)
		{
			s->stacka[i] = s->stacka[i - 1];
			s->tab[i] = s->tab[i - 1];
		}
		s->stacka[i] = temp;
		s->tab[i] = temp;
	}
	ft_strcpy(str, s->temp_a);
}

void	ft_r_rotate_b(char *str, t_struct *s)
{
	int			i;
	int			temp;

	if (!str[2])
	{
		i = -1;
		temp = s->stackb[0];
		while (++i < s->stackb_size)
			s->stackb[i] = s->stackb[i + 1];
		s->stackb[i] = temp;
	}
	else
	{
		temp = s->stackb[s->stackb_size];
		i = s->stackb_size + 1;
		while (--i > 0)
			s->stackb[i] = s->stackb[i - 1];
		s->stackb[i] = temp;
	}
	ft_strcpy(str, s->temp_b);
}
