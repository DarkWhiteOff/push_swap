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

int	sorted(int *pilea, int pilesize)
{
	int	i;
	int	*pilex;

	i = 0;
	pilex = malloc(sizeof(int) * pilesize);
	pilex = ft_pilecpy(pilex, pilea, pilesize);
	while (pilex[0] != min(pilex, pilesize))
		ra_rb(pilex, pilesize);
	pilesize = pilesize - 1;
	i = pilesize - 1;
	while (pilesize > 0)
	{
		while (i >= 0)
		{
			if (pilex[pilesize] < pilex[i])
				return (free(pilex), 0);
			i--;
		}
		pilesize--;
		if (pilesize != 0)
			i = pilesize - 1;
	}
	return (free(pilex), 1);
}

void	rotate_pile(int *pileacpy, int pilesize, int check)
{
	if (pileacpy[0] == min(pileacpy, pilesize))
		return ;
	else
	{
		if (min_number_index(pileacpy, pilesize) <= pilesize / 2)
		{
			while (pileacpy[0] != min(pileacpy, pilesize))
			{
				ra_rb(pileacpy, pilesize);
				if (check == 1)
					ft_printf("ra\n");
			}
		}
		else
		{
			while (pileacpy[0] != min(pileacpy, pilesize))
			{
				rra_rrb(pileacpy, pilesize);
				if (check == 1)
					ft_printf("rra\n");
			}
		}
	}
	return ;
}

int	find_swappable_index(int *pileacpy, int pilesize)
{
	int	i;
	int	swap_index;
	int	*pilex;

	swap_index = 0;
	pilex = malloc(sizeof(int) * pilesize);
	pilex = ft_pilecpy(pilex, pileacpy, pilesize);
	while_rotate(pilex, pilesize);
	vars_init(&pilesize, &i);
	while (pilesize > 0)
	{
		while (i >= 0)
		{
			if (pilex[pilesize] < pilex[i])
			{
				while (pileacpy[swap_index] != pilex[i])
					swap_index++;
				return (free(pilex), swap_index);
			}
			i--;
		}
		pilesize--;
		i = pilesize - 1;
	}
	return (swap_index);
}

void	sort(int *pileacpy, int pilesize)
{
	int	swappable_index;
	int	swappable_value;

	swappable_index = 0;
	swappable_value = 0;
	while (sorted(pileacpy, pilesize) == 0)
	{
		swappable_index = find_swappable_index(pileacpy, pilesize);
		swappable_value = pileacpy[swappable_index];
		if (swappable_index <= pilesize / 2)
		{
			while (pileacpy[0] != swappable_value)
				ra_rb(pileacpy, pilesize);
		}
		else
		{
			while (pileacpy[0] != swappable_value)
				rra_rrb(pileacpy, pilesize);
		}
		sa_sb(pileacpy, pilesize);
	}
	rotate_pile(pileacpy, pilesize, 0);
	return ;
}

void	sort_and_assign(int *pilea, int *pileacpy, int pilesize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pilesize)
	{
		pileacpy[i] = pilea[i];
		i++;
	}
	sort(pileacpy, pilesize);
	i = 0;
	while (i < pilesize)
	{
		while (j < pilesize)
		{
			if (pilea[i] == pileacpy[j])
			{
				pilea[i++] = j + 1;
				break ;
			}
			j++;
		}
		j = 0;
	}
}
