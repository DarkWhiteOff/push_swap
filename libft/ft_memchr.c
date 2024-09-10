/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:08:27 by zamgar            #+#    #+#             */
/*   Updated: 2024/05/31 14:23:34 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*ss;

	i = 0;
	ss = (unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return (&ss[i]);
		i++;
	}
	return (NULL);
}

/*int	main()
{
	//unsigned char	s[50] = "okcok";
	char	s[] = {0, 1, 2, 3, 4, 5};

	printf("%s\n", (char *)ft_memchr(s, 0, 0));
	printf("%s\n", (char *)ft_memchr(s, 0, 1));
	printf("%s\n", (char *)ft_memchr(s, 2, 3));
	printf("%s\n", (char *)ft_memchr(s, 6, 4));
	printf("%s\n\n", (char *)ft_memchr(s, 2 + 256, 3));

	printf("%s\n", (char *)memchr(s, 0, 0));
        printf("%s\n", (char *)memchr(s, 0, 1));
        printf("%s\n", (char *)memchr(s, 2, 3));
        printf("%s\n", (char *)memchr(s, 6, 4));
	printf("%s\n", (char *)memchr(s, 2 + 256, 3));
	return (0);
}*/
