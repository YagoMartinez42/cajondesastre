/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_num_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:34:37 by samartin          #+#    #+#             */
/*   Updated: 2023/05/05 12:00:36 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "./libft/libft.h"

char	*gen_num()
{
	int		n;
	int		sign;
	char *	num;

	n = rand();
	sign = rand();
	if (sign & 1)
		n *= -1;
	num = ft_itoa(n);
	
	return (num);
}

int main(int argc, char** argv)
{
	int		count;
	char 	*str;
	char	*aux;
	char	*num;

	if (argc == 2)
	{
		str = malloc (1);
		count = ft_atoi(argv[1]);
		srand(time(0));
		while (count > 0)
		{
			aux = str;
			str = ft_strjoin(str, " ");
			free(aux);
			num = gen_num();
			aux = str;
			str = ft_strjoin(str, num);
			free(aux);
			count--;
		}
		ft_printf("%s\n", str);
	}
	return (0);
}
