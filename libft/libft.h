/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:30:22 by oadewumi          #+#    #+#             */
/*   Updated: 2024/07/01 13:58:28 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# define FT_LONG_MAX 9223372036854775807L

//This struct is used for handling the needs of ft_printf
typedef struct s_check
{
	int	error;
	int	count;
}				t_check;

//This linked list structure is used for the Libft bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);

int		ft_strncmp(const char *src, const char *dest, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_isdigit(int num);
int		ft_isalpha(int alf);
int		ft_isalnum(int an);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isascii(int a);
int		ft_isprint(int p);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_print_bits(unsigned char octet);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);

//ft_Printf utilities
int		ft_printf(const char *input, ...);

void	print_hexadecimal(unsigned long long n, t_check *audit, char format);
void	print_pointer_hex(unsigned long long ptr, t_check *audit);
void	print_unsign_fd(unsigned int nb, t_check *audit);
void	print_nbr_fd(int nb, t_check *audit);
void	print_char_fd(char c, t_check *audit);
void	print_str_fd(char *s, t_check *audit);

#endif