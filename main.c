/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 15:29:36 by rreedy           ###   ########.fr       */
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

	if (argc != 2)
	{
		ft_putstr("error");
		return (0);
	}
	count = 0;
	buf = ft_strnew(BUF_SIZE);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buf, MINO_SIZE))
	{
		buf[MINO_SIZE - 1] = '\0';
		bits = get_mino(buf);
		count++;
		if (!bits || count > 26)
		{
			ft_putendl("error");
			return (0);
		}
	}
	close(fd);
	return (0);
}
