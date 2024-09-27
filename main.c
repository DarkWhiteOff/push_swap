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

int find_swappable_index(int *pilea, int pilesize)
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
        pilex[i] = pilea[i];
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
                while (pilea[swap_index2] != pilex[swap_index])
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

void    set_finder_v2(int *pilea, int *pileb, int pilesize)
{
    int swappable_index;
    int swappable_value;
    int i;

    swappable_index = 0;
    swappable_value = 0;
    while (pile_is_sorted(pilea, pilesize) == 0)
    {
        swappable_index = find_swappable_index(pilea, pilesize);
        swappable_value = pilea[swappable_index];
        if (swappable_index <= pilesize / 2)
        {
            while (pilea[0] != swappable_value)
            {
                ra_rb(pilea, pilesize);
                ft_printf("ra\n");
            }
        }
        else
        {
            while (pilea[0] != swappable_value)
            {
                rra_rrb(pilea, pilesize);
                ft_printf("rra\n");
            }
        }
        sa_sb(pilea, pilesize);
        ft_printf("sa\n");
    }
    if (pile_is_sorted(pilea, pilesize) == 1)
    {
        if (pilea[0] == min_number_value(pilea, pilesize))
            return ;
        else
        {
            if (min_number_index(pilea, pilesize) <= pilesize / 2)
            {
                while (pilea[0] != min_number_value(pilea, pilesize))
                {
                    ra_rb(pilea, pilesize);
                    ft_printf("ra\n");
                }
            }
            else
            {
                while (pilea[0] != min_number_value(pilea, pilesize))
                {
                    rra_rrb(pilea, pilesize);
                    ft_printf("rra\n");
                }
            }
        }
    }
    return ;
}

// Main
int     main(int argc, char *argv[])
{
    int     i = 1;
    int     pilesize = 0;
    int k = 1;
    int     *pilea;
    int     *pileb;

    while (argv[i++])
        pilesize++;
    pilea = malloc(sizeof(int) * pilesize);
    pileb = malloc(sizeof(int) * pilesize);
    i = 0;
    while (i < pilesize)
    {
        pilea[i] = ft_atoi(argv[k]);
        i++;
        k++;
    }
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
    set_finder_v2(pilea, pileb, pilesize);
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