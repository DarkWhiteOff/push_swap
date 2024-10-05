#include "push_swap.h"

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
	int	pilesize;
	int	*pilea;
	int	*pileb;
	int	*pileacpy;

	pilesize = 0;
	if (argc < 2)
		return (ft_printf("Error\n", 0));
	pilesize = check_args(argc, argv);
	pilea = malloc(sizeof(int) * pilesize);
	pileb = malloc(sizeof(int) * pilesize);
	pileacpy = malloc(sizeof(int) * pilesize);
	if (argc == 2 && is_there_space(argv[1]) == 1)
		handle_argc_2(pilea, argv[1], pilesize);
	if (argc > 2)
		handle_argc(pilea, argv, pilesize);
	if (pile_is_sorted(pilea, pilesize) == 1 && pilea[0] != min_number_value(pilea, pilesize) && pilesize <= 5)
		check_pile_almost_sorted(pilea, pileb, pileacpy, pilesize);
	sort_and_assign(pilea, pileacpy, pilesize);
	free(pileacpy);
	print_piles(pilea, pileb, pilesize, 0);
	if (pilesize <= 5)
		sort_small_pile(pilea, pileb, pilesize);
	bit_and_set(pilea, pileb, pilesize);
	free(pilea);
	free(pileb);
	return (0);
}

void    print_piles(int *pilea, int *pileb, int pilesizeofa, int pilesizeofb)
{
	int r = 0;
	ft_printf("\n");
	ft_printf("Pile a\n");
	while (r < pilesizeofa)
	{
		ft_printf("%d\n", pilea[r]);
		r++;
	}
	r = 0;
	ft_printf("Pile b\n");
	while (r < pilesizeofb)
	{
		ft_printf("%d\n", pileb[r]);
		r++;
	}
	ft_printf("\n");
}