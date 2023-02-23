/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:49:13 by tofujiwa            #+#    #+#             */
/*   Updated: 2023/02/13 17:49:13 by tofujiwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar (unsigned char c)
{
	write (1, &c, 1);
	return (1);
}

// static int	ft_putstr (char *str)
// {
// 	int	size;

// 	size = 0;
// 	while (*str)
// 	{
// 		size += write (1, str, 1);
// 		str++;
// 	}
// 	return (size);
// }

static int	ft_putstr_n (char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
	{
		size += write (1, "(null)", 6);
		return (size);
	}
	while (*str)
	{
		size += write (1, str, 1);
		str++;
	}
	return (size);
}

static int	ft_putnbr (int	nb)
{
	long	n;
	int		size;

	size = 0;
	n = (long)nb;
	if (n < 0)
	{
		size += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		size += ft_putchar(n % 10 + '0');
	}
	else
		size += ft_putchar(n + '0');
	return (size);
}

static int	ft_puthexa(unsigned int num)
{
	int	temp;
	int	size;

	temp = 0;
	size = 0;
	if (num > 0)
	{
		ft_puthexa (num / 16);
		temp = (num % 16);
		if (temp >= 0 && temp <= 9)
			size += ft_putchar (temp + '0'); 
		else if (10 <= temp && temp <= 16)
			size += ft_putchar (temp - 10 + 'a');
	}
	return (size);
}

static int	ft_puthexa_upper(unsigned int num)
{
	int	temp;
	int	size;

	temp = 0;
	size = 0;
	if (num > 0)
	{
		ft_puthexa_upper (num / 16);
		temp = (num % 16);
		if (temp >= 0 && temp <= 9)
			size += ft_putchar (temp + '0');
		if (10 <= temp && temp <= 16)
			size += ft_putchar (temp - 10 + 'A');
	}
	return (size);
}

static int	uns_num_work(unsigned int num)
{
	unsigned long	n;
	int				size;

	size = 0;
	n = (unsigned long)num;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		size += ft_putchar(n % 10 + '0');
	}
	else
		size += ft_putchar(n + '0');
	return (size);
}

static int	ft_printpercentage(unsigned int c)
{
	int	size;

	size = 0;
	if (c == '%')
	{
		size += write (1, "%", 1);
		return (size);
	}
	else
		return (0);
}

static int	judge_format(va_list ap, const char *c)
{
	int	size;

	size = 0;
	if (*c == 'c')
		size += ft_putchar(va_arg (ap, int));
    else if (*c == 's')
		size += ft_putstr_n(va_arg (ap, char *));
	else if (*c == 'd' || *c == 'i')
		size += ft_putnbr(va_arg (ap, int));
    else if (*c == 'p')
		size += ft_putpointer((uintptr_t)va_arg (ap, void *));
    else if (*c == 'u')
		size += uns_num_work(va_arg (ap, unsigned int));
	else if (*c == 'x')
		size += ft_puthexa(va_arg (ap, unsigned int));
	else if (*c == 'X')
		size += ft_puthexa_upper(va_arg (ap, unsigned int));
    else if (*c == '%')
		size += ft_printpercentage(va_arg (ap, unsigned int));
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;
	char 	*c;

	va_start(ap, format);
	size = 0;
	// if (!format)
	// 	return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			c = (char *)format;
			size += judge_format(ap, c);
		}
		else
		{
			c = (char *)format;
			size += ft_putchar(*c);
		}
		format++;
	}
	va_end(ap);
	return (size);
}

// int main (void)
// {
// 	printf ("aiueo\n");
// 	ft_printf ("aiueo");
// 	printf ("\n");
// 	printf ("\n");

// 	char c = 'a';
// 	printf ("printf:   %c\n", c);
// 	ft_printf ("ft_printf:%c", c);
// 	printf ("\n");
// 	printf ("\n");

// 	char *str = "aiueo";
// char *str_null = "";
// 	printf ("printf:   %s\n", str);
// 	ft_printf ("ft_printf:%s", str);
// printf ("%s", str_null);
// ft_printf ("%s", str_null);
// 	printf ("\n");
// 	printf ("\n");

// 	int	nbr = -8975;
// 	printf ("printf:   %d\n", nbr);
// 	ft_printf ("ft_printf:%d", nbr);
// 	printf ("\n");
// 	printf ("printf:   %i\n", nbr);
// 	ft_printf ("ft_printf:%i\n", nbr);
// 	printf ("\n");

// 	unsigned int x = 89;
// 	int temp;
// 	int buffer;

// 	// temp = printf ("printf:   %x\n", x);
// 	printf ("printf:   %x\n", x);
// 	// printf ("%d\n", temp);
// 	// printf ("\n");
// 	// buffer = ft_printf ("ft_printf:%x", x);
// 	ft_printf ("ft_printf:%x", x);
// 	// printf ("\n");
// 	// printf ("%d\n", buffer);
// 	printf ("\n");
// 	printf ("\n");

// 	unsigned int X = 255;
// 	printf ("printf:   %X\n", X);
// 	ft_printf ("ft_printf:%X\n", X);

// 	int ptr = 321;
// 	printf ("%p\n", &ptr);
// 	ft_printf ("%p\n", &ptr);
// 	printf ("\n");
// 	printf ("\n");

// 	unsigned int uns = 234;
// 	printf ("%u\n", uns);
// 	ft_printf ("%u\n", uns);
// 	printf ("\n");
// 	printf ("\n");

// 	printf ("printf:   %d %u %c %s %%\n", nbr, uns, c, str);
// 	ft_printf("ft_printf:%d %u %c %s %%\n", nbr, uns, c, str);
// 	printf ("\n");
// }

int main ()
{
	// printf (" NULL %s NULL ", NULL);
	// ft_printf (" NULL %s NULL ", NULL);

	char *str = "aiueo";
	int z = printf ("%s\n", str);
	printf ("%d\n", z);

	int	ptr = 567;
	int x = printf (" %p \n", &ptr);
	int y = ft_printf (" %p ", &ptr);
	printf ("%d\n", x);
	printf ("%d\n", y);
}