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

void	sa_sb(int *pilex, int pilesize)
{
	int	temp;

	temp = 0;
	if (pilesize >= 1)
	{
		temp = pilex[0];
		pilex[0] = pilex[1];
		pilex[1] = temp;
	}
}

void	ss(int *pilea, int *pileb, int pilesize)
{
	sa_sb(pilea, pilesize);
	sa_sb(pileb, pilesize);
}
