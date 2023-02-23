/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_work.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:55:53 by tofujiwa          #+#    #+#             */
/*   Updated: 2023/02/23 13:23:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	point_counter (uintptr_t point)
{
	int			len;
	
	len = 0;
	while (point > 0)
	{
		point = point / 16;
		len++;
	}
	return (len);
}

static void	ft_sub_putpointer (uintptr_t point)
{
	int	temp;

	temp = 0;
	if (point > 0)
	{
		temp = (point % 16);
		ft_sub_putpointer(point / 16);
		if (temp >= 0 && temp <= 9)
			ft_putchar (temp + '0');
		if (10 <= temp && temp <= 16)
			ft_putchar (temp - 10 + 'a');
	}
}

int	ft_putpointer (uintptr_t point)
{
	int size;

	// if (point < 0)
		
	size = 0;
	size += write (1, "0x", 2);
	size += point_counter (point);
	ft_sub_putpointer (point);
	return (size);
}