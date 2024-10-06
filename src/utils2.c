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

int	is_there_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	free_array(char **array, int pilesize)
{
	while (pilesize >= 0)
	{
		free(array[pilesize]);
		pilesize--;
	}
	free(array);
}

void	pile_almost_sorted(int *pilea, int *pileb, int *pileacpy, int pilesize)
{
	rotate_pile(pilea, pilesize, 1);
	free(pilea);
	free(pileb);
	free(pileacpy);
	exit(0);
}

int	*ft_pilecpy(int *newpile, int *pile, int pilesize)
{
	int	i;

	i = 0;
	while (i < pilesize)
	{
		newpile[i] = pile[i];
		i++;
	}
	return (newpile);
}

void	while_rotate(int *pilex, int pilesize)
{
	while (pilex[0] != min(pilex, pilesize))
		ra_rb(pilex, pilesize);
}
