/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_work.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofujiwa <tofujiwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:53 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/22 16:44:40 by tofujiwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sub_putpointer (uintptr_t point)
{
	int	temp;
	int	size;

	temp = 0;
	size = 0;
	if (point > 0)
	{
		ft_sub_putpointer(point / 16);
		temp = (point % 16);
		if (temp >= 0 && temp <= 9)
			size += ft_putchar (temp + '0');
		if (10 <= temp && temp <= 16)
			size += ft_putchar (temp - 10 + 'a');
	}
	return (size);
}

int	ft_putpointer (uintptr_t point)
{
	int size;

	// if (point < 0)
		
	size = 0;
	size += write (1, "0x", 2);
	size += ft_sub_putpointer (point);
	return (size);
}