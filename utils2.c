#include "push_swap.h"

int is_there_space(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

void    free_array(char **array, int pilesize)
{
	while (pilesize >= 0)
	{
		free(array[pilesize]);
		pilesize--;
	}
    free(array);
}

void    check_pile_almost_sorted(int *pilea, int *pileb, int *pileacpy, int pilesize)
{
    rotate_pile(pilea, pilesize, 1);
    free(pilea);
    free(pileb);
    free(pileacpy);
    exit(0);
}