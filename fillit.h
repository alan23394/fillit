/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:21:16 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/19 12:15:24 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define uint16_t u_int16_t
# define uint8_t char
# define MINO_SIZE 21
# define R(i, cur) ((BITS(cur) & (0xF000 >> (i * 4))) << (i * 4))
# define BITS(cur) (((t_mino *)(cur->content))->mino)
# define CHAR(cur) (((t_mino *)(cur->content))->c)
# define X(cur) (((t_mino *)(cur->content))->x)
# define Y(cur) (((t_mino *)(cur->content))->y)
# define XOROR(a, b) ((a ^ b) == (a | b))

typedef struct		s_mino
{
	char			c;
	uint16_t		mino;
	uint8_t			x;
	uint8_t			y;
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
void				print_map(uint16_t map[]);

/*
**	Map
*/
void				place_mino(uint16_t map[], t_list *mino);
int					find_spot(uint16_t map[], int size, t_list *mino, int row);
void				fill_map(uint16_t map[], int *size, t_list *head);
int					ft_lstlen(t_list *head);
void				map_main(t_list *head);

#endif
