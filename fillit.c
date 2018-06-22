/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/18 13:34:45 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_mino	*new_mino(char ch, uint16_t bits)
{
	t_mino	*newmino;

	newmino = (t_mino *)ft_memalloc(sizeof(t_mino));
	if (!newmino)
		return (0);
	newmino->c = ch;
	newmino->mino = bits;
	newmino->x = 0;
	newmino->y = 0;
	return (newmino);
}

void	print_map(t_list *list, int size)
{
	char	*s;
	int		row;
	int		i;	
	
	s = ft_strinit(sizeof(char) * size * (size + 1), '.');
	row = size;
	s[((size + 1) * row) - 1] = '\0';
	while (--row)
		s[((size + 1) * row) - 1] = '\n';
	while (list->content)
	{
		row = 0;
		i = 16;
		while (i--)
		{
			if ((BITS(list) >> i) & 0x0001)
				s[(Y(list) + row) * (size + 1) + X(list) + 
				((15 - i) % 4)] = CHAR(list);
			if ((16 - i) % 4  == 0)
				++row;
		}
		list = list->next;
	}
	ft_putendl(s);
}

uint16_t	validate(uint16_t mino)
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

uint16_t	get_mino(char *buf)
{
	uint16_t	mino;
	int			i;
	int			count;

	mino = 0;
	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '#' && ++count)
			mino = mino | (1 << (15 - (i - (i / 5))));
		else if (buf[i] != '.' && buf[i] != '\n')
			return (0);
		else if (buf[i] == '\n' && ((i + 1) % 5 != 0))
			return (0);
		++i;
	}
	return ((count != 4 || i != 20) ? 0 : validate(mino));
}

t_list	*create_list(int fd, char *buf)
{
	t_list		*head;
	t_list		*cur;
	int			count;
	uint16_t	bits;

	head = ft_lstnew(0, 0);
	if (!head)
		return (0);
	cur = head;
	count = 0;
	while (count < 26 && read(fd, buf, MINO_SIZE))
	{
		buf[MINO_SIZE - 1] = (buf[20] == '\n' ? '\0' : 0);
		bits = get_mino(buf);
		if (!bits)
			return (0);
		cur->content = new_mino('A' + count, bits);
		if (!cur->content)
			return (0);
		count++;
		cur->content_size = sizeof(cur->content);
		cur->next = ft_lstnew(0, 0);
		cur = cur->next;
	}
	return (head);
}
