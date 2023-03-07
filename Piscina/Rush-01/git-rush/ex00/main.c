/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:40:04 by danielma          #+#    #+#             */
/*   Updated: 2023/02/12 16:30:12 by bagilar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	init_mat(int mat[SIZE][SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			mat[i][j] = 0;
		}
	}
}

void	print_mat(int mat[SIZE][SIZE])
{
	int		i;
	int		j;
	char	aux;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE - 1)
		{
			aux = mat[i][j] + '0';
			write(1, &aux, 1);
			write(1, " ", 1);
		}
		aux = mat[i][SIZE - 1] + '0';
		write(1, &aux, 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char	*argv[])
{
	t_params	params;
	int			mat[SIZE][SIZE];

	if (valid_param(argc, argv))
	{
		init_mat(mat);
		receive_param(argv[1], &params);
		if (SIZE == 4 && !apply_norms(mat, &params))
			write(1, "Error\n", 6);
		if (solve(mat, &params))
			print_mat(mat);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
