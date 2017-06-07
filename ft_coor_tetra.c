/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:26:45 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/07 17:35:44 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

char	**ft_row_tetra(char *tetra)
{
	t_type2	ro;

	if (!(ro.tab = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	ro.row = 0;
	ro.i = 0;
	ro.j = 4;
	while (ro.i < 19)
	{
		ro.col = 0;
		if (!(ro.tab[ro.row] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		while (ro.i < ro.j)
		{
			ro.tab[ro.row][ro.col] = tetra[ro.i];
			ro.col++;
			ro.i++;
		}
		ro.tab[ro.row][ro.col] = '\0';
		ro.row++;
		ro.i = ro.i + 1;
		ro.j = ro.i + 4;
	}
	return (ro.tab);
}

int		ft_ini(t_type4 *s)
{
	s->sq = 0;
	s->row = 0;
	if (!(s->coor = (int **)malloc(sizeof(int *) * 4)))
		return (0);
	if (!(s->coor[s->sq] = (int *)malloc(sizeof(int) * 2)))
		return (0);
	s->coor[0][0] = 0;
	s->coor[0][1] = 0;
	return (1);
}

int		ft_end(t_type4 *s)
{
	if (!(s->coor[s->sq] = (int *)malloc(sizeof(int) * 2)))
		return (0);
	s->coor[s->sq][0] = s->col - s->ori[0];
	s->coor[s->sq][1] = s->row - s->ori[1];
	s->sq++;
	return (1);
}

int		**ft_coor_tetra(char **tetra)
{
	t_type4 s;

	if ((ft_ini(&(s))) == 0)
		return (NULL);
	while (s.row < 4)
	{
		s.col = 0;
		while (s.col < 4)
		{
			if (s.sq == 0 && tetra[s.row][s.col] == '#')
			{
				s.ori[0] = s.col;
				s.ori[1] = s.row;
				s.sq++;
			}
			else if (tetra[s.row][s.col] == '#')
			{
				if ((ft_end(&(s))) == 0)
					return (NULL);
			}
			s.col++;
		}
		s.row++;
	}
	return (s.coor);
}
