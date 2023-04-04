/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   signals.c                                      ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/04/01 17:30:21 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/01 17:50:13 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sighandler(int sig)
{
	if (sig == SIGINT)
	{
		putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
