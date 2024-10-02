/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:08:33 by zamgar            #+#    #+#             */
/*   Updated: 2024/05/31 15:13:53 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//#include <stdio.h>

/* void    ft_free(char **array, int pilesize)
{
	while (pilesize > 0)
	{
		free(array[pilesize]);
		pilesize--;
	}
} */

void	handle_errors(char **array, int *pilea, int *pileb, int *pileacpy, int k, int pilesize, int check)
{
	ft_printf("Error\n");
	if (check == 1)
	{
		while (pilesize > 0)
		{
			free(array[pilesize]);
			pilesize--;
		}
	}
	free(pilea);
    free(pileb);
    free(pileacpy);
    exit(0);
}

int	ft_atoi(char **array, int *pilea, int *pileb, int *pileacpy, int k, int pilesize, int check)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(array[k][i]))
		i++;
	if (array[k][i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (array[k][i] == '+')
		i++;
	while (array[k][i] != '\0')
	{
		if (!(array[k][i] >= '0' && array[k][i] <= '9'))
			handle_errors(array, pilea, pileb, pileacpy, k, pilesize, check);
		nbr = nbr * 10 + array[k][i] - '0';
		i++;
	}
	/* ft_printf("%d\n", (size_t)nbr);
	if (((size_t)nbr * sign) > 2147483647 && ((size_t)nbr * sign) != -2147483648)
		handle_errors(pilea, pileb, pileacpy, 1); */
	return (nbr * sign);
}

/*int	main() 
{
	const char	str[30] = "-+48";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}*/
