/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:45:14 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/15 17:45:17 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

#include <stdio.h>					// REMOVE!!

# define MAX 2147483647

int		main(int argc, char **argv);
int		read_input(int fd, char ***arr);
int		check_block_sides(char ***arr, int i, int j, int k);
int		check_square(char ***arr, int i, int *empties, int *blocks);
int		check_input(char ***arr, int i);
int		align_pieces(char ***arr, int i);
int		check_row(char ***arr, int index);
int		check_col(char ***arr, int index);
void	move_row(char ***arr, int index);
void	move_col(char ***arr, int index);
int		convert_to_binary(char ***arr, char **bin_arr, int piece_count);
char	 **solve_map(char **bin_arr, int piece_count);
void	print_bits(int n);
void	give_map(int *map, int side_len);

#endif

