/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:21:16 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/17 14:07:52 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MINO_SIZE 21
# define BITS(cur) (((t_mino *)(cur->content))->mino)
# define CHAR(cur) (((t_mino *)(cur->content))->c)

typedef struct		s_mino
{
	char			c;
	short			mino;
}					t_mino;

t_mino			*new_mino(char ch, short bits);
short			validate(short mino);
short			get_mino(char *buf);

void			print_bits(int c, int nb);
void			print_numbers(short mino);
void			print_item(t_list *elem);

#endif
