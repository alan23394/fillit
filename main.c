/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 16:21:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>


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
	while (read(fd, buf, MINO_SIZE))
	{
		buf[MINO_SIZE - 1] = '\0';
		bits = get_mino(buf);
		print_bits(bits, 16);
		ft_putchar('\n');
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
