/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:14 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/04 18:19:43 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>

static int	ft_set_check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static size_t	ft_check_beg(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_set_check(set, str[i]) == 0)
		i++;
	if (i == ft_strlen(str))
		return (0);
	return (i);
}

static size_t	ft_check_end(char const *str, char const *set)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (str[i] != '\0')
		i++;
	i = i - 1;
	while (ft_set_check(set, str[i]) == 0)
	{
		z++;
		i--;
	}
	if (z + 1 == ft_strlen(str))
		return (0);
	return (z);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			z;
	size_t			checkb;
	size_t			checke;
	char			*newstr;

	i = ft_strlen(s1);
	checkb = ft_check_beg(s1, set);
	checke = ft_check_end(s1, set);
	newstr = (char *)malloc(sizeof(char) * (i - (checkb + checke)) + 1);
	if (newstr == NULL)
		return (NULL);
	z = 0;
	i = i - (checkb + checke);
	while (z < i)
	{
		newstr[z] = s1[checkb];
		z++;
		checkb++;
	}
	newstr[z] = '\0';
	return (newstr);
}

/*int	main()
{
	char	*s1 = "   xxxtripouille   xxx";
	char	*set =  " x";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
