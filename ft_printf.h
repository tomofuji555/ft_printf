#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

int	ft_putchar (unsigned char c);
int	ft_putstr_n (char *str);
int	ft_printf(const char *format, ...);
int	ft_putpointer (uintptr_t point);
ssize_t	ft_puthexa (unsigned int num);
ssize_t	ft_puthexa_up (unsigned int num);
ssize_t ft_putnbr (int  nb);
int ft_putuns (unsigned int num);
int	ft_putpercent(unsigned int c);

#endif