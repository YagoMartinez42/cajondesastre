#include <stdlib.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int j;

	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				break;
			j++;
		}
		if (!accept[j])
			return (i);
		i++;
	}
	return i;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{

	if (argc == 2)
	{
		printf("non-whitespace starts at index %i\n", ft_strspn(argv[1], " \t\n\r"));
		printf("non-whitespace starts at index %i\n", strspn(argv[1], " \t\n\r"));
	}
	return 0;
}
