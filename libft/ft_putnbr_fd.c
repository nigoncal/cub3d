/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:03:10 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 14:03:16 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header_libft.h"

void	min_number(unsigned int min_n, int fd)
{
	if (min_n > 0)
	{
		min_number(min_n / 10, fd);
		ft_putchar_fd(min_n % 10 + '0', fd);
	}
}

void	actual_putnbr(int n, int fd)
{
	unsigned int min_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		min_n = n;
		min_number(min_n, fd);
	}
	else if (n > 0)
	{
		actual_putnbr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd(n + '0', fd);
	else
		actual_putnbr(n, fd);
}
