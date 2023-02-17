/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:48:10 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/17 17:25:54 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		*(char *)(s + i) = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*array;

// 	if (count == 0 || size == 0)
// 	{
// 		count = 1;
// 		size = 1;
// 	}
// 	array = malloc(count * size);
// 	if (!array)
// 		return (array);
// 	ft_bzero(array, (count * size));
// 	return (array);
// }

static int	ft_char_in_set(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	str_size;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str_size = (end - start + 1);
	str = (char *)malloc(str_size * sizeof(*s1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

void	ft_free_str_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	get_arr_len(char *str, char *set)
{
	char	*trimmed_str;
	int		arr_len;
	int		i;

	trimmed_str = ft_strtrim(str, set);
	if (trimmed_str == 0)
		return (-1);
	arr_len = 0;
	i = 0;
	if (ft_strchr(set, trimmed_str[i]) == 0)
		arr_len++;
	while (trimmed_str[i])
	{
		if (ft_strchr(set, trimmed_str[i]) != 0)
			arr_len++;
		i++;
	}
	free(trimmed_str);
	return (arr_len);
}

int	get_element_size(char *str, char *set)
{
	int	size;

	size = 0;
	while (*str && ft_strchr(set, *str) == 0)
	{
		size++;
		str++;
	}
	return (size);
}
char	**ft_split_set(char *str, char *set)
{
	char	**arr;
	int		arr_len;
	int		i;
	int		j;

	i = 0;
	if (!str || !set)
		return (0);
	arr_len = get_arr_len(str, set);
	arr = ft_calloc(arr_len + 1, sizeof(*arr));
	if (!arr)
		return (0);
	while (i < arr_len && *str)
	{
		j = 0;
		while (*str && ft_strchr(set, *str) != 0)
			str++;
		arr[i] = ft_calloc(get_element_size(str, set) + 1, sizeof(*arr[i]));
		if (arr[i] == 0)
		{
			ft_free_str_array(arr);
			return (0);
		}
		while (*str && ft_strchr(set, *str) == 0)
			arr[i][j++] = *str++;
		i++;
	}
	return (arr);
}