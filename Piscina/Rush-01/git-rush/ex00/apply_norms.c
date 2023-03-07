/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_norms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:56:54 by danielma          #+#    #+#             */
/*   Updated: 2023/02/12 16:23:27 by bagilar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	apply_norms(int mat[SIZE][SIZE], t_params *params)
{
	int	ind;
	int	norm[SIZE];

	ind = -1;
	while (++ind < SIZE)
	{
		norms(params->up[ind], params->down[ind], norm);
		if (norm[0] != 0 || norm[1] != 0 || norm[2] != 0 || norm[3] != 0)
		{
			mat[0][ind] = norm[0];
			mat[1][ind] = norm[1];
			mat[2][ind] = norm[2];
			mat[3][ind] = norm[3];
		}
		norms(params->left[ind], params->right[ind], norm);
		if (norm[0] != 0 || norm[1] != 0 || norm[2] != 0 || norm[3] != 0)
		{
			mat[ind][0] = norm[0];
			mat[ind][1] = norm[1];
			mat[ind][2] = norm[2];
			mat[ind][3] = norm[3];
		}
	}
	return (1);
}
