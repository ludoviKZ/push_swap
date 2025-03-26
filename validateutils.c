/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:05:53 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/26 17:09:02 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	atol(const char *str)
{
	long	result;
	int	neg;

	result = 0;
	neg = 1;
	while (*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * neg);
}