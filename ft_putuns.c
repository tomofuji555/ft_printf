/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:50:59 by marvin            #+#    #+#             */
/*   Updated: 2023/02/24 20:50:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  uns_count (unsigned int num)
{
    int size;

    size = 0;
    while (num > 0)
    {
        num = num / 16;
        size++;
    }
    return (size);
}

static void	ft_sub_uns(unsigned int num)
{
	unsigned long	n;

	n = (unsigned long)num;
	if (n >= 10)
	{
		ft_sub_uns(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int ft_putuns (unsigned int num)
{
    int size;

    size = 0;
    size += uns_count (num);
    ft_sub_uns (num);
    return (size);
}