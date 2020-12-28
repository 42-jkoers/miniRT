/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:51:21 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 20:38:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t count);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen(char *str);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(char *str, char c);
char				*ft_strrchr(char *str, char c);
char				*ft_strnstr(
					const char *big, const char *little, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(
					t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** Custom functions
*/

long				ft_abs(long num);
size_t				ft_numlen(long num, unsigned long base);
size_t				ft_numlen_u(unsigned long num, unsigned long base);
char				*ft_numtostr(long num);
char				*ft_numtostr_u(unsigned long num);
char				*ft_numtohexstr_u(
					unsigned long num, bool lowercase, bool prefix);
char				*ft_numtohexstr_precision_u(unsigned long num, \
					bool lowercase, bool prefix, size_t min_len);
char				*ft_numtobase(long num, char *base);
char				*ft_numtobase_u(unsigned long num, char *base);
char				*ft_numtostr_precision_u(unsigned long num, size_t min_len);
char				*ft_numtostr_precision(long num, size_t min_len);
char				*ft_strndup(char *str, size_t len);
char				*ft_strndup_unsafe(char *str, size_t len);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, size_t nb);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
void				ft_strtolower(char *s);
void				ft_strtoupper(char *s);
void				ft_lstpush_back(t_list **lst, void *content);
void				ft_lstpush_front(t_list **lst, void *content);
void				ft_putstr(char *s);
bool				ft_includes(char *str, char c);
void				ft_strset(char *str, char c, size_t n);
void				ft_padend(char **str, size_t target_len, char pad);
void				ft_padstart(char **str, size_t target_len, char pad);
int					ft_isspace(char c);
long				ft_strtonum(char *str);
unsigned long		ft_strtonum_u(char *str);
long				ft_max(long a, long b);
unsigned long		ft_max_u(unsigned long a, unsigned long b);
long				ft_min(long a, long b);
unsigned long		ft_min_u(unsigned long a, unsigned long b);
int					ft_get_next_line(int fd, char **line);
char				**ft_split_or(
						const char *s, const char *spitters, size_t *length);
char				**ft_split_file(const char *filename, size_t *num_lines);
char				**ft_split_length(char const *s, char c, size_t *length);
void				*ft_realloc(void *ptr, size_t orig_len, size_t new_len);
void				ft_lstshift(t_list **lst, void (*del)(void*));
void				ft_free_2d(void **arr, size_t length);
void				*ft_memdup(void *src, size_t n);

typedef struct		s_arr_voidp
{
	size_t			start_i;
	size_t			length;
	size_t			size;
	void			**table;
}					t_arr_voidp;
t_arr_voidp			*ft_arr_voidp(size_t initial_size);
void				*ft_arr_voidp_set(t_arr_voidp **arr, size_t i, void *value);
void				*ft_arr_voidp_get(t_arr_voidp *arr, size_t i);
void				*ft_arr_voidp_push(t_arr_voidp **arr, void *value);
void				ft_arr_voidp_free(t_arr_voidp *arr, void (*del)(void *));
void				ft_arr_voidp_shift(t_arr_voidp **arr, void (*del)(void *));
void				ft_arr_voidp_pop(t_arr_voidp **arr, void (*del)(void *));
void				**ft_arr_voidp_concat(t_arr_voidp *arr, size_t *length);
double				ft_strtodbl(char *str);
size_t				ft_strcount(char *str, char search);

/*
** typedef struct		s_arr_long
** {
** 	size_t			start_i;
** 	size_t			length;
** 	size_t			size;
** 	long			*table;
** }					t_arr_long;
*/

#endif
