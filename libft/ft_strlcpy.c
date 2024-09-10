/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:54:37 by zamgar            #+#    #+#             */
/*   Updated: 2024/05/30 15:05:46 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen((char *)src);
	if (dsize == 0)
		return (srclen);
	while ((char)src[i] != '\0' && i < (dsize - 1))
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/*int	main()
{
	//char	src[50] = "Bonjour";
	char	dst[50];
	
	printf ("%zu\n", ft_strlcpy(dst, "", 3));
	printf("%s\n", dst);
	return (0);
}*/
