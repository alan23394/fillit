/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:21:16 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/16 15:56:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define READ_SIZE	8
# define BUF_SIZE	128
# define MINO_SIZE	21

typedef struct		s_mino
{
	char			c;
	short			mino;
}					t_mino;

t_mino			*new_mino(char ch, short bits);
void			print_bits(int c, int nb);
void			print_numbers(short mino);
short			validate(short mino);
short			get_mino(char *buf);

#endif
