/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:10:04 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/26 17:10:04 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int 	uns_count (unsigned int num)
{
	int				size;
	unsigned long	n;

	size = 0;
	n = num;
	while (n > 0)
	{
		n = n / 10;
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
	int	size;

	size = 0;
	if (num == 0)
		size++;
	size += uns_count (num);
	ft_sub_uns (num);
	return (size);
}