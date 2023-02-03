#include <unistd.h>

int main(int argc, char** argv )
{
	int i = 0;
	int f = 0;

	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				if (f == 1 && (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
					write (1, "   ", 3);
				write (1, (argv[1] + i), 1);
				f = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
