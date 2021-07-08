#ifndef UTILS_H
# define UTILS_H
# include <string.h>
# include <unistd.h>



void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void    ft_puterror(char *str);
#endif