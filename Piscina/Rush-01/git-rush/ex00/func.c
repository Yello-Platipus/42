/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:01:35 by danielma          #+#    #+#             */
/*   Updated: 2023/02/12 17:45:40 by bagilar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	search_empty_case(int mat[SIZE][SIZE], int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (mat[i][j] == 0)
			{
				*x = i;
				*y = j;
				return (1);
			}
		}
	}
	return (0);
}

int	can_put_value(int mat[SIZE][SIZE], int x, int y, int value)
{
	int	ind;

	ind = -1;
	while (++ind < SIZE)
		if (mat[x][ind] == value || mat[ind][y] == value)
			return (0);
	return (1);
}

int	line_is_valid(int mat[SIZE][SIZE], t_params *params, int x)
{
	int	ind;
	int	max;
	int	visible;

	max = 0;
	visible = 0;
	ind = -1;
	while (++ind < SIZE)
	{
		visible += (mat[x][ind] > max);
		max = ((mat[x][ind] > max) ? mat[x][ind] : max);
	}
	if (params->left[x] != visible)
		return (0);
	max = 0;
	visible = 0;
	while (--ind > -1)
	{
		visible += mat[x][ind] > max;
		max = ((mat[x][ind] > max) ? mat[x][ind] : max);
	}
	if (params->right[x] != visible)
		return (0);
	return (1);
}

int	column_is_valid(int mat[SIZE][SIZE], t_params *params, int y)
{
	int	ind;
	int	max;
	int	visible;

	max = 0;
	visible = 0;
	ind = -1;
	while (++ind < SIZE)
	{
		visible += mat[ind][y] > max;
		max = ((mat[y][ind] > max) ? mat[y][ind] : max);
	}
	if (params->up[y] != visible)
		return (0);
	max = 0;
	visible = 0;
	while (--ind > -1)
	{
		visible += mat[ind][y] > max;
		max = ((mat[y][ind] > max) ? mat[y][ind] : max);
	}
	if (params->down[y] != visible)
		return (0);
	return (1);
}

int	solve(int mat[SIZE][SIZE], t_params *params)
{
	int	x;
	int	y;
	int	value;

	if (search_empty_case(mat, &x, &y))
	{
		value = 0;
		while (++value <= SIZE)
		{
			if (can_put_value(mat, x, y, value))
			{
				mat[x][y] = value;
				if (y == (SIZE - 1) && !line_is_valid(mat, params, x))
					continue ;
				if (x == (SIZE - 1) && !column_is_valid(mat, params, y))
					continue ;
				if (solve (mat, params))
					return (1);
			}
		}
		mat[x][y] = 0;
		return (0);
	}
	return (1);
}
