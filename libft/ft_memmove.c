/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:43:08 by zamgar            #+#    #+#             */
/*   Updated: 2024/05/31 14:34:41 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>
//#include <string.h>

static void	*ftft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)(dest);
	s = (unsigned char *)(src);
	if (s == d || n == 0)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	*temp;

	i = 0;
	s = (unsigned char *)(src);
	d = (unsigned char *)(dest);
	temp = s;
	if (s == d || n == 0)
		return (dest);
	if (d < s)
		return (ftft_memcpy(dest, src, n));
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = temp[i - 1];
			i--;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	*dest;
	char	*src = "lorem ipum dolor sit amet";
	char	s0[] = {0, 0, 0, 0, 0, 0, 0};
	char	s[] = {65, 66, 67, 68, 69, 0, 45};
	char	sr1[] = {67, 68, 67, 68, 69, 0, 45};
	char	sr2[] = {67, 67, 68, 68, 69, 0, 45};

	printf("%s\n\n", (char *)ft_memmove(sr1 + 1, sr1, 2));
	printf("%s\n", (char *)memmove(sr1 + 1, sr1, 2));
	return (0);
}*/
