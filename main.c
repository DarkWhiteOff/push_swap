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
        ft_printf("taille pile : %d\n", j);
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
        ft_printf("taille pile : %d\n", j);
        i = 1;
        while (i < j)
        {
            pilex[i] = pilex[i + 1];
            i++;
        }
        pilex[i] = 0;
        if (pilex[i])
            ft_printf("caca");
    }
}

// Creation des fonctions sa/b ss pa/b ra/b rr rra/b rrr
void    sa_sb(int *pilex)
{
    int temp;

    temp = pilex[1];
    pilex[1] = pilex[2];
    pilex[2] = temp;
}

void    ss(int  *pilea, int *pileb)
{
    int temp;

    temp = pilea[1];
    pilea[1] = pilea[2];
    pilea[2] = temp;

    temp = pileb[1];
    pileb[1] = pileb[2];
    pileb[2] = temp;
}

void    pb(int *pilea, int  *pileb)
{
    if (pileb[1])
        actualise_pile(pileb, "push");
    pileb[1] = pilea[1];
    actualise_pile(pilea, "unpush");
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
    pileb[1] = 3;
    pileb[2] = 1;
    pileb[3] = 2;
    while (j < i)
    {
        ft_printf("%d\n", pileb[j]);
        j++;
    }
    //verif
    ft_printf("\nTesting\n");
    //sa_sb(pilea);
    //ss(pilea, pileb);
    pb(pilea, pileb);
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
    ft_printf("\nTesting\n");
    free(pilea);
    free(pileb);
    return (0);
}
