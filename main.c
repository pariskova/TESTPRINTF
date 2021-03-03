#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("le chian printf : |%d|", atoi(argv[1]));
	printf("\n");
	ft_printf("mon vrai printf : |%d|", atoi(argv[1]));
	printf("\n");
	return(0);
}
	
