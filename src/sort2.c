/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:22:32 by zamgar            #+#    #+#             */
/*   Updated: 2024/10/06 14:22:34 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strbitlen(char *octet)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (octet[j] != '1' && octet[j] != '\0')
		j++;
	while (octet[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

int	decimal_to_bits(int max_value)
{
	int		i;
	int		j;
	char	*octet;

	i = 31;
	j = 0;
	octet = malloc (sizeof(char) * 33);
	while (i >= 0)
	{
		octet[j] = (max_value >> i & 1) + '0';
		i--;
		j++;
	}
	octet[j] = '\0';
	i = ft_strbitlen(octet);
	free(octet);
	return (i);
}

void	push_and_rotate(int *pilea, int *pileb, int i, t_pszab *pilesizes)
{
	if ((pilea[0] >> i & 1) == 0)
	{
		pb(pilea, pileb, pilesizes->pa, pilesizes->pb);
		pilesizes->pa -= 1;
		pilesizes->pb += 1;
		ft_printf("pb\n");
	}
	else
	{
		ra_rb(pilea, pilesizes->pa);
		ft_printf("ra\n");
	}
}

void	bit_and_set(int *pilea, int *pileb, t_pszab *pilesizes)
{
	int	i;
	int	j;
	int	pilesize;
	int	bit_index_max;

	i = 0;
	j = 0;
	pilesize = pilesizes->pa;
	bit_index_max = decimal_to_bits(max_number_value(pilea, pilesize));
	while (i < bit_index_max)
	{
		while (j++ < pilesize)
			push_and_rotate(pilea, pileb, i, pilesizes);
		while (pilesizes->pb > 0)
		{
			pa(pilea, pileb, pilesizes->pa, pilesizes->pb);
			pilesizes->pb -= 1;
			pilesizes->pa += 1;
			ft_printf("pa\n");
		}
		j = 0;
		i++;
	}
}
