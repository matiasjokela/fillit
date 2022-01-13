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
int		convert_to_binary(char ***arr, int **bin_arr, int piece_count);
int		solve_map(int **bin_arr, int piece_count);
void	print_bits(int n);
void	give_map(int *map, int side_len);
int		plant_piece(int **bin_arr, int *map, int i, int side_len);
int		move_piece(int **bin_arr, int *map, int i, int side_len);
int		move_to_next_row(int **bin_arr, int i, int side_len, int *map);
void	restore_piece(int **bin_arr, int i);
void	pop_piece(int *map, int **bin_arr, int i, int side_len);
int		solver(int **bin_arr, int *map, int i, int side_len);
void	show_output(int **bin_arr, int side_len);
void	restart_piece(int **bin_arr, int *map, int i, int side_len);
void	skip_row(int **bin_arr, int *map, int i, int side_len);

#endif

