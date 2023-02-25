/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:10:44 by marvin            #+#    #+#             */
/*   Updated: 2023/02/25 15:10:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_n (char *str)
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