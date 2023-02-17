/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:45:06 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/17 17:00:22 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void ft_print_env(t_list *list)
{
    int i;

    i = 0;
    while (list->env_vars[i])
    {
        printf("%s\n", list->env_vars[i]);
        i++;
    }
    
}