/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:49:49 by samartin          #+#    #+#             */
/*   Updated: 2023/03/14 13:09:00 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	unsigned int x;
	unsigned int y;
	unsigned int den = 3;
	unsigned int i;
	unsigned int j;
	unsigned int p;
	unsigned int e;
	int fd;
	
	if (argc != 4)
	{
		ft_printf("Two numeric arguments >= 4 and a filename needed\n");
		return (-1);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x < 4 || y < 4)
	{
		ft_printf("Two numeric arguments >= 4 and a filename needed\n");
		return (-1);
	}
	p = 0;
	e = 0;
	i = 0;
	j = 0;
	srand(time(NULL));
	fd = open(argv[3], O_WRONLY | O_APPEND | O_CREAT, 0644);
	while (j < y)
	{
		i = 0;
		if (j == 0 || j == y - 1)
		{
			while (i < x)
			{
				write(fd, "1", 1);
				i++;
			}
		}
		else
		{
			while (i < x)
			{
				if (i == 0 || i == x - 1)
					write(fd, "1", 1);
				else
				{
					if ((rand() % (x * y)) < den && p == 0)
					{
						write(fd, "P", 1);
						p = 1;
					}
					else if ((rand() % (x * y)) < den && e == 0)
					{
						write(fd, "E", 1);
						e = 1;
					}
					else if ((rand() % x) == 0)
						write(fd, "C", 1);
					else if ((rand() % y) < den)
						write(fd, "1", 1);
					else
						write(fd, "0", 1);
				}
				i++;
			}
		}
		write(fd, "\n", 1);
		j++;
	}
	close(fd);
	return (1);
}