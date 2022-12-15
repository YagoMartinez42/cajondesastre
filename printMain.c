#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	unsigned int num = 65595;
	float flo = 10.10003033f;
	char	*str = "Hola";

	ft_printf("%s %c\n", "Hola Mundo", '!');
	printf("%s %c\n", "Hola Mundo", '!');
	ft_printf("%i, %i, %%, %u, %x, %X, %p\n", 100, -672222, (unsigned int)4100000000, num, num, str);
	printf("%i, %i, %%, %u, %x, %X. %p\n", 100, -672222, (unsigned int)4100000000, num, num, str);
	ft_printf ("%f\n", flo);
	return 0;
}