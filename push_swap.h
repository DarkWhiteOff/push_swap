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
int					ft_putchar(char c);
int					ft_itoa2(int n);
char				*ft_itoa_ft_printf(int n);
int					ft_count_ft_printf(int n);
char				*ft_min_ft_printf(char *str);
int					ft_putstr(char *str);
//pas utilisée
int					ft_dec_into_hex(unsigned int n, int b);
void				ft_print_array(char *array, int i);
char				*ft_fill_hexarray(unsigned int n, char *string,
						char *array);
int					ft_get_size_hexarray(unsigned int n);
int					ft_unsigned_itoa2(unsigned int n);
char				*ft_unsigned_itoa(unsigned int n);
int					ft_unsigned_count(unsigned int n);
int					ft_putptr(unsigned long long adress);
char				*ft_fill_ptrarray(unsigned long long adress,
						char *string, char *array);
int					ft_get_size_ptrarray(unsigned long long adress);
int					ft_putstr(char *str);

// Libft
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *str, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *str, int fd);
char				**ft_split(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t dsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *tofind, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// Push swap
void    actualise_pile(int *pilex, char *str, int pilesize);
void    sa_sb(int *pilex, int pilesize);
void    ss(int  *pilea, int *pileb, int pilesize);
void    pb_pa(int *pilea, int  *pileb, char *str, int pilesizeofa, int pilesizeofb);
void    ra_rb(int *pilex, int pilesize);
void    rr(int *pilea, int *pileb, int pilesize);
void    rra_rrb(int *pilex, int pilesize);
void    rrr(int *pilea, int *pileb, int pilesize);
int min_number_value(int *pilea, int pilesize);
int min_number_index(int *pilea, int pilesize);
int pile_is_sorted(int *pilea, int pilesize);
int find_swappable_index(int *pileacpy, int pilesize);
void    rotate_pile(int *pileacpy, int pilesize, int check);
void    sort(int *pileacpy, int pilesize, int check);
void    sort_and_assign(int *pilea, int *pileacpy, int pilesize);
int ft_strbitlen(char *octet);
int	decimal_to_bits(int max_value);
int max_number_value(int *pilea, int pilesize);
void    bit_and_set(int *pilea, int *pileb, int pilesize);
int search_nb_index(int *pilea, int pilesize, int tosearch);
void    sort_pilesize_3(int *pilea, int *pileb);
void    push_nb(int *pilea, int *pileb, int pilesizeofa, int pilesizeofb, int index);
void    sort_pilesize_4_5(int *pilea, int *pileb);
void    sort_small_pile(int *pilea, int *pileb, int pilesize);
int is_there_space(char *str);
void    free_array(char **array, int pilesize);
void    check_chars(char **array, int pilesize, int check);
int handle_doubles(int *pilea, int pilesize);
void    check_doubles(char **array, int pilesize, int check);
int check_args(int argc, char **argv);
void    check_pile_almost_sorted(int *pilea, int *pileb, int *pileacpy, int pilesize);
void    handle_argc_2(int *pilea, char *str, int pilesize);
void    handle_argc(int *pilea, char **argv, int pilesize);

#endif