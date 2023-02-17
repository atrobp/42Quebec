/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:16:27 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/17 16:10:01 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

int	throw_error(char *error, int exit_code)
{
	printf("\033[0;31m\n");
	printf("Error\n%s\n", error);
	printf("\033[0m");
	if (exit_code >= 0)
		exit(exit_code);
	return (1);
}

//  return the rest of the haystack including the needle if the first occurence of the needle is found 
//  or the whole haystack if both values are the same. return NULL if set of letters not founded
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

void	ft_edit_env(char *name, char *buffer, t_list *list)
{
	int i;
	int j;
    char*   var_name;
    char*   parsed_name;

    i = 0;
	j = 0;
    parsed_name = ft_strjoin(name, "=");
    while (list->env_vars[i])
	{
        var_name = ft_strnstr(list->env_vars[i], parsed_name, ft_strlen(list->env_vars[i]));
		if (var_name)
        {
            j = 0;
            while (list->env_vars[i][j])
            {
                list->env_vars[i][j] = 0;
                j++;
            }
            free(list->env_vars[i]);
            list->env_vars[i] = ft_strjoin(parsed_name, buffer);
            free(parsed_name);
            return ;
        }
		i++;
	}
    free(parsed_name);
}