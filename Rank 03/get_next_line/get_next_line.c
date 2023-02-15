#include "get_next_line.h"

char	*_strdup(char *src, char *dst, int call, int *newline) {
	char	*temp = malloc(sizeof(char) * call + 1);
	int		i = 0;

	if (!temp) return NULL;
	if (call > 1) {
		for (size_t j = 0; src[j]; j++) {
			temp[i] = src[j];
			i += 1;
		}
		free(src);
	}
	for (size_t j = 0; dst[j]; j++) {
		temp[i] = dst[j];
		i += 1;
		if (temp[i - 1] == '\n') {
			*newline = 1;
			break ;
		}
	}
	temp[i] = 0;
	return temp;
}

int	get_next_line(int fd) {
	char	*src = NULL, dst[3];
	int		call, newline;

	call = newline = 0;
	if (BUFFER_SIZE > 0 && fd >= 0) {
		while (read(fd, dst, BUFFER_SIZE)) {
			dst[1] = 0;
			src = _strdup(src, dst, ++call, &newline);
			if (newline == 1) break ;
		}
	}
	return src;
}
