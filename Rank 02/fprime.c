#include <stdio.h>

void	fprime(int nbr){
	for (int i = 2; i <= nbr; i += 1){
		if (nbr % i == 0){
			printf("%d", i);
			if (i != nbr)
				printf("*");
			nbr /= i;
			i = 1;
		}
	}
}

int	main(int ac, char **av){
	ac == 2 ? atoi(av[1]) == 1 ? printf("1") : fprime(atoi(av[1])) : 0;
	printf("\n");
	return 0;
}
