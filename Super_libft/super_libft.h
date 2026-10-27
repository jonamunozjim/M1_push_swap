/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fejimene <fejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:54:48 by fejimene          #+#    #+#             */
/*   Updated: 2026/10/23 13:21:01 by fejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_LIBFT_H
# define SUPER_LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *ptr, int x, size_t n);
void			ft_bzero(void *ptr, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_toupper(int n);
int				ft_tolower(int n);
char			*ft_strchr(const char *str, int a);
char			*ft_strrchr(const char *str, int a);
int				ft_strncmp(const char *str1, const char *str2, size_t a);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strnstr(const char *big, const char *lil, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(void *str);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif

int				ft_printf(char const *str, ...);
int				ft_conver(char const str, va_list args);
int				ft_putchar_print(int c);
int				ft_putnbr_print(int n);
int				ft_putunbr_print(unsigned int n);
int				ft_putstr_print(char *s);
int				ft_puthex_print(unsigned long nb, const char c);
int				ft_putptr_print(void *ptr);

char			*get_next_line(int fd);
char			*ft_read(int fd, char *buffer);
char			*ft_line(char *buffer);
char			*ft_clean(char *buffer, char *line);
char			*ft_free_and_null(char *res, char *buffer);
char			*ft_strjoin_next_line(char *s1, char *s2);