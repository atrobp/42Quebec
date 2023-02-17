/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:14:02 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/17 17:45:22 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"
char	*ft_memjoin(char *s1, char *s2)
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
    // if (buffer == "~" || !buffer)
	// 	chdir(ft_getenv("HOME", list->env_vars));
	// set PWD to the desired path if chdir(buffer) == 0
	if (!buffer)
		buffer = ft_getenv("HOME", list->env_vars);
	if (chdir(buffer) < 0)
		printf("error finding path\n");
	else 
	{
		// if OLDPWD unexistent,  if (list->cd_count == 0) dont update OLDPWD
		//                        else add OLDPWD
		// set OLDPWD to the previous path aka the current PWD before changing anithing
		// ft_getenv("OLDPWD", list->env_vars) == 0 && list->cd_count == 1
		// TODO: has to go through the condition is OLDPWD exists in the list->env_vars
		if (1)
		{
			ft_edit_env("OLDPWD", ft_getenv("PWD", list->env_vars), list);
			free(list->cmd);
			list->cmd = ft_memdup("export OLDPWD=", ft_getenv("PWD", list->env_vars), END);
			// ft_env_edit_add(list);
		}
		ft_edit_env("PWD", getcwd(NULL, 0), list);
		list->cmd = ft_memdup("export PWD=", getenv("PWD"), END);
		// ft_env_edit_add(list);
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
	char**			input_tmp;
	char**			path_tmp;
	static void		(*ptr_func[3])(t_list *)
		= {ft_env_print, ft_env_edit_add, ft_env_delete};
	ft_setspecial_cmd(p);
	char* cmd = ft_memdup(p->cmd, EMPTY, ' ');
	if (ft_memcmp(cmd, "cd"))
	{
		cd(p, p->cmd + ft_memlen(p->cmd, ' '));
	}
	if (ft_memcmp(cmd, "edit"))
	{
		ft_edit_env("PWD", p->cmd + ft_memlen(p->cmd, ' '), p);
		free(cmd);
		return ;
	}
	if (ft_memcmp(cmd, "env"))
	{
		ft_print_env(p);
		return ;
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
		input_tmp = ft_split_set(p->cmd, "|");
		path_tmp = ft_split_set(ft_getenv("PATH", p->env_vars), ":");
		ft_valid_and_send(input_tmp, path_tmp);
		system(p->cmd);
	}
	ft_free_str_array(input_tmp);
	ft_free_str_array(path_tmp);
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
	size_t	len;
	char	**array;

	i = -1;
	len = 0;
	if (!str[0])
		return (NULL);
	while (str[++i])
	{
		if (str[i] == set)
			len += 1;
	}
	i = 0;
	j = 0;
	array = malloc(sizeof(array) * len) + 1;
	if (!array)
		return (NULL);
	while (str[i] && i < ft_memlen(str, END))
	{
		while (str[i] <= ' ')
			i += 1;
		array[j] = ft_memdup(str + i, EMPTY, set);
		i += ft_memlen(str + i, set);
		j += 1;
	}
	array[j] = NULL;
	return (array);
}
