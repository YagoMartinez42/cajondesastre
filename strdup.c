#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char* dst;

	while (src[len])
		len++;
	dst = malloc(len + 1);
	while (i <= len)
	{
		dst[i] = src [i];
		i++;
	}
	return dst;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	char frase[50] = "Hola mundo";
	char* frase2;
	printf("%s\n", frase);
	frase2 = ft_strdup(frase);
	printf("%s\n", frase2);
	frase2 = strdup(frase);
	printf("%s\n", frase2);
	return 0;
}
