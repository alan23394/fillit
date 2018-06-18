/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:36:47 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/18 10:58:12 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check line
see if row of piece fits in line
check below line at the same index if row of piece fits in that line
keep going until it either can't do it, or all the lines in the piece are checked
bitwise or each row recursively
*/

#include "libft.h"
#include "fillit.h"

void	board_main()
{
	uint16_t	board[16];

	for (int i = 0; i < 16; i++)
		board[i] = 0;

	print_board(board);
}
