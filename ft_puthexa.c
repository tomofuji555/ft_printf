/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:32:57 by marvin            #+#    #+#             */
/*   Updated: 2023/02/24 20:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_counter (unsigned int num)
{
	int			size;
	
	size = 0;
	while (num > 0)
	{
		num = num / 16;
		size++;
	}
	return (size);
}

static void	ft_sub_puthexa(unsigned int num)
{
	char    c;

	c = 0;
	if (num > 0)
	{
		ft_sub_puthexa (num / 16);
		c = (num % 16);
		if (c >= 0 && c <= 9)
			ft_putchar (c + '0'); 
		else if (10 <= c && c <= 16)
			ft_putchar (c - 10 + 'a');
	}
}

int	ft_puthexa (unsigned int num)
{
	int size;
		
	size = 0;
	size += hexa_counter (num);
	ft_sub_puthexa (num);
	return (size);
}