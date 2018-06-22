/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:07:20 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/18 12:48:55 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*ft_strinit(size_t size, int c)
{
	return ((char *)ft_nmemset(malloc(size + 1), c, size + 1));
}

/*
void	print_bits(int c, int nb)
{
	if (nb > 1)
		print_bits(c >> 1, nb - 1);
	ft_putnbr(c & 1);
	ft_putchar(' ');
}

void	print_numbers(uint16_t mino)
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
		ft_putstr(", c: ");
		ft_putchar(CHAR(elem));
		ft_putstr(", x: ");
		ft_putnbr(X(elem));
		ft_putstr(", y: ");
		ft_putnbr(Y(elem));
	}
	ft_putchar('\n');
}

void	print_mab(uint16_t map[])
{
	int i;

	i = 0;
	while (i < 16)
	{
		print_bits(map[i], 16);
		ft_putchar('\n');
		++i;
	}
 }
*/
