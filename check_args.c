#include "push_swap.h"

void    check_chars(char **array, int pilesize, int check)
{
    int i;
    int j;

    i = check;
    j = 0;
    while (array[i])
    {
        if ((array[i][j] == '-' || array[i][j] == '+') && (array[i][j + 1] != '\0'))
            j++;
        while (array[i][j])
        {
            if (!(array[i][j] >= '0' && array[i][j] <= '9'))
            {
                ft_printf("Error (other chars)\n");
                if (check == 0)
                    free_array(array, pilesize);
                exit(0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return ;
}

int handle_doubles(int *pilea, int pilesize)
{
    int i;
    int j;
    int actual_nb;

    i = 0;
    j = 0;
    actual_nb = 0;
    while (i < pilesize)
    {
        actual_nb = pilea[i];
        while (j < pilesize)
        {
            if ((pilea[i] == pilea[j]) && (i != j))
                return(0);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

void    check_doubles(char **array, int pilesize, int check)
{
    int *pilea;
    int i;
    int j;

    i = check;
    j = 0;
    pilea = malloc(sizeof(int) * pilesize);
    while (j < pilesize)
    {
        pilea[j] = ft_atoi(array[i]);
        i++;
        j++;
    }
    if ((handle_doubles(pilea, pilesize) == 0) || (pile_is_sorted(pilea, pilesize) == 1 && pilea[0] == min_number_value(pilea, pilesize)))
    {
        ft_printf("Error (double) or (pile already sorted)\n");
        if (check == 0)
            free_array(array, pilesize);
        free(pilea);
        exit (0);
    }
    free(pilea);
    return ;
}

int check_args(int argc, char **argv)
{
    char    **array;
    int i;
    int pilesize;

    pilesize = 0;
    if (argc == 2 && is_there_space(argv[1]) == 1)
    {
        i = 0;
        array = ft_split(argv[1], ' ');
        while (array[i++])
            pilesize++;
        check_chars(array, pilesize, 0);
        check_doubles(array, pilesize, 0);
        free_array(array, pilesize);
    }
    else if (argc >= 2)
    {
        i = 1;
        while (argv[i++])
            pilesize++;
        check_chars(argv, pilesize, 1);
        check_doubles(argv, pilesize, 1);
    }
    return (pilesize);
}