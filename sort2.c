#include "push_swap.h"

int	ft_strbitlen(char *octet)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (octet[j] != '1' && octet[j] != '\0')
		j++;
	while (octet[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

int	decimal_to_bits(int max_value)
{
	int		i;
	int		j;
	char	*octet;

	i = 31;
	j = 0;
	octet = malloc (sizeof(char) * 33);
	while (i >= 0)
	{
		octet[j] = (max_value >> i & 1) + '0';
		i--;
		j++;
	}
	octet[j] = '\0';
	i = ft_strbitlen(octet);
	free(octet);
	return (i);
}

void	push_and_rotate(int *pilea, int *pileb, int i, int *pilesizeofa, int *pilesizeofb)
{
	if ((pilea[0] >> i & 1) == 0)
	{
		pb_pa(pilea, pileb, 'b', *pilesizeofa, *pilesizeofb);
		(*pilesizeofa) -= 1;
		(*pilesizeofb) += 1;
		ft_printf("pb\n");
	}
	else
	{
		ra_rb(pilea, *pilesizeofa);
		ft_printf("ra\n");
	}
}

void	bit_and_set(int *pilea, int *pileb, int pilesize)
{
	int	i;
	int	j;
	int	bit_index_max;
	int	pilesizeofa;
	int	pilesizeofb;

	i = 0;
	j = 0;
	bit_index_max = decimal_to_bits(max_number_value(pilea, pilesize));
	pilesizeofa = pilesize;
	pilesizeofb = 0;
	while (i < bit_index_max)
	{
		while (j++ < pilesize)
			push_and_rotate(pilea, pileb, i, &pilesizeofa, &pilesizeofb);
		while (pilesizeofb > 0)
		{
			pb_pa(pilea, pileb, 'a', pilesizeofa, pilesizeofb);
			pilesizeofb -= 1;
			pilesizeofa += 1;
			ft_printf("pa\n");
		}
		j = 0;
		i++;
	}
}
