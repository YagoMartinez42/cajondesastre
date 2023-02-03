/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:09:51 by samartin          #+#    #+#             */
/*   Updated: 2023/01/09 12:37:14 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char** argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{	
			if (argv[1][i] >= 65 && argv[1][i] <= 90)
				argv[1][i] = 155 - argv[1][i];
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
				argv[1][i] = 219 - argv[1][i];
			write (1, argv[1] + i, 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return 0;
}
