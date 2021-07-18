#ifndef UTILS_H
# define UTILS_H
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_puterror(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_usleep(size_t time);
size_t	get_time(void);
size_t	get_time_pass(size_t t0);
size_t	uget_time(void);
int		ft_isdigit(int c);
int		is_str_digit(char *str);
#endif
