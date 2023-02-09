

#include "../include/ft_minishell.h"

bool	ft_isnewline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (true);
		i += 1;
	}
	return (false);
}


char	*ft_retword(char *src, char *dst, int size)
{
	char	*str;
	int		i;
	int		copy;

	str = malloc(sizeof(char) * (size * 2));
	i = 0;
	copy = 0;
	if (size > 1)
	{
		while (dst[i])
		{
			str[copy] = dst[i];
			i += 1;
			copy += 1;
		}
		free(dst);
	}
	i = -1;
	while (src[++i])
	{
		str[copy] = src[i];
		copy += 1;
	}
	str[copy] = 0;
	return (str);
}

char	*ft_gnl()
{
	char	*final;
	char	temp[2];
	int		ret;
	int		time;

	time = 0;
	ret = read(0, &temp, 1);
	while (1)
	{
		while (ret > 0)
		{
			temp[1] = 0;
			final = ft_retword(temp, final, ++time);
			if (ft_isnewline(final) == true)
				break ;
			ret = read(0, &temp, 1);
		}
		system(final);
		free(final);
	}
}
