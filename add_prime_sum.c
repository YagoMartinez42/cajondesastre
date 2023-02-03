#include <unistd.h>

static int ft_is_prime(unsigned long n)
{
	int i = 2;
	if (n < 2)
		return 0;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

static void ft_put_num(unsigned long n)
{
	char n_str[20];
	int dig = 0;

	while (n >= 10)
	{
		n_str[dig] = (n % 10) + '0';
		n /= 10;
		dig++;
	}
	n_str[dig] = n + '0';
	n_str[dig + 1] = '\0';
	while (dig >= 0)
	{
		write(1, n_str + dig, 1);
		dig--;
	}
	write(1, "\n", 1);
}

static unsigned long ft_atoi(char* str)
{
	unsigned long n = 0;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n);
}

int main(int argc, char** argv)
{
	unsigned long num = 0;
	unsigned long i = 2;
	unsigned long sum = 0;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return -1;
	}
	num = ft_atoi(argv[1]);
	while (i <=  num)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	ft_put_num(sum);
	return 0;
}
