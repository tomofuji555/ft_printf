/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:46:20 by marvin            #+#    #+#             */
/*   Updated: 2023/02/24 20:46:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_up_counter (unsigned int num)
{
	int			len;
	
	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_sub_puthexa_up(unsigned int num)
{
	char    c;

	c = 0;
	if (num > 0)
	{
		ft_sub_puthexa_up (num / 16);
		c = (num % 16);
		if (c >= 0 && c <= 9)
			ft_putchar (c + '0'); 
		else if (10 <= c && c <= 16)
			ft_putchar (c - 10 + 'A');
	}
}

int	ft_puthexa_up (unsigned int num)
{
	int size;
		
	size = 0;
	size += hexa_up_counter (num);
	ft_sub_puthexa_up (num);
	return (size);
}