# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

void    actualise_pile(int *pilex, char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str == "push")
    {
        while (pilex[i])
            i++;
        i = i - 1;
        while (i >= j)
        {
            pilex[i + 1] = pilex[i];
            i--;
        }
    }
    if (str == "unpush")
    {
        while (pilex[i])
            i++;
        while (j < i)
        {
            pilex[j] = pilex[j + 1];
            j++;
        }
        pilex[j] = 0;
    }
}

int ft_pilesize(int *pilea)
{
    int i;

    i = 0;
    while (pilea[i])
        i++;
    return (i);
}

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
    if (str == "pb" && ft_pilesize(pilea) > 0)
    {
        if (pileb[0])
            actualise_pile(pileb, "push");
        pileb[0] = pilea[0];
        actualise_pile(pilea, "unpush");
    }
    if (str == "pa" && ft_pilesize(pileb) > 0)
    {
        if (pilea[0])
            actualise_pile(pilea, "push");
        pilea[0] = pileb[0];
        actualise_pile(pileb, "unpush");
    }
}

void    ra_rb(int *pilex, int pilesize)
{
    int i;
    int temp;

    i = 0;
    temp = pilex[i];
    while (i < ft_pilesize(pilex) - 1)
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

void    bit_and_set(int *pilea, int *pileb, int pilesize)
{
    int i;
    int j;
    int max_value;
    int bit_index_max;

    i = 0;
    j = 0;
    max_value = 7;
    bit_index_max = 3;
    while (i < bit_index_max)
    {
        while (j < pilesize)
        {
            if ((pilea[0] >> i & 1) == 0)
                pb_pa(pilea, pileb, "pb", pilesize);
            else
                ra_rb(pilea, pilesize);
            j++;
        }
        while (ft_pilesize(pileb) != 0)
            pb_pa(pilea, pileb, "pa", pilesize);
        j = 0;
        i++;
    }
}

void    print_piles(int *pilea, int *pileb, int pilesize)
{
    int r = 0;
        printf("Pile a\n");
        while (pilea[r])
        {
            printf("%d\n", pilea[r]);
            r++;
        }
        r = 0;
        printf("Pile b\n");
        while (pileb[r])
        {
            printf("%d\n", pileb[r]);
            r++;
        }
}

// Main
int     main(void)
{
    int     *pilea;
    int     *pileb;
    int pilesize;

    pilea = malloc(sizeof(int) * 7);
    pileb = malloc(sizeof(int) * 7);
    pilea[0] = 7;
    pilea[1] = 6;
    pilea[2] = 5;
    pilea[3] = 1;
    pilea[4] = 2;
    pilea[5] = 3;
    pilea[6] = 4;

    pileb[0] = 0;
    pileb[1] = 0;
    pileb[2] = 0;
    pileb[3] = 0;
    pileb[4] = 0;
    pileb[5] = 0;
    pileb[6] = 0;
    pilesize = ft_pilesize(pilea);

    print_piles(pilea, pileb, pilesize);
    printf("\n");
    //bit_and_set(pilea, pileb, pilesize);

    ra_rb(pilea, pilesize);
    pb_pa(pilea, pileb, "pb", pilesize);
    ra_rb(pilea, pilesize);
    ra_rb(pilea, pilesize);
    pb_pa(pilea, pileb, "pb", pilesize);
    ra_rb(pilea, pilesize);
    pb_pa(pilea, pileb, "pb", pilesize);

    print_piles(pilea, pileb, pilesize);

    free(pilea);
    free(pileb);
    return (0);
}

/*

7/
5   4
1   2
3   6

*/