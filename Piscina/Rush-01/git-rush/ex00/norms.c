/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:01:02 by danielma          #+#    #+#             */
/*   Updated: 2023/02/12 16:30:42 by bagilar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	norm1(int seen2, int apply[SIZE])
{
	if (seen2 == 4)
	{
		apply[0] = 4;
		apply[1] = 3;
		apply[2] = 2;
		apply[3] = 1;
	}
	else if (seen2 == 3)
		apply[0] = 4;
	else if (seen2 == 2)
	{
		apply[0] = 4;
		apply[3] = 3;
	}
}

void	norm2(int seen2, int apply[SIZE])
{
	if (seen2 == 1)
	{
		apply[0] = 3;
		apply[3] = 4;
	}
	else if (seen2 == 3)
		apply[1] = 4;
}

void	norm3(int seen2, int apply[SIZE])
{
	if (seen2 == 2)
		apply[2] = 4;
	else if (seen2 == 1)
		apply[3] = 4;
}

void	norm4(int seen2, int apply[SIZE])
{
	if (seen2 == 1)
	{
		apply[0] = 1;
		apply[1] = 2;
		apply[2] = 3;
		apply[3] = 4;
	}
}

void	norms(int seen1, int seen2, int apply[SIZE])
{
	apply[0] = 0;
	apply[1] = 0;
	apply[2] = 0;
	apply[3] = 0;
	if (seen1 == 1)
		norm1(seen2, apply);
	else if (seen1 == 2)
		norm2(seen2, apply);
	else if (seen1 == 3)
		norm3(seen2, apply);
	else if (seen1 == 4)
		norm4(seen2, apply);
}
