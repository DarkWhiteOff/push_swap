/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:54:03 by zamgar            #+#    #+#             */
/*   Updated: 2024/10/07 13:54:04 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min(int *pilea, int pilesize)
{
	int	i;
	int	min_nb;

	i = pilesize - 1;
	min_nb = pilea[i];
	i = i - 1;
	while (i >= 0)
	{
		if (pilea[i] < min_nb)
			min_nb = pilea[i];
		i--;
	}
	return (min_nb);
}

int	min_number_index(int *pilea, int pilesize)
{
	int	i;
	int	min_nb;
	int	min_index;

	i = pilesize - 1;
	min_nb = pilea[i];
	min_index = i;
	i = i - 1;
	while (i >= 0)
	{
		if (pilea[i] < min_nb)
		{
			min_nb = pilea[i];
			min_index = i;
		}
		i--;
	}
	return (min_index);
}

int	max_number_value(int *pilea, int pilesize)
{
	int	i;
	int	max_nb;

	i = pilesize - 1;
	max_nb = pilea[i];
	i = i - 1;
	while (i >= 0)
	{
		if (pilea[i] > max_nb)
			max_nb = pilea[i];
		i--;
	}
	return (max_nb);
}

int	search_nb_index(int *pilea, int pilesize, int tosearch)
{
	int	i;

	i = 0;
	while (i < pilesize)
	{
		if (pilea[i] == tosearch)
			return (i);
		i++;
	}
	return (-1);
}

void	vars_init(int *pilesize, int *i)
{
	*pilesize -= 1;
	*i = *pilesize - 1;
}
