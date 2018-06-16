/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:21:16 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 11:32:58 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define READ_SIZE	8
# define BUF_SIZE	128
# define PIECE_SIZE	21

typedef struct		s_piece
{
	char			c;
	short			piece;
}					t_piece;

t_piece			*new_piece(char ch, short bits);
void			print_bits(int c, int nb);
short			align(short piece);
int				validate(short piece);
short			get_piece(char *buf);
short			conv_piece(char *buf);

#endif
