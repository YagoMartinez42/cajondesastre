#include <unistd.h>

int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && i >= 0)
			i--;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && i >= 0)
		{
			j++;
			i--;
		}
		while (j-- > 0)
			write(1, (argv[1] + (++i)), 1);
	}
	write(1, "\n", 1);
	return 0;
}

