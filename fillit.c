/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/17 12:48:39 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_mino	*new_mino(char ch, short bits)
{
	t_mino	*newmino;

	newmino = (t_mino *)ft_memalloc(sizeof(t_mino));
	if (!newmino)
		return (0);
	newmino->c = ch;
	newmino->mino = bits;
	return (newmino);
}

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

short	validate(short mino)
{
	while (!(mino & 0xF000))
		mino = mino << 4;
	while (!(mino & 0x8888))
		mino = mino << 1;
	if ((mino & 0xE000) == 0xE000)
		return ((mino & 0x1E00) ? mino : 0);
	if ((mino & 0x8000) == 0x8000)
		return ((mino & 0x4448) ? mino : 0);
	if ((mino & 0x4C00) == 0x4C00)
		return ((mino & 0xA2C0) ? mino : 0);
	if ((mino & 0x8400) == 0x8400 && !(mino ^ 0x8640))
		return ((mino & 0x31BF) ? 0 : mino);
	return ((mino == 0x44C0 || mino == 0x2E00) ? mino : 0);
}

short	get_mino(char *buf)
{
	short	mino;
	int		i;
	int		count;

	mino = 0;
	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '#' && ++count)
		{	
			mino = mino | (1 << (15 - (i - (i/5))));
		}
		else if (buf[i] != '.' && buf[i] != '\n')
			return (0);
		else if (buf[i] == '\n' && ((i + 1) % 5 != 0))
			return (0);
		++i;
	}
	return ((count != 4 || i != 20) ? 0 : validate(mino));
}
