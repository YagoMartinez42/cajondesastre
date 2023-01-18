/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pow2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:28:52 by samartin          #+#    #+#             */
/*   Updated: 2023/01/18 12:03:41 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Checks if a number is power of 2. That is true if there is a single positive
 * bit in the number and it is not 1. To check it, we move the bits to the right
 * until there is any in position 2 (n & 2 == true), if at that point n == 2,
 * its original value was power of 2, otherwise it was not, because there were
 * some other positive bits.
 */
int	is_pow2(unsigned int n)
{
	while (n >= 2)
	{
		if (n & 2)
		{
			if (n == 2)
				return (1);
			else
				return (0);
		}
		n = n >> 1;
	}
	return (0);
}
