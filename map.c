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

int		find_spot(uint16_t map[], t_list *mino, int row)
{
	/*
	if (!map)
		return (-1);
	if (i >= 16)
		find_spot(map + 1, mino, 0, 0);
	if (row == 0)
	{
		if ((*map ^ (R(row, mino) >> i)) > *map)
			return (find_spot(map + 1, mino, i, row + 1));
		find_spot(map, mino, i + 1, row);
	}
	if ((*map ^ (R(row, mino) >> i)) > *map)
		return (find_spot(map + 1, mino, i, row + 1));
	else
		
	return (1);

	if (!map)
		return (-1);
	if (X(mino) >= 16)
	{
		Y(mino)++;
		X(mino) = 0;
		return (find_spot(map, mino, row));
	}
	if (row >= 4)
		return (1);
	if (row == 0)
	{
		if ((*(map + Y(mino)) ^ (R(row, mino) >> X(mino))) > *map)
		{
			Y(mino)++;
			if (find_spot(map, mino, row + 1) == 1)
				return (1);
		}
		X(mino)++;
		return (find_spot(map, mino, row));
	}
	if ((*(map + Y(mino)) ^ (R(row, mino) >> X(mino))) > *map)
		return (find_spot(map, mino, row + 1));
	return (0);
	*/
	if (!map)
		return (-1);
	if (X(mino) >= 16)
	{
		Y(mino)++;
		X(mino) = 0;
		return (find_spot(map, mino, row));
	}
	if (row == 0)
	{
		while (X(mino) > 16)
		{
			if ((*(map + Y(mino)) ^ (R(row, mino) >> X(mino))) > *map)
			{
				Y(mino)++;
				if (find_spot(map, mino, row + 1) == 1)
					return (1);
			}
			X(mino)++;
		}
	}
}

void	fill_map(uint16_t map[], t_list *head)
{
	place_mino(map, head);
	print_map(map);
	ft_putchar('\n');
	place_mino(map, head);
}

void	map_main(t_list *head)
{
	uint16_t	map[16];

	ft_bzero(map, sizeof(uint16_t) * 16);

	//fill_map(map, head);
	X(head) = 4;
	Y(head) = 4;
	X(head->next->next) = 11;
	Y(head->next->next) = 10;
	X(head->next->next->next) = 10;
	Y(head->next->next->next) = 10;
	place_mino(map, head);
	place_mino(map, head->next);
	place_mino(map, head->next->next);
	place_mino(map, head->next->next->next);
	ft_putnbr(find_spot(map, head, 0, 0));
	ft_putchar('\n');

	print_map(map);
 }
