/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:28:46 by danielma          #+#    #+#             */
/*   Updated: 2023/02/12 16:49:04 by bagilar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>

# define N_COLS 4
# define N_ROWS 4
# define SIZE 4

typedef struct s_params
{
	char	up[SIZE];
	char	down[SIZE];
	char	left[SIZE];
	char	right[SIZE];
}	t_params;

int		apply_norms(int mat[SIZE][SIZE], t_params *params);
int		search_empty_case(int mat[SIZE][SIZE], int *x, int *y);
int		can_put_value(int mat[SIZE][SIZE], int x, int y, int value);
int		line_is_valid(int mat[SIZE][SIZE], t_params *params, int y);
int		column_is_valid(int mat[SIZE][SIZE], t_params *params, int y);
int		solve(int mat[SIZE][SIZE], t_params *params);
int		valid_param(int argc, char *argv[]);
void	receive_param(char *in, t_params *params);
void	init_up_down(char *in, t_params *params);
void	init_left_right(char *in, t_params *params);
void	norm1(int seen2, int apply[SIZE]);
void	norm2(int seen2, int apply[SIZE]);
void	norm3(int seen2, int apply[SIZE]);
void	norm4(int seen2, int apply[SIZE]);
void	norms(int seen1, int seen2, int apply[SIZE]);
void	print_mat(int mat[SIZE][SIZE]);

#endif
