/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:17:10 by zamgar            #+#    #+#             */
/*   Updated: 2024/05/27 19:13:23 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dsize == 0 || dstlen >= dsize)
		return (srclen + dsize);
	while (dst[i] != '\0' && i < dsize)
		i++;
	while (src[j] != '\0' && i < dsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (srclen + dstlen);
}

/*int	main()
{
	char dst[10] = "Bonjour";
	char src[10] = "Aurevoir";
	size_t dsize = 5;

	printf("%zu", ft_strlcat(dst, (char *)src, dsize));
	

	return (0);
}*/
