/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_pilesize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:53:27 by zamgar            #+#    #+#             */
/*   Updated: 2024/10/07 13:53:28 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_pilesize_3(int *pilea, int *pileb)
{
	if (pilea[0] == 1 && pilea[1] == 3 && pilea[2] == 2)
		ft_printf("sa\nra\n");
	else if (pilea[0] == 2 && pilea[1] == 1 && pilea[2] == 3)
		ft_printf("sa\n");
	else if (pilea[0] == 3 && pilea[1] == 2 && pilea[2] == 1)
		ft_printf("sa\nrra\n");
	free(pilea);
	free(pileb);
	exit(0);
}

void	push_nb(int *pilea, int *pileb, t_pszab *pilesizes, int index)
{
	int	nb_index;

	nb_index = search_nb_index(pilea, pilesizes->pa, index);
	while (pilea[0] != index)
	{
		if (nb_index <= pilesizes->pa / 2)
		{
			ra_rb(pilea, pilesizes->pa);
			ft_printf("ra\n");
		}
		else
		{
			rra_rrb(pilea, pilesizes->pa);
			ft_printf("rra\n");
		}
	}
	pb(pilea, pileb, pilesizes->pa, pilesizes->pb);
	pilesizes->pa--;
	ft_printf("pb\n");
}

void	sort_pilesize_4_5(int *pilea)
{
	if (pilea[0] == 1 && pilea[1] == 3 && pilea[2] == 2)
		ft_printf("sa\nra\n");
	else if (pilea[0] == 2 && pilea[1] == 1 && pilea[2] == 3)
		ft_printf("sa\n");
	else if (pilea[0] == 2 && pilea[1] == 3 && pilea[2] == 1)
		ft_printf("rra\n");
	else if (pilea[0] == 3 && pilea[1] == 1 && pilea[2] == 2)
		ft_printf("ra\n");
	else if (pilea[0] == 3 && pilea[1] == 2 && pilea[2] == 1)
		ft_printf("sa\nrra\n");
}

void	sort_small_pile(int *pilea, int *pileb, t_pszab *pilesizes)
{
	if (pilesizes->pa == 3)
		sort_pilesize_3(pilea, pileb);
	if (pilesizes->pa == 4)
	{
		push_nb(pilea, pileb, pilesizes, 4);
		sort_pilesize_4_5(pilea);
		ft_printf("pa\n");
		ft_printf("ra\n");
		free(pilea);
		free(pileb);
		exit(0);
	}
	if (pilesizes->pa == 5)
	{
		push_nb(pilea, pileb, pilesizes, 4);
		push_nb(pilea, pileb, pilesizes, 5);
		sort_pilesize_4_5(pilea);
		ft_printf("pa\n");
		ft_printf("pa\n");
		ft_printf("ra\n");
		ft_printf("ra\n");
		free(pilea);
		free(pileb);
		exit(0);
	}
}
