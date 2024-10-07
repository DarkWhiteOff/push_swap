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

void	handle_argc_2(int *pilea, char *str, int pilesize)
{
	int		i;
	char	**array;

	i = 0;
	array = ft_split(str, ' ');
	while (i < pilesize)
	{
		pilea[i] = ft_atoi(array[i]);
		i++;
	}
	free_array(array, pilesize);
}

void	handle_argc(int *pilea, char **argv, int pilesize)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (i < pilesize)
	{
		pilea[i] = ft_atoi(argv[k]);
		i++;
		k++;
	}
}

int	main(int argc, char *argv[])
{
	t_pszab	psz;
	int		*pa;
	int		*pb;
	int		*pileacpy;

	if (argc < 2)
		return (0);
	check_args(argc, argv, &psz);
	pa = malloc(sizeof(int) * psz.pa);
	pb = malloc(sizeof(int) * psz.pa);
	pileacpy = malloc(sizeof(int) * psz.pa);
	if (argc == 2 && is_there_space(argv[1]) == 1)
		handle_argc_2(pa, argv[1], psz.pa);
	if (argc > 2)
		handle_argc(pa, argv, psz.pa);
	if (sorted(pa, psz.pa) == 1 && pa[0] != min(pa, psz.pa) && psz.pa <= 5)
		pile_almost_sorted(pa, pb, pileacpy, psz.pa);
	sort_and_assign(pa, pileacpy, psz.pa);
	free(pileacpy);
	if (psz.pa <= 5)
		sort_small_pile(pa, pb, &psz);
	bit_and_set(pa, pb, &psz);
	free(pa);
	free(pb);
	return (0);
}
