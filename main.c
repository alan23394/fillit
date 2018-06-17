/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:48:31 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/17 13:13:07 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

t_list	*create_list(int fd, char *buf)
{
	t_list	*head;
	t_list	*cur;
	int		count;
	short	bits;

	head = ft_lstnew(0, 0);
	if (!head)
		return (0);
	cur = head;
	count = 0;
	while (count < 26 && read(fd, buf, MINO_SIZE))
	{
		buf[MINO_SIZE - 1] = '\0';
		bits = get_mino(buf);
		if (bits)
		{
			cur->content = new_mino('A' + count, bits);
			if (cur->content)
				count++;
			else
				return (0);
			cur->content_size = sizeof(cur->content);
			cur->next = ft_lstnew(0, 0);
			cur = cur->next;
		}
		else
			return (0);
	}
	return (head);
}

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
