#include <unistd.h>

int	_strlen(char *str) {
	int	i = 0;

	for (; str[i]; i++) ;
	return i;
}

int	main(int ac, char **av) {
	int	i  = 0;

	if (ac == 3) {
		for (int j = 0; av[2][j]; j++) {
			if (av[2][j] == av[1][i]) {
				i += 1;
			}
			if (!av[1][i]) {
				write(1, av[1], _strlen(av[1]));
				break ;
			}
		}
	}
	write(1, "\n", 1);
	return 0;
}
