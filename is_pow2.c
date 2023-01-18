/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pow2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:28:52 by samartin          #+#    #+#             */
/*   Updated: 2023/01/18 12:23:46 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Checks if a number is power of 2. That is true if there is a single positive
 * bit in the number. To check it, we move the bits to the right until there is
 * any in position 1 (n & 1 == true), if at that point n == 1, its original
 * value was power of 2, otherwise it was not, because there were some other
 * positive bits. (1 is also power of 2: 1 = 2^0).
 */
int	is_pow2(unsigned int n)
{
	while (n >= 1)
	{
		if (n & 1)
		{
			if (n == 1)
				return (1);
			else
				return (0);
		}
		n = n >> 1;
	}
	return (0);
}
