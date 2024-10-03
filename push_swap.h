#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

// Ft printf
int					ft_printf(const char *str, ...);
int					get_next_arg(va_list *ap, char c);
int					ft_dec_into_hex(unsigned int n, int b);
void				ft_print_array(char *array, int i);
char				*ft_fill_hexarray(unsigned int n, char *string,
						char *array);
int					ft_get_size_hexarray(unsigned int n);
int					ft_itoa2(int n);
char				*ft_itoa(int n);
char				*ft_min(char *str);
int					ft_count(int n);
int					ft_unsigned_itoa2(unsigned int n);
char				*ft_unsigned_itoa(unsigned int n);
int					ft_unsigned_count(unsigned int n);
int					ft_putptr(unsigned long long adress);
char				*ft_fill_ptrarray(unsigned long long adress,
						char *string, char *array);
int					ft_get_size_ptrarray(unsigned long long adress);
int					ft_putstr(char *str);
int					ft_putchar(char c);

// Libft
size_t					ft_atoi(const char *str);
int					ft_isspace(int c);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);

// Push swap
void    actualise_pile(int *pilex, char push_unspuh, int pilesize);
void    sa_sb(int *pilex, int pilesize);
void    ss(int  *pilea, int *pileb, int pilesize);
void    pb_pa(int *pilea, int  *pileb, char pb_pa, int pilesizeofa, int pilesizeofb);
void    ra_rb(int *pilex, int pilesize);
void    rr(int *pilea, int *pileb, int pilesize);
void    rra_rrb(int *pilex, int pilesize);
void    rrr(int *pilea, int *pileb, int pilesize);
int min_number_value(int *pilea, int pilesize);
int min_number_index(int *pilea, int pilesize);
int pile_is_sorted(int *pilea, int pilesize);
int find_swappable_index(int *pileacpy, int pilesize);
void    rotate_pile(int *pileacpy, int pilesize, int check);
void    sort(int *pileacpy, int pilesize);
void    sort_and_assign(int *pilea, int *pileacpy, int pilesize);
int ft_strbitlen(char *octet);
int	decimal_to_bits(int max_value);
int max_number_value(int *pilea, int pilesize);
void    push_and_rotate(int *pilea, int *pileb, int i, int *pilesizeofa, int *pilesizeofb);
void    bit_and_set(int *pilea, int *pileb, int pilesize);
int search_nb_index(int *pilea, int pilesize, int tosearch);
void    sort_pilesize_3(int *pilea, int *pileb);
void    push_nb(int *pilea, int *pileb, int pilesizeofa, int pilesizeofb, int index);
void    sort_pilesize_4_5(int *pilea);
void    sort_small_pile(int *pilea, int *pileb, int pilesize);
int is_there_space(char *str);
void    free_array(char **array, int pilesize);
void    check_chars(char **array, int pilesize, int check);
int handle_doubles(int *pilea, int pilesize);
void	check_big_nb(char **array, int pilesize, int check);
void    check_doubles(char **array, int pilesize, int check);
int check_args(int argc, char **argv);
void    check_pile_almost_sorted(int *pilea, int *pileb, int *pileacpy, int pilesize);
void    handle_argc_2(int *pilea, char *str, int pilesize);
void    handle_argc(int *pilea, char **argv, int pilesize);
//void    print_piles(int *pilea, int *pileb, int pilesizeofa, int pilesizeofb);

#endif