/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 02:21:22 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/13 19:24:06 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_elem(char *str)
{
	int		i;
	int		diez;
	int		point;
	int		finligne;

	i = 0;
	diez = 0;
	point = 0;
	finligne = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			diez++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			finligne++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	if (diez != 4 || point != 12 || finligne != 4)
		return (0);
	return (1);
}

static int		check_line(char *str)
{
	int		x;
	int		y;
	int		add_5;

	x = 0;
	y = 0;
	add_5 = 4;
	while (str[x] != '\0')
	{
		if (str[x] == '.' || str[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (str[x] == '\n' && x == add_5)
		{
			y = 0;
			add_5 += 5;
		}
		x++;
	}
	return (1);
}

static int		check_forme(char *str)
{
	int		i;
	int		hauteur;
	int		largeur;

	i = 0;
	hauteur = get_hauteur(str);
	largeur = get_largeur(str);
	if (diezcoller(str) == 0)
		return (0);
	if (espacediez(str) == 0 || largeur == 0 || hauteur == 0)
		return (0);
	if (hauteur == 2 && largeur == 2)
		return (1);
	else if (hauteur == 2 && largeur == 3)
		return (1);
	else if (hauteur == 3 && largeur == 2)
		return (1);
	else if (hauteur == 1 && largeur == 4)
		return (1);
	else if (hauteur == 4 && largeur == 1)
		return (1);
	else
		return (0);
}

int				check(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetri)
	{
		if (check_elem(tab[i]) != 1)
			return (0);
		if (check_line(tab[i]) != 1)
			return (0);
		if (check_forme(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int				premier_test(char *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			y++;
		if (y == 4)
		{
			if (buf[x + 1] != '\n' && buf[x + 1] != '\0')
				return (0);
			if (buf[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
