/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:44:33 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/17 08:54:45 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_minishell.h"

void ft_echo(char** arg)
{
    // if -n, print without \n
    if (arg[1] == "-n")
        printf("%s", arg[0]);
    else    
        printf("%s\n", arg[0]);
}