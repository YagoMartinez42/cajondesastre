static void ft_to_lower(char* str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

static int ft_strchar(char* str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return i;
		i++;
	}
	return -1;
}

int ft_atoi_base(const char *str, int base)
{
	int n = 0;
	int i = 0;
	int j = 0;
	int sign = 1;
	char str_base[17] = "0123456789abcdef";

	if (base > 1 && base < 17)
	{
		ft_to_lower((char*)str);
		while ((str[i] >= 9 && str[i]<= 13) || str[i] == ' ')
			i++;
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && ((j = ft_strchar(str_base, str[i])) >= 0))
		{
			n *= base;
			n += j;
			i++;
		}
	}
	return (n * sign);
}

#include <stdio.h>

int main(int argc, char** argv)
{
	int n;
	if (argc > 1)
	{
		n = ft_atoi_base(argv[1], 16);
		printf("%i", n);
	}
	return 0;
}
