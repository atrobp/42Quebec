#pragma once

#undef BUFFER_SIZE
#define BUFFER_SIZE 1

#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd);
char	*_strdup(char *src, char *dst, int call, int *newline);
