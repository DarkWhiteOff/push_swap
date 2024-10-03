#include "push_swap.h"

void    actualise_pile(int *pilex, char push_unspuh, int pilesize)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (push_unspuh == 'p')
    {
        i = pilesize - 1;
        while (i >= j)
        {
            pilex[i + 1] = pilex[i];
            i--;
        }
    }
    if (push_unspuh == 'u')
    {
        while (j < pilesize - 1)
        {
            pilex[j] = pilex[j + 1];
            j++;
        }
        pilex[j] = 0;
    }
}

void    pb_pa(int *pilea, int  *pileb, char pb_pa, int pilesizeofa, int pilesizeofb)
{
    if (pb_pa == 'b' && pilesizeofa > 0)
    {
        if (pilesizeofb > 0)
            actualise_pile(pileb, 'p', pilesizeofb);
        pileb[0] = pilea[0];
        actualise_pile(pilea, 'u', pilesizeofa);
    }
    else if (pb_pa == 'a' && pilesizeofb > 0)
    {
        if (pilesizeofa > 0)
            actualise_pile(pilea, 'p', pilesizeofa);
        pilea[0] = pileb[0];
        actualise_pile(pileb, 'u', pilesizeofb);
    }
}