#include <stdio.h>

int ft_atoi (const char *str)
{
	int num = 0;
	int i = 0;
	int sign = 1;
	
	while ((str[i] >= 9 && str[i]<= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int main(int argc, char** argv)
{
	int n;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		printf("%i\n", n);
	}
}
