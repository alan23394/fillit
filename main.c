/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/17 14:26:51 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*buf;
	int		fd;
	t_list	*head;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file.fillit");
		return (0);
	}
	buf = ft_strnew(MINO_SIZE + 1);
	fd = open(argv[1], O_RDONLY);
	head = create_list(fd, buf);
	if (!head)
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	ft_lstiter(head, &print_item);
	return (0);
}
