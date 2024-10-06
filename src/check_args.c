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

void	check_chars(char **tab, int pilesize, int check)
{
	int	i;
	int	j;

	i = check;
	j = 0;
	while (tab[i])
	{
		if ((tab[i][j] == '-' || tab[i][j] == '+') && (tab[i][j + 1] != '\0'))
			j++;
		while (tab[i][j])
		{
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
			{
				ft_printf("Error\n");
				if (check == 0)
					free_array(tab, pilesize);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

int	dbs(int *pilea, int pilesize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pilesize)
	{
		while (j < pilesize)
		{
			if ((pilea[i] == pilea[j]) && (i != j))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	check_doubles(char **array, int psz, int check)
{
	int	*p;
	int	i;
	int	j;

	i = check;
	j = 0;
	p = malloc(sizeof(int) * psz);
	while (j < psz)
	{
		p[j] = ft_atoi(array[i]);
		i++;
		j++;
	}
	if ((dbs(p, psz) == 0) || (sorted(p, psz) == 1 && p[0] == min(p, psz)))
	{
		if (dbs(p, psz) == 0)
			ft_printf("Error\n");
		if (check == 0)
			free_array(array, psz);
		free(p);
		exit(0);
	}
	free(p);
	return ;
}

void	check_big_nb(char **array, int pilesize, int check)
{
	int		i;
	int		j;
	size_t	*pilea;

	i = check;
	j = 0;
	pilea = malloc(sizeof(size_t) * pilesize);
	while (j < pilesize)
		pilea[j++] = ft_atoi(array[i++]);
	i = 0;
	while (i < pilesize)
	{
		if (pilea[i] > (size_t)2147483647 && pilea[i] < (size_t) - 2147483648)
		{
			ft_printf("Error\n");
			if (check == 0)
				free_array(array, pilesize);
			free(pilea);
			exit(0);
		}
		i++;
	}
	free(pilea);
	return ;
}

void	check_args(int argc, char **argv, t_pszab *pilesizes)
{
	char	**array;
	int		i;

	pilesizes->pa = 0;
	if (argc == 2 && is_there_space(argv[1]) == 1)
	{
		i = 0;
		array = ft_split(argv[1], ' ');
		while (array[i++])
			pilesizes->pa++;
		check_chars(array, pilesizes->pa, 0);
		check_big_nb(array, pilesizes->pa, 0);
		check_doubles(array, pilesizes->pa, 0);
		free_array(array, pilesizes->pa);
	}
	else if (argc >= 2)
	{
		i = 1;
		while (argv[i++])
			pilesizes->pa++;
		check_chars(argv, pilesizes->pa, 1);
		check_big_nb(argv, pilesizes->pa, 1);
		check_doubles(argv, pilesizes->pa, 1);
	}
	pilesizes->pb = 0;
}
