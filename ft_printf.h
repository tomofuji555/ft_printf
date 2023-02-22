#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <inttypes.h>

int	ft_putchar (unsigned char c);
int	ft_printf(const char *format, ...);
int	ft_putpointer (uintptr_t point);

#endif