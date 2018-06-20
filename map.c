/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:36:47 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/19 12:15:10 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check line
see if row of piece fits in line
check below line at the same index if row of piece fits in that line
keep going until it either can't do it, or all the lines in the piece are checked
bitwise or each row recursively
*/

#include "libft.h"
#include "fillit.h"

void	place_mino(uint16_t map[], t_list *mino)
{
	int i;

	i = -1;
	map += Y(mino);
	while (++i < 4)
		*map++ ^= R(i, mino) >> X(mino);
}

/*
** Right now, this function needs to check for the width of a piece
** to make sure it doesn't place it off the edge of the board.
*/
int		find_spot(uint16_t map[], t_list *mino, int row)
{
	if (!map || Y(mino) >= 16)
		return (-1);
	if (X(mino) >= 16)
	{
		ft_putstr("going up to line: ");
		Y(mino)++;
		ft_putnbr(Y(mino));
		ft_putchar('\n');
		ft_putstr("line bits: ");
		print_bits(*(map + Y(mino)), 16);
		ft_putchar('\n');
		X(mino) = 0;
		return (find_spot(map, mino, 0));
	}
	if (row == 0)
	{
		if (XOROR(*(map + Y(mino)), (R(row, mino) >> X(mino))))
		{
			ft_putendl("going in here");
			if (find_spot(map + 1, mino, row + 1))
			{
				ft_putendl("further in here");
				return (find_spot(map + 1, mino, row + 1));
			}
		}
		ft_putstr("skipping x: ");
		ft_putnbr(X(mino));
		ft_putstr(" y: ");
		ft_putnbr(Y(mino));
		ft_putchar('\n');
		X(mino)++;
		return (find_spot(map, mino, row));
	}
	if (row < 4 && XOROR(*(map + Y(mino)), (R(row, mino) >> X(mino))))
	{
		ft_putstr("row: ");
		ft_putnbr(row);
		ft_putchar('\n');
		return (find_spot(map + 1, mino, row + 1));
	}
	else
		return (XOROR(*(map + Y(mino)), (R(row, mino) >> X(mino))));
}

void	fill_map(uint16_t map[], t_list *head)
{
	int i;

	i = 1;
	while (head->content && find_spot(map, head, 0) != -1)
	{
		ft_putstr("piece ");
		ft_putnbr(i);
		ft_putchar('\n');
		ft_putnbr(X(head));
		ft_putstr(", ");
		ft_putnbr(Y(head));
		ft_putchar('\n');
		place_mino(map, head);
		print_map(map);
		head = head->next;
		i++;
	}
}

void	map_main(t_list *head)
{
	uint16_t	map[16];

	ft_bzero(map, sizeof(uint16_t) * 16);

	fill_map(map, head);

	print_map(map);
 }
