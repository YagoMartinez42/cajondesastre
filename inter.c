#include <unistd.h>

int char_in(char* str, char c)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main(int argc, char** argv)
{
	char interset[128] = "";
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!(char_in(interset, argv[1][i])) && (char_in(argv[2], argv[1][i])))
			{
				interset[j] = argv[1][i];
				j++;
			}
			i++;
		}
	}
	interset[j] = '\n';
	interset[j + 1] = '\0';
	write(1, interset, j+1);
	return 0;
}
