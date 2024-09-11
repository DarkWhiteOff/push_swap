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
    return (j);
}

// Fonctions sa/b ss pa/b ra/b rr rra/b rrr
void    sa_sb(int *pilex)
{
    int temp;

    temp = 0;
    if (pile_size(pilex) >= 2)
    {
        temp = pilex[1];
        pilex[1] = pilex[2];
        pilex[2] = temp;
    }
}

void    ss(int  *pilea, int *pileb)
{
    sa_sb(pilea);
    sa_sb(pileb);
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

void    ra_rb(int *pilex)
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
    temp = pilex[i];
    while (i < j)
    {
        pilex[i] = pilex[i + 1];
        i++;
    }
    pilex[i] = temp;
}

void    rr(int *pilea, int *pileb)
{
    ra_rb(pilea);
    ra_rb(pileb);
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

int pile_is_sorted()
{
    
}

void    set_finder_v2(int *pilea, int *pileb)
{
    int N;
    int swappable_index;
    int swappable_value;

    N = pile_size(pilea);
    swappable_index = 0;
    swappable_value = 0;
    while (pile_is_sorted(pilea) == 0)
    {
        swappable_index = find_swappable_index(pilea);
        swappable_value = pile[swappable_index];
        if (swappable_index <= N / 2)
        {
            while (pile[1] != swappable_value)
                ra_rb(pilea);
        }
        else
        {
            while (pile[1] != swappable_value)
                rra_rrb(pilea);
        }
        sa_sb(pilea);
    }
    if(pile_is_sorted(pilea) == 1)
    {
        if (pilea[1] == min_number_value(pilea))
            return ;
        else
        {
            if (min_number_index(pilea) <= N / 2)
            {
                while (pile[1] != min_number_value(pilea))
                    ra_rb(pilea);
            }
            else
            {
                while (pile[1] != min_number_value(pilea))
                    rra_rrb(pilea);
            }
        }
    }
    return ;
}

// Main
int     main(int argc, char *argv[])
{
    int     i = 1;
    int     j = 0;
    int     *pilea;
    int     *pileb;

    while (argv[i])
        i++;                                //calcul du nombre d'elements
    pilea = malloc(sizeof(int*) * i);
    pileb = malloc(sizeof(int*) * i);      //malloc
    while (j < i)
    {
        pilea[j] = ft_atoi(argv[j]);
        j++;
    }                                      //remplissage pile a
    //verif
    j = 1;
    ft_printf("Pile a\n");
    while (j - 1 < pile_size(pilea))
    {
        ft_printf("%d\n", pilea[j]);
        j++;
    }
    j = 1;
    ft_printf("Pile b\n");
    while (j - 1 < pile_size(pileb))
    {
        ft_printf("%d\n", pileb[j]);
        j++;
    }
    //verif
    ft_printf("\nTesting\n");
    //instructions
    set_finder(pilea, pileb);;
    //instructions
    j = 1;
    ft_printf("Pile a\n");
    while (j - 1 < pile_size(pilea))
    {
        ft_printf("%d\n", pilea[j]);
        j++;
    }
    j = 1;
    ft_printf("Pile b\n");
    while (j - 1 < pile_size(pileb))
    {
        ft_printf("%d\n", pileb[j]);
        j++;
    }
    ft_printf("Testing\n");
    free(pilea);
    free(pileb);
    return (0);
}
