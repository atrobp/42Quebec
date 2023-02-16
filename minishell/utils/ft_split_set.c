/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:48:10 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/11 10:44:33 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_free_str_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
    return (0);
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
char	**ft_split_set(char *str, char set)
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
			return (ft_free_str_array(arr));
		while (*str && ft_strchr(set, *str) == 0)
			arr[i][j++] = *str++;
		i++;
	}
	return (arr);
}
