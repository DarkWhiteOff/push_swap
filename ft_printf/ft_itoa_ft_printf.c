/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ft_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:55:18 by zamgar            #+#    #+#             */
/*   Updated: 2024/10/07 13:55:24 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_ft_printf(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_min_ft_printf(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa_ft_printf(int n)
{
	int		i;
	char	*str;

	i = ft_count_ft_printf(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		return (ft_min_ft_printf(str));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	while (n >= 10)
	{
		str[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	str[i - 1] = n + '0';
	return (str);
}

int	ft_itoa2(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_ft_printf(n);
	i = ft_strlen((const char *)str);
	ft_putstr(str);
	free(str);
	return (i);
}
