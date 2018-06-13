/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/12 16:53:16 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

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
		print_usage();
		return (0);
	}
	count = 0;
	head = new_piece('A', 0x0000);
	cur = head;
	buf = ft_strnew(BUF_SIZE);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buf, PIECE_SIZE + 1))
	{
		buf[20] = '\0';
		bits = get_piece(buf);
		count++;
		if (!bits || count > 26)
		{
			ft_putendl("error");
			return (0);
		}
		cur = new_piece(('A' + count - 1), bits);
		cur = cur->next;
	}
	close(fd);
	return (0);
}
