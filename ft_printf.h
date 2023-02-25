#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <inttypes.h>

int	ft_putchar (unsigned char c);
int	ft_putstr_n (char *str);
int	ft_printf(const char *format, ...);
int	ft_putpointer (uintptr_t point);
int	ft_puthexa (unsigned int num);
int	ft_puthexa_up (unsigned int num);
int ft_putnbr (int  nb);
int ft_putuns (unsigned int num);
int	ft_putpercent(unsigned int c);

#endif