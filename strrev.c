char	*ft_strrev(char *str)
{
	int i = 0;
	char swpr;
	int len;

	while (str[i])
		i++;
	len = i;
	i = 0;
	while (i < (len / 2))
	{
		swpr = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i]  = swpr;
		i++;
	}
	return str;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	if (argc == 2)
		printf("%s\n", ft_strrev(argv[1]));
	return 0;
}

