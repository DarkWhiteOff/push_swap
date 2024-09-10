/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:50:48 by zamgar            #+#    #+#             */
/*   Updated: 2024/05/27 19:20:48 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

/*int	main()
{
	char	str[15] = "oabfajf";
	
	printf("%s\n", str);
	ft_bzero(str, 0);
	printf("%s\n", str);
	return (0);
}*/
