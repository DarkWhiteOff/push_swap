/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:22:32 by zamgar            #+#    #+#             */
/*   Updated: 2024/10/06 14:22:34 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	actualise_pile(int *pilex, char push_unspuh, int pilesize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (push_unspuh == 'p')
	{
		i = pilesize - 1;
		while (i >= j)
		{
			pilex[i + 1] = pilex[i];
			i--;
		}
	}
	if (push_unspuh == 'u')
	{
		while (j < pilesize - 1)
		{
			pilex[j] = pilex[j + 1];
			j++;
		}
		pilex[j] = 0;
	}
}

void	pb(int *pilea, int *pileb, int pilesizeofa, int pilesizeofb)
{
	if (pilesizeofa > 0)
	{
		if (pilesizeofb > 0)
			actualise_pile(pileb, 'p', pilesizeofb);
		pileb[0] = pilea[0];
		actualise_pile(pilea, 'u', pilesizeofa);
	}
}

void	pa(int *pilea, int *pileb, int pilesizeofa, int pilesizeofb)
{
	if (pilesizeofb > 0)
	{
		if (pilesizeofa > 0)
			actualise_pile(pilea, 'p', pilesizeofa);
		pilea[0] = pileb[0];
		actualise_pile(pileb, 'u', pilesizeofb);
	}
}
