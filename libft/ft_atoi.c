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

void	handle_errors(int *pilea, int *pileb, int *pileacpy, int check)
{
	if (check == 0)
		ft_printf("Error (other chars)\n");
	if (check == 1)
		ft_printf("Error (number too big)\n");
	free(pilea);
    free(pileb);
    free(pileacpy);
    exit(0);
}

int	ft_atoi(const char *str, int *pilea, int *pileb, int *pileacpy)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			handle_errors(pilea, pileb, pileacpy, 0);
		nbr = nbr * 10 + str[i] - '0';
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
