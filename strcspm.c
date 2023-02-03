#include <stdlib.h>

size_t	ft_strcspn(const char* s, const char* reject)
{
	size_t i = 0;
	size_t j;

	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return i;
			j++;
		}
		i++;
	}
	return i;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	int indx;
	if (argc == 2)
	{
		indx = ft_strcspn(argv[1], " \t\n\r");
		printf("Whitespace in index %i\n", indx);
		indx = strcspn(argv[1], " \t\n\r");
		printf("Whitespace in index %i\n", indx);
	}
}
