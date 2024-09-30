#include "push_swap.h"

// Fonctions utils
void    actualise_pile(int *pilex, char *str)
{
    int i;
    int j;
    int temp;

    i = 1;
    j = 0;
    temp = 0;
    if (str == "push")
    {
        while (pilex[i])
        {
            j++;
            i++;
        }
        i = 0;
        while (j > i)
        {
            pilex[j + 1] = pilex[j];
            j--;
        }
    }
    if (str == "unpush")
    {
        while (pilex[i])
        {
            j++;
            i++;
        }
        i = 1;
        while (i < j)
        {
            pilex[i] = pilex[i + 1];
            i++;
        }
        pilex[i] = 0;
    }
}

// Fonctions sa/b ss pa/b ra/b rr rra/b rrr
void    sa_sb(int *pilex, int pilesize)
{
    int temp;

    temp = 0;
    if (pilesize >= 1)
    {
        temp = pilex[0];
        pilex[0] = pilex[1];
        pilex[1] = temp;
    }
}

void    ss(int  *pilea, int *pileb, int pilesize)
{
    sa_sb(pilea, pilesize);
    sa_sb(pileb, pilesize);
}

void    pb_pa(int *pilea, int  *pileb, char *str, int pilesize)
{
    if (str == "pb" && pilesize > 0)
    {
        if (pileb[1])
            actualise_pile(pileb, "push");
        pileb[1] = pilea[1];
        actualise_pile(pilea, "unpush");
    }
    if (str == "pa" && pilesize > 0)
    {
        if (pilea[1])
            actualise_pile(pilea, "push");
        pilea[1] = pileb[1];
        actualise_pile(pileb, "unpush");
    }
}

void    ra_rb(int *pilex, int pilesize)
{
    int i;
    int temp;

    i = 0;
    temp = pilex[i];
    while (i < pilesize - 1)
    {
        pilex[i] = pilex[i + 1];
        i++;
    }
    pilex[i] = temp;
}

void    rr(int *pilea, int *pileb, int pilesize)
{
    ra_rb(pilea, pilesize);
    ra_rb(pileb, pilesize);
}

void    rra_rrb(int *pilex, int pilesize)
{
    int temp;

    pilesize = pilesize - 1;
    temp = pilex[pilesize];
    while (pilesize > 0)
    {
        pilex[pilesize] = pilex[pilesize - 1];
        pilesize--;
    }
    pilex[0] = temp;
}

void    rrr(int *pilea, int *pileb, int pilesize)
{
    rra_rrb(pilea, pilesize);
    rra_rrb(pileb, pilesize);
}

// fonctions pour trouver le set d'instructions
int min_number_value(int *pilea, int pilesize)
{
    int i;
    int min_nb;

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

int min_number_index(int *pilea, int pilesize)
{
    int i;
    int min_nb;
    int min_index;

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

int pile_is_sorted(int *pilea, int pilesize)
{
    int i;
    int *pilex;

    i = 0;
    pilex = malloc(sizeof(int) * pilesize);
    while (i < pilesize)
    {
        pilex[i] = pilea[i];
        i++;
    }
    while (pilex[0] != min_number_value(pilex, pilesize))
        ra_rb(pilex, pilesize);
    pilesize = pilesize - 1;
    i = pilesize - 1;
    while (pilesize > 0)
    {
        while(i >= 0)
        {
            if (pilex[pilesize] < pilex[i])
                return (free(pilex), 0);
            i--;
        }
        pilesize--;
        if (pilesize != 0)
            i = pilesize - 1;
    }
    free(pilex);
    return (1);
}

int find_swappable_index(int *pileacpy, int pilesize)
{
    int i;
    int *pilex;
    int swap_index;
    int swap_index2;

    i = 0;
    swap_index = 0;
    swap_index2 = 0;
    pilex = malloc(sizeof(int*) * pilesize);
    while (i < pilesize)
    {
        pilex[i] = pileacpy[i];
        i++;
    }
    while (pilex[0] != min_number_value(pilex, pilesize))
        ra_rb(pilex, pilesize);
    pilesize -= 1;
    i = pilesize - 1;
    while (pilesize > 0)
    {
        while(i >= 0)
        {
            if (pilex[pilesize] < pilex[i])
            {
                swap_index = i;
                while (pileacpy[swap_index2] != pilex[swap_index])
                    swap_index2++;
                free(pilex);
                return (swap_index2);
            }
            i--;
        }
        pilesize--;
        if (pilesize > 0)
            i = pilesize - 1;
    }
}

void    sort(int *pileacpy, int pilesize)
{
    int swappable_index;
    int swappable_value;
    int i;

    swappable_index = 0;
    swappable_value = 0;
    while (pile_is_sorted(pileacpy, pilesize) == 0)
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
    if (pile_is_sorted(pileacpy, pilesize) == 1)
    {
        if (pileacpy[0] == min_number_value(pileacpy, pilesize))
            return ;
        else
        {
            if (min_number_index(pileacpy, pilesize) <= pilesize / 2)
            {
                while (pileacpy[0] != min_number_value(pileacpy, pilesize))
                    ra_rb(pileacpy, pilesize);
            }
            else
            {
                while (pileacpy[0] != min_number_value(pileacpy, pilesize))
                    rra_rrb(pileacpy, pilesize);
            }
        }
    }
    return ;
}

void    sort_and_assign(int *pilea, int *pileacpy, int pilesize)
{
    int i;
    int j;

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
                pilea[i] = j;
                break ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

int	decimal_to_bits(int max_value)
{
	int	i;
	int	j;
    char    *octet;

	i = 7;
	j = 0;
    octet = malloc (sizeof(char) * 32);
	while (i >= 0)
	{
		octet[j] = (c >> i & 1) + '0';
		i--;
		j++;
	}
	octet[j] = '\0';
	return (octet);
}

int max_number_value(int *pilea, int pilesize)
{
    int i;
    int max_nb;

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

void    bit_and_set(int *pilea, int pilesize)
{
    int i;
    int max_value;
    int bit_index_max;

    i = 0;
    max_value = max_number_value(pilea, pilesize);
    bit_index_max = decimal_to_bits(max_value);
    /* while (i < pilesize)
    {
        
        i++;
    } */
}

// Main
int     main(int argc, char *argv[])
{
    int     i = 1;
    int     pilesize = 0;
    int k = 1;
    int     *pilea;
    int     *pileb;
    int *pileacpy;

    while (argv[i++])
        pilesize++;
    pilea = malloc(sizeof(int) * pilesize);
    pileb = malloc(sizeof(int) * pilesize);
    pileacpy = malloc(sizeof(int*) * pilesize);
    i = 0;
    while (i < pilesize)
    {
        pilea[i] = ft_atoi(argv[k]);
        i++;
        k++;
    }

    sort_and_assign(pilea, pileacpy, pilesize);
    bit_and_set(pilea, pilesize);
    free(pilea);
    free(pileb);
    free(pileacpy);
    exit(0);
    //verif
    i = 0;
    ft_printf("Pile a avant\n");
    while (i < pilesize)
    {
        ft_printf("%d\n", pilea[i]);
        i++;
    }
    ft_printf("\n");
    //verif

    //instructions
    //set_finder_v2(pilea, pileb, pilesize);
    //instructions

    //verif
    i = 0;
    ft_printf("Pile a après\n");
    while (i < pilesize)
    {
        ft_printf("%d\n", pilea[i]);
        i++;
    }
    //verif
    free(pilea);
    free(pileb);
    return (0);
}