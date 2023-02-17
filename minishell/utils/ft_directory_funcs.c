/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directory_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:58:11 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/17 17:47:42 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minishell.h"

// ~ == /Users/${HOSTNAME}

// char    **get_files_in_path(char *path)
// {
//     input = "/bin"
//     output = {{"bash"}, {"cat"}, {"echo"}, {"mv"}, {"cp"}, etc. }
// }

// char    **get_previous_path(char *path)
// {
//     input = "/bin"
//     output = {{"bash"}, {"cat"}, {"echo"}, {"mv"}, {"cp"}, etc. }
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
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

char	*ft_get_variable(char *env_var)
{
}