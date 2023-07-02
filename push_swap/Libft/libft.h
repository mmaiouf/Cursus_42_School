/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:01:56 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/06 17:40:36 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}		t_list;

long				ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memset(void *pointer, int value, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *tofind,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));
t_list				*ft_lstmap(t_list *lst, int (*f)(int),
						void (*del)(int));
int					ft_len_int(int nb);
int					ft_putnbr_int(int nb);
int					ft_len_u_int(unsigned int nb);
int					ft_putnbr_u_int(unsigned int nb);
int					ft_putchar_int(char c);
int					ft_putstr_int(char *str);
int					ft_printf(const char *str, ...);
int					get_arg_len(const char *str, int i, va_list ap);
unsigned int		ft_len_hexa(unsigned int nb);
unsigned int		ft_display_hexa(long nb, char caps);
unsigned long long	ft_len_hexa_pointer(unsigned long long nb);
unsigned long long	ft_display_hexa_pointer(unsigned long long nb);
int					check_nbread_and_linebreak(char *str, int nb_read);
char				*read_file(int fd, char *backup);
char				*get_a_line(char *backup);
char				*get_next_line_start(char *backup);
char				*get_next_line(int fd);
int					get_index_linebreak(char *str);
int					get_len_line(char *str);
size_t				ft_strlen(char const *str);
void				*ft_memcpy_gnl(void *dest, void *src, size_t size);
char				*ft_strjoin_free(char *s1, char *s2);

#endif
