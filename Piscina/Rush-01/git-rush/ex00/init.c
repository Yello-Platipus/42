/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:29:13 by danielma          #+#    #+#             */
/*   Updated: 2023/02/12 16:26:17 by bagilar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	valid_param(int argc, char *argv[])
{
	int		ret;
	int		i;
	char	*ptr;

	ret = 1;
	i = 0;
	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	ptr = argv[1];
	while (*ptr != '\0')
	{
		if ((*ptr < '0' || *ptr > '4') && *ptr != ' ')
			ret = 0;
		ptr++;
		i++;
	}
	if (i != 31)
		ret = 0;
	if (ret == 0)
		write (1, "Error\n", 6);
	return (ret);
}

void	receive_param(char *in, t_params *params)
{
	init_up_down(in, params);
	init_left_right((in + 2 * 2 * SIZE), params);
}

void	init_up_down(char *in, t_params *params)
{
	int		i;
	char	*ptr;

	ptr = in;
	i = -1;
	while (++i < SIZE)
	{
		params->up[i] = *ptr - '0';
		ptr += 2;
	}
	i = -1;
	while (++i < SIZE)
	{
		params->down[i] = *ptr - '0';
		ptr += 2;
	}
}

void	init_left_right(char *in, t_params *params)
{
	int		i;
	char	*ptr;

	ptr = in;
	i = -1;
	while (++i < SIZE)
	{
		params->left[i] = *ptr - '0';
		ptr += 2;
	}
	i = -1;
	while (++i < SIZE)
	{
		params->right[i] = *ptr - '0';
		ptr += 2;
	}
}
