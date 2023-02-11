/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directory_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:58:11 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/10 16:29:30 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

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

void	*cd(t_list *list, const char *buffer)
{
    char* path = buffer;
    
    // send to home VALUE is ~ or no path
    if (path == '~' || !path)
        chdir(ft_getenv("HOME", list->env));
	// set PWD to the desired path if chdir(buffer) == 0
	if (chdir(path) < 0)
		throw_error("error finding path");
	else 
	{
		// if OLDPWD unexistent,  if (list->cd_count == 0) dont update OLDPWD
		//                        else add OLDPWD
		// set OLDPWD to the previous path aka the current PWD before changing anithing
		if (ft_getenv("OLDPWD", list->env) == 0 && list->cd_count == 1)
		{
			free(list->cmd);
			list->cmd = ft_memdup("export OLDPWD=", ft_getenv("PWD", list->env), END);
			ft_env_edit_add(list);
		}
		free(list->cmd);
		list->cmd = ft_memdup("export PWD=", buffer, END);
		ft_env_edit_add(list);
	}
	// ft_get_variable("HOME");
	// ft_set_variable("OLDPWD", pwd);
}

char	*ft_get_variable(char *env_var)
{
}