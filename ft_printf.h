#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <inttypes.h>

int	ft_printchar (char c);
int	put_format(va_list ap, const char *format);
int	ft_printf(const char *format, ...);
int	ft_putstr (char *str);


#endif