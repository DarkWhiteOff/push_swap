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

int pile_size(int *pilex)
{
    int i;
    int size = 0;

    i = 0;
    while (pilex[i + 1] != 0)
    {
        i++;
        size++;
    }
    return (size);
}

// Fonctions sa/b ss pa/b ra/b rr rra/b rrr
void    sa_sb(int *pilex, int pilesize)
{
    int temp;

    temp = 0;
    if (pilesize >= 2)
    {
        temp = pilex[1];
        pilex[1] = pilex[2];
        pilex[2] = temp;
    }
}

void    ss(int  *pilea, int *pileb, int pilesize)
{
    sa_sb(pilea, pilesize);
    sa_sb(pileb, pilesize);
}

void    pb_pa(int *pilea, int  *pileb, char *str)
{
    if (str == "pb" && pile_size(pilea) > 0)
    {
        if (pileb[1])
            actualise_pile(pileb, "push");
        pileb[1] = pilea[1];
        actualise_pile(pilea, "unpush");
    }
    if (str == "pa" && pile_size(pileb) > 0)
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

void    rra_rrb(int *pilex)
{
    int i;
    int j;
    int temp;

    i = 1;
    j = 0;
    temp = 0;
    while (pilex[i])
    {
        j++;
        i++;
    }
    i = 1;
    temp = pilex[j];
    while (j > i)
    {
        pilex[j] = pilex[j - 1];
        j--;
    }
    pilex[1] = temp;
}

void    rrr(int *pilea, int *pileb)
{
    rra_rrb(pilea);
    rra_rrb(pileb);
}

// Fonction qui permet de trouver la facon la plus courte de trier la pile
/* void    set_finder(int *pilea, int *pileb)
{
    int N;
    int swappable_index;
    int swappable_value;

    N = pile_size(pilea);
    swappable_index = 0;
    swappable_value = 0;
    if(pile_is_sorted(pilea) == 1)
    {
        if (pilea[1] == min_number_value(pilea))
            return ;
        else
        {
            if (min_number_index(pilea) <= N / 2)
            {
                // rotate pilea while (pile[1] != min_number_value)
            }
            else
            {
                // rotate pilea while (pile[1] != min_number_value)
            }
        }
    }
    else if (pile_is_sorted(pilea) == 0)
    {
        swappable_index = find_swappable_index(pilea);
        swappable_value = pile[swappable_index];
        if (swappable_index <= N / 2)
        {
            // rotate pilea while (pile[1] != swappable_value)
        }
        else
        {
            // rotate pilea while (pile[1] != swappable_value)
        }
        //swap pilea
    }
} */

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

    i = pilesize;
    min_nb = pilea[i];
    min_index = 0;
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
    return (i);
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
    i = pilesize - 1;
    while (pilex[0] != min_number_value(pilex, pilesize))
        ra_rb(pilex, pilesize);
    while (pilesize >= 0)
    {
        while(i >= 0)
        {
            if (pilex[pilesize] < pilex[i])
                swap_index = i;
            i--;
        }
        pilesize--;
        if (pilesize != 0)
            i = pilesize - 1;
    }
    while (pilea[swap_index2] != pilex[swap_index])
        swap_index2++;
    free(pilex);
    return (swap_index2);
}

void    set_finder_v2(int *pilea, int *pileb, int pilesize)
{
    int swappable_index;
    int swappable_value;
    int i;

    swappable_index = 0;
    swappable_value = 0;
    i = 0;
    ft_printf("Pile a avant\n");
    while (i < pilesize)
    {
        ft_printf("%d\n", pilea[i]);
        i++;
    }
    while (pile_is_sorted(pilea, pilesize) == 0)//
    {
        ft_printf("pile is not sorted");
        swappable_index = find_swappable_index(pilea, pilesize);
        free(pilea);
        free(pileb);
        exit(0);
        swappable_value = pilea[swappable_index];
        if (swappable_index <= pilesize / 2)
        {
            while (pilea[0] != swappable_value)
                ra_rb(pilea, pilesize);
        }
        else
        {
            while (pilea[0] != swappable_value)
                rra_rrb(pilea);
        }
        sa_sb(pilea, pilesize);
    }
//
    if (pile_is_sorted(pilea, pilesize) == 1)
    {
        if (pilea[0] == min_number_value(pilea, pilesize))
            return ;
        else
        {
            if (min_number_index(pilea, pilesize) <= pilesize / 2)
            {
                while (pilea[1] != min_number_value(pilea, pilesize))
                    ra_rb(pilea, pilesize);
            }
            else
            {
                while (pilea[1] != min_number_value(pilea, pilesize))
                    rra_rrb(pilea);
            }
        }
    }
    i = 0;
    ft_printf("Pile a apres\n");
    while (i < pilesize)
    {
        ft_printf("%d\n", pilea[i]);
        i++;
    }
    free(pilea);
    free(pileb);
    exit(0);
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
    //verif
    ft_printf("\nTesting\n");
    //instructions
    set_finder_v2(pilea, pileb, pilesize);
    //instructions
    i = 0;
    ft_printf("Pile a après\n");
    while (i < pilesize)
    {
        ft_printf("%d\n", pilea[i]);
        i++;
    }
    ft_printf("Testing\n");
    free(pilea);
    free(pileb);
    return (0);
}


// PYTHON TUTOR
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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
    while (pilesize >= 0)
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
    free(pilea);
    free(pilex);
    exit(0);
    free(pilex);
    return (1);
}

int    ft_atoi(const char *str)
{
    int    i;
    int    nbr;
    int    sign;

    i = 0;
    nbr = 0;
    sign = 1;
    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + str[i] - '0';
        i++;
    }
    return (nbr * sign);
}

int     main(int argc, char *argv[])
{
    int     i = 1;
    int     j = 0;
    int k = 1;
    int     *pilea;
    int     *pileb;
    int     pilesize = 5;

    pilea = malloc(sizeof(int) * pilesize);
    pileb = malloc(sizeof(int) * pilesize);
    argv[1] = "4";
    argv[2] = "5";
    argv[3] = "1";
    argv[4] = "2";
    argv[5] = "3";
    i = 0;
    while (i < pilesize)
    {
        pilea[i] = ft_atoi(argv[k]);
        i++;
        k++;
    }
    printf("%d\n", pile_is_sorted(pilea, pilesize));
    return (0);
}
