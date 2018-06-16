/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 12:48:28 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

t_list	*create_list(int fd)
{
	t_list	*head;
	t_list	*cur;
	int		count;

	head = ft_lstnew(0, 0);
	cur = head;
	count = 0;
	while (count < 26)
	{
		if (read(fd, buf, PIECE_SIZE))
		{
			bits = get_piece(buf);
			if (bits)
			{
				cur->content = new_piece('A', bits);
			}
		}
	return (head);
}

int		main(int argc, char **argv)
{
	int		fd;
	short	bits;
	int		count;
	char	*buf;
	t_piece	*head;
	t_piece	*cur;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit fillit_file");
		return (0);
	}
	count = 0;
	head = new_piece('A', 0);
	cur = head;
	buf = ft_strnew(BUF_SIZE);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buf, PIECE_SIZE))
	{
		buf[PIECE_SIZE - 1] = '\0';
		bits = get_piece(buf);
		count++;
		if (!bits || count > 26)
		{
			ft_putendl("error");
			return (0);
		}
		cur->piece = bits;
		cur->next = new_piece(('A' + count), 0);
		cur = cur->next;
	}

	close(fd);
	return (0);
}
