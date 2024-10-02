#include "push_swap.h"

void    actualise_pile(int *pilex, char *str, int pilesize)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str == "push")
    {
        i = pilesize - 1;
        while (i >= j)
        {
            pilex[i + 1] = pilex[i];
            i--;
        }
    }
    if (str == "unpush")
    {
        while (j < pilesize - 1)
        {
            pilex[j] = pilex[j + 1];
            j++;
        }
        pilex[j] = 0;
    }
}

void    pb_pa(int *pilea, int  *pileb, char *str, int pilesizeofa, int pilesizeofb)
{
    if (str == "pb" && pilesizeofa > 0)
    {
        if (pilesizeofb > 0)
            actualise_pile(pileb, "push", pilesizeofb);
        pileb[0] = pilea[0];
        actualise_pile(pilea, "unpush", pilesizeofa);
    }
    if (str == "pa" && pilesizeofb > 0)
    {
        if (pilesizeofa > 0)
            actualise_pile(pilea, "push", pilesizeofa);
        pilea[0] = pileb[0];
        actualise_pile(pileb, "unpush", pilesizeofb);
    }
}