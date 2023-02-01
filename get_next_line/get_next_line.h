/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:41:24 by atopalli          #+#    #+#             */
/*   Updated: 2022/09/27 13:28:55 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
