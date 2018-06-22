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

int		find_spot(uint16_t map[], int size, t_list *mino, int row)
{
	if (!map || (((Y(mino) + row) >= size) && (R(row, mino) > 0)))
		return (-1);
	if (LAST(mino) == CORD(mino, size))
		++X(mino);
	if (X(mino) >= (size - 3) &&
		(BITS(mino) & (0x1111 << ((X(mino) - (size - 3))))))
	{
		++Y(mino);
		X(mino) = 0;
		return (find_spot(map, size, mino, 0));
	}
	if (row == 0)
	{
		if (XOROR(*(map + Y(mino)), (R(row, mino) >> X(mino))))
			if (find_spot(map + 1, size, mino, row + 1))
				return (find_spot(map + 1, size, mino, row + 1));
		++X(mino);
		return (find_spot(map, size, mino, row));
	}
	if (row < 3 && XOROR(*(map + Y(mino)), (R(row, mino) >> X(mino))))
		return (find_spot(map + 1, size, mino, row + 1));
	else
		return (XOROR(*(map + Y(mino)), (R(row, mino) >> X(mino))));
}

int		fill_map(uint16_t map[], int *size, t_list *cur)
{
	int	i;

	if (!cur->content)
		return (1);
	LAST(cur) = -1;
	X(cur) = 0;
	Y(cur) = 0;
	i = find_spot(map, *size, cur, 0);
	while (i == 1)
	{
		if (cur->content && i != -1)
		{
			LAST(cur) = CORD(cur, *size);
			place_mino(map, cur);
			if (fill_map(map, size, cur->next))
				return (1);
			place_mino(map, cur);
		}
		i = find_spot(map, *size, cur, 0);
	}
	return (0);
}

int		ft_lstlen(t_list *head)
{
	int	count;

	count = 0;
	while (head && head->content)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	map_main(t_list *head)
{
	uint16_t	map[16];
	int			count;
	int			size;

	ft_bzero(map, sizeof(uint16_t) * 16);
	count = ft_lstlen(head);
	size = 2;
	while (size * size < count * 4)
		++size;
	while (size <= 16)
	{
		if (!fill_map(map, &size, head))
			++size;
		else
			break;
	}
	if (size > 16)
		ft_putendl("error");
	print_map(head, size);
}
