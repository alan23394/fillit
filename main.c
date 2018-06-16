/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 14:58:56 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

/*
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
*/

int		main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	int		count;
	short	bits;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file.fillit");
		return (0);
	}
	buf = ft_strnew(BUF_SIZE);
	fd = open(argv[1], O_RDONLY);
	count = 0;
	while (read(fd, buf, PIECE_SIZE))
	{
		buf[PIECE_SIZE - 1] = '\0';
		bits = get_piece(buf);
		count++;
		if (!bits || count > 26)
		{
			ft_putstr("bits: ");
			print_bits(bits, 16);
			ft_putendl("error");
			return (0);
		}
	}
	close(fd);
	return (0);
}
