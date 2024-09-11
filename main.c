#include "push_swap.h"

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

// Creation des fonctions sa/b ss pa/b ra/b rr rra/b rrr
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
    if (str == "pb")
    {
        if (pileb[1])
            actualise_pile(pileb, "push");
        pileb[1] = pilea[1];
        actualise_pile(pilea, "unpush");
    }
    if (str == "pa")
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
    while (j < i)
    {
        ft_printf("%d\n", pilea[j]);
        j++;
    }
    j = 1;
    ft_printf("Pile b\n");
    while (j < i)
    {
        ft_printf("%d\n", pileb[j]);
        j++;
    }
    //verif
    ft_printf("\nTesting\n");
    pb_pa(pilea, pileb, "pb");
    pb_pa(pilea, pileb, "pb");
    pb_pa(pilea, pileb, "pb");
    pb_pa(pilea, pileb, "pb");
    pb_pa(pilea, pileb, "pb");
    pb_pa(pilea, pileb, "pb");
    pb_pa(pilea, pileb, "pb");
    j = 1;
    ft_printf("Pile a\n");
    while (j < i)
    {
        ft_printf("%d\n", pilea[j]);
        j++;
    }
    j = 1;
    ft_printf("Pile b\n");
    while (j < i)
    {
        ft_printf("%d\n", pileb[j]);
        j++;
    }
    ft_printf("Testing\n");
    free(pilea);
    free(pileb);
    return (0);
}
