/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:45:52 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/11 10:43:10 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// size_t number_of_strings = sizeof(names) / sizeof(names[0]);
void ft_swap(char** s1, char** s2)
{
    char* tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void ft_put_strs(char** strs, int number_of_strings)
{
    int i;

    i = 0;
    while (i < number_of_strings)
    {
        printf("%s\n", strs[i]);
        i++;
    }
}

void ft_sort_strs(char** strs, int number_of_strings)
{
    char *tmp;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < number_of_strings)
    {
        j = -1;
        while (++j < number_of_strings)
            if(strcmp(strs[i], strs[j]) < 0)
                ft_swap(&strs[i], &strs[j]);
        i++;
    }
}