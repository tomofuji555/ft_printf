/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:58:38 by marvin            #+#    #+#             */
/*   Updated: 2023/02/24 20:58:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  nbr_count (int nb)
{
    int size;

    size = 0;
    while (nb > 0)
    {
        nb = nb / 10;
        size++;
    }
    return (size);
}

static void	ft_sub_putnbr (int	nb)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_sub_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int ft_putnbr (int  nb)
{
    int size;

    size = 0;
    size += nbr_count (nb);
    ft_sub_putnbr (nb);
    return (size);
}