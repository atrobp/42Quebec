/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:14:02 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/16 16:17:09 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_memlen(s1, END) + ft_memlen(s2, END) + 1) * sizeof(char));
	if (!str)
		return (NULL);
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

void	cd(t_list *list, char *buffer)
{
    // send to home VALUE is ~ or no path
    if (ft_memcmp(buffer, "~") || !buffer)
        chdir(ft_getenv("HOME", list->env_vars));
	// if (ft_memcmp(buffer, "..") || !buffer)
    //     getcwd(oldpwd);
	// set PWD to the desired path if chdir(buffer) == 0
	if (chdir(buffer) < 0)
		printf("error finding path");
	else 
	{
		// if OLDPWD unexistent,  if (list->cd_count == 0) dont update OLDPWD
		//                        else add OLDPWD
		// set OLDPWD to the previous path aka the current PWD before changing anithing
		if (ft_getenv("OLDPWD", list->env_vars) == 0 && list->cd_count == 1)
		{
			free(list->cmd);
			list->cmd = ft_memdup("export OLDPWD=", ft_getenv("PWD", list->env_vars), END);
			ft_env_edit_add(list);
		}
		free(list->cmd);
		list->cmd = ft_memdup("export PWD=", ft_strjoin(ft_getenv("PWD", list->env_vars), buffer), END);
		ft_env_edit_add(list);
	}
	// ft_get_variable("HOME");
	// ft_set_variable("OLDPWD", pwd);
}

void	*ft_trimcmd(char *str)
{
	int	i;
	int	copy;

	i = 0;
	copy = 0;
	while (str[i] == ' ' || str[i] == '	')
		i += 1;
	while (str[i])
	{
		str[copy] = str[i];
		i += 1;
		copy += 1;
		while (str[i] && str[i] <= ' ')
		{
			if (str[i + 1] > ' ')
				str[copy++] = ' ';
			i += 1;
		}
	}
	str[copy] = 0;
	return (str);
}

void	ft_check_cmd(t_list *p)
{
	size_t			i;
	static void		(*ptr_func[3])(t_list *)
		= {ft_env_print, ft_env_edit_add, ft_env_delete};

	ft_setspecial_cmd(p);
	// cd desktop
	char* cmd = ft_memdup(p->cmd, EMPTY, ' ');
	if (ft_memcmp(cmd, "cd"))
	{
		cd(p, p->cmd + ft_memlen(p->cmd, ' '));
	}
	free(cmd);
	
	i = 0;
	while (i < 3)
	{
		if (ft_memcmp(p->cmd, p->spec_cmd[i]))
		{
			ptr_func[i](p);
			break ;
		}
		free(p->spec_cmd[i]);
		i += 1;
	}
	if (i == 3)
	{
		ft_valid_and_send(ft_split(p->cmd, '|'), ft_split(ft_getenv("PATH", p->env_vars), ':'));
	}
	while (i < 3)
		free(p->spec_cmd[i++]);
	free(p->cmd);
}

void	ft_setspecial_cmd(t_list *p)
{
	p->spec_cmd[0] = ft_memdup("export", EMPTY, END);
	p->spec_cmd[1] = ft_memdup("export ", EMPTY, END);
	p->spec_cmd[2] = ft_memdup("unset ", EMPTY, END);
	p->spec_cmd[3] = NULL;
	if (ft_memchr(p->cmd, ' '))
	{
		free(p->spec_cmd[1]);
		free(p->spec_cmd[2]);
		p->spec_cmd[1] = ft_memdup("export ", p->cmd + 7, END);
		p->spec_cmd[2] = ft_memdup("unset ", p->cmd + 6, END);
	}
}

char	**ft_split(char *str, char set)
{
	size_t	i;
	size_t	j;
	char	**array;

	i = -1;
	j = 0;
	if (!str[0])
		return (NULL);
	while (str[++i])
		if (str[i] == set)
			j += 1;
	array = malloc(sizeof(array) * (j + 1)) + 1;
	i = 0;
	j = 0;
	if (!array)
		return (NULL);
	array[0] = ft_memdup("me like apples", EMPTY, END);
	while (str[i] && i < ft_memlen(str, END))
	{
		while (str[i] == ' ')
			i += 1;
		array[j] = ft_memdup(str + i, EMPTY, set);
		printf("1: %s\n", array[j]);
		i += ft_memlen(str + i, set);
		j += 1;
	}
	array[j] = NULL;
	printf("2: %s\n", array[j]);
	printf("i: %ld\n", j);
	return (array);

}

