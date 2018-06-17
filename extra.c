/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:07:20 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/17 14:08:02 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_bits(int c, int nb)
{
	if (nb > 1)
		print_bits(c >> 1, nb - 1);
	ft_putnbr(c & 1);
	if (!(nb % 4))
		ft_putchar(' ');
}

void	print_numbers(short mino)
{
	int i;

	ft_putstr("mino numbers:  ");
	i = 0;
	while (i <= 16)
	{
		if ((0x8000 >> i) & mino)
		{
			ft_putnbr(i + 1);
			ft_putstr(", ");
		}
		++i;
	}
	ft_putendl("\b\b");
}

void	print_item(t_list *elem)
{
	if (elem->content)
	{
		print_bits(BITS(elem), 16);
		ft_putstr(" ");
		ft_putchar(CHAR(elem));
	}
	ft_putchar('\n');
}
