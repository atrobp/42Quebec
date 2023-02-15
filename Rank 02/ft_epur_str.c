#include <unistd.h>

void	epurstr(char *str){
	int	flag = 0;

	for (int i = 0; str[i]; i++){
		while (str[i] == ' ' || str[i] == '	')
			i += 1;
		if (flag == 1)
			write(1, " ", 1);
		while (str[i] > ' '){
			flag = 1;
			write(1, &str[i], 1);
			i += 1;
		}
	}
}

int	main(int ac, char **av){
	ac == 2 ? epurstr(av[1]): 0;
	write(1, "\n", 1);
	return 0;
}
