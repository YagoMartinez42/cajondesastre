int is_power_of_2(unsigned int n)
{
	while (n >= 1)
	{
		if (n & 1)
		{
			if (n == 1)
				return (1);
			else
				return (0);
		}
		n = n >> 1;
	}
	return (0);
}

#include <unistd.h>

int main (void)
{
	unsigned int n1 = 1;
	unsigned int n2 = 12;
	unsigned int n3 = 64;

	if (is_power_of_2(n1))
		write(1, "n1 es\n", 6);
	if (is_power_of_2(n2))
		write(1, "n2 es\n", 6);
	if (is_power_of_2(n3))
		write(1, "n3 es\n", 6);
	return 0;
}
