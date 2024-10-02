#include "push_swap.h"

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

void    rotate_pile(int *pileacpy, int pilesize, int check)
{
    if (pile_is_sorted(pileacpy, pilesize) == 1)
    {
        if (pileacpy[0] == min_number_value(pileacpy, pilesize))
            return ;
        else
        {
            if (min_number_index(pileacpy, pilesize) <= pilesize / 2)
            {
                while (pileacpy[0] != min_number_value(pileacpy, pilesize))
                {
                    ra_rb(pileacpy, pilesize);
                    if (check == 1)
                        ft_printf("ra\n");
                }
            }
            else
            {
                while (pileacpy[0] != min_number_value(pileacpy, pilesize))
                {
                    rra_rrb(pileacpy, pilesize);
                    if (check == 1)
                        ft_printf("rra\n");
                }
            }
        }
    }
    return ;
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

void    sort(int *pileacpy, int pilesize, int check)
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
            {
                ra_rb(pileacpy, pilesize);
                if (check == 1)
                    ft_printf("ra\n");
            }
        }
        else
        {
            while (pileacpy[0] != swappable_value)
            {
                rra_rrb(pileacpy, pilesize);
                if (check == 1)
                    ft_printf("rra\n");
            }
        }
        sa_sb(pileacpy, pilesize);
        if (check == 1)
            ft_printf("sa\n");
    }
    rotate_pile(pileacpy, pilesize, check);
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
    sort(pileacpy, pilesize, 0);
    i = 0;
    while (i < pilesize)
    {
        while (j < pilesize)
        {
            if (pilea[i] == pileacpy[j])
            {
                pilea[i] = j + 1;
                break ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}