/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:22:32 by zamgar            #+#    #+#             */
/*   Updated: 2024/10/06 14:22:34 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_rb(int *pilex, int pilesize)
{
	int	i;
	int	temp;

	i = 0;
	temp = pilex[i];
	while (i < pilesize - 1)
	{
		pilex[i] = pilex[i + 1];
		i++;
	}
	pilex[i] = temp;
}

void	rr(int *pilea, int *pileb, int pilesize)
{
	ra_rb(pilea, pilesize);
	ra_rb(pileb, pilesize);
}

void	rra_rrb(int *pilex, int pilesize)
{
	int	temp;

	pilesize = pilesize - 1;
	temp = pilex[pilesize];
	while (pilesize > 0)
	{
		pilex[pilesize] = pilex[pilesize - 1];
		pilesize--;
	}
	pilex[0] = temp;
}

void	rrr(int *pilea, int *pileb, int pilesize)
{
	rra_rrb(pilea, pilesize);
	rra_rrb(pileb, pilesize);
}
