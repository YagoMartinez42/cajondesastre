#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return NULL;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	char* indx;
	if (argc == 2)
	{
		indx = ft_strpbrk(argv[1], " \t\n\r");
		printf("Whitespace from %s\n", indx);
		indx = strpbrk(argv[1], " \t\n\r");
		printf("Whitespace from %s\n", indx);
	}
}
