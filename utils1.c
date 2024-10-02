#include "push_swap.h"

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

int search_nb_index(int *pilea, int pilesize, int tosearch)
{
    int i;
   
    i = 0;
    while (i < pilesize)
    {
        if (pilea[i] == tosearch)
            return (i);
        i++;
    }
    return (-1);
}