/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 15:04:39 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_piece	*new_piece(char ch, short bits)
{
	t_piece	*ret;

	ret = (t_piece *)ft_memalloc(sizeof(t_piece));
	if (!ret)
		return (0);
	ret->c = ch;
	ret->piece = bits;
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

int		validate(short piece)
{
	int i;

	while (!(piece & 0xF000))
		piece <<= 4;
	while (!(piece & 0x8888))
		piece <<= 1;
	ft_putstr("mino numbers:  ");
	i = 0;
	while (i < 14)
	{
		if ((0x8000 >> i) & piece)
		{
			ft_putnbr(i + 1);
			ft_putstr(", ");
		}
		++i;
	}
	ft_putendl("\b\b");
	return (piece);
}

short	conv_piece(char *buf)
{
	char	*cur;
	int		count;
	int		i;
	short	ret;

	cur = buf;
	count = 0;
	i = 0;
	ret = 0;
	while (*cur && count <= 4)
	{
		if (*cur == '#' && count < 4 && i++ < 4)
		{
			ret = ret | (1 << (15 - ((cur - buf) - ((cur - buf)/5))));
			++count;
		}
		else if (*cur == '.' && count < 4)
			++count;
		else if (*cur == '\n' && count == 4)
			count = 0;
		else
			return (0);
		++cur;
	}
	if (i != 4)
		return (0);
	return (ret);
}

short	get_piece(char *buf)
{
	short	ret;

	ret = conv_piece(buf);
	if (!ret)
		return (0);
	ret = validate(ret);
	if (!ret)
		return (0);
	return (ret);
}
