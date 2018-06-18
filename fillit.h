/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:21:16 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/18 11:00:34 by abarnett         ###   ########.fr       */
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
	uint16_t		mino;
}					t_mino;

/*
**	Fillit
*/
t_mino				*new_mino(char ch, uint16_t bits);
uint16_t			validate(uint16_t mino);
uint16_t			get_mino(char *buf);
t_list				*create_list(int fd, char *buf);

/*
**	Extra
*/
void				print_bits(int c, int nb);
void				print_numbers(uint16_t mino);
void				print_item(t_list *elem);
void				print_board(uint16_t board[]);

/*
**	Board
*/
void				board_main();

#endif
