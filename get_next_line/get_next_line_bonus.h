/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:01:55 by atopalli          #+#    #+#             */
/*   Updated: 2022/09/28 17:14:52 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	char	*temp;
	int		flag;
	int		buf;
}				t_struct;

char	*get_next_line(int file_desc);
int		ftstrlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif