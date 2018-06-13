/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/12 18:06:34 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

void	print_usage()
{
	ft_putendl("usage: ./fillit fillit_file");
}

t_piece	*new_piece(char ch, short bits)
{
	t_piece	*ret;

	ret = (t_piece *)ft_memalloc(sizeof(t_piece));
	if (!ret)
		return (0);
	ret->c = ch;
	ret->piece = bits;
	ret->next = 0;
	return (ret);
}

void	print_bits(int c, int nb)
{
	if (nb > 1)
		print_bits(c >> 1, nb - 1);
	ft_putnbr(c & 1);
	if (!(nb % 4))
		ft_putchar(' ');
}

short	align(short piece)
{
	int shift;

	shift = 0;
	while (!((piece << shift) & 0xF000))
		shift += 4;
	while (!((piece << shift) & 0x8888))
		shift += 1;
	return ((short)shift);
}

int		validate_mino(int *mino)
{
	ft_putstr("mino numbers:  ");
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(*mino);
		ft_putstr(", ");
		++mino;
		++i;
	}
	ft_putendl("\b\b");
	return (1);
}

short	conv_piece(char *buf, int coords[])
{
	char	*cur;
	int		i;
	int		count;

	cur = buf;
	i = 0;
	count = 0;
	while (*cur && count <= 4)
	{
		if (*cur == '#' && count < 4 && i < 4)
		{
			ret = ret | (1 << (15 - ((cur - buf) - ((cur - buf)/5))));
			coords[i] = (1 + (cur - buf) - (cur - buf)/5);
			i++;
			count++;
		}
		else if (*cur == '.' && count < 4)
			count++;
		else if (*cur == '\n' && count == 4)
			count = 0;
		else
			return (0);
		++cur;
	}
	return (ret);
}

short	get_piece(char *buf)
{
	int		coords[4];
	int		*p_coords;
	int		i;
	short	ret;

	i = 0;
	ret = conv_piece(buf, coords);
	/*
	while (*cur && count <= 4)
	{
		if (*cur == '#' && count < 4 && i < 4)
		{
			ft_putstr("grid pos:		");
			ft_putnbr((cur - buf) - (cur - buf)/5);
			ft_putstr("  (");
			ft_putnbr(15 - ((cur - buf) - (cur - buf)/5));
			ft_putstr(")");
			ft_putchar('\n');
			ft_putstr("normal bit:		");
			ft_putnbr(1 << ((cur - buf) - ((cur - buf)/5)));
			ft_putstr("    (");
			print_bits(1 << ((cur - buf) - ((cur - buf)/5)), 16);
			ft_putendl("\b)");
			ft_putstr("flipped bit:		");
			ft_putnbr(0 | 1 << (15 - ((cur - buf) - ((cur - buf)/5))));
			ft_putstr("    (");
			print_bits(0 | 1 << (15 - ((cur - buf) - ((cur - buf)/5))), 16);
			ft_putendl("\b)");
			ret = ret | (1 << (15 - ((cur - buf) - ((cur - buf)/5))));
			ft_putstr("ret:		(");
			print_bits(ret, 16);
			ft_putendl("\b)");
			ft_putstr("coords[");
			ft_putnbr(i);
			ft_putstr("]:		");
			coords[i] = ((cur - buf) - (cur - buf)/5);
			ft_putnbr(coords[i]);
			ft_putchar('\n');
			ft_putchar('\n');
			//ret = ret | (1 << (15 - ((cur - buf) - ((cur - buf)/5))));
			//coords[i] = (1 + (cur - buf) - (cur - buf)/5);
			i++;
			count++;
		}
		else if (*cur == '.' && count < 4)
			count++;
		else if (*cur == '\n' && count == 4)
			count = 0;
		else
			return (0);
		++cur;
	}
	*/
	if (i != 4)
		return (0);
	while (i--)
		coords[i] -= align(ret);
	ret <<= align(ret);
	p_coords = coords;
	if (!validate_mino(p_coords))
		return (0);
	return (ret);
}
