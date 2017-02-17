/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:05:28 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/13 18:21:46 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_position(t_tetrimino *debut, char **tab, int taille_carre)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (debut->tetrimino[i][j] == '#' && (debut->x + j >= taille_carre \
						|| debut->y + i >= taille_carre))
				return (0);
			if (debut->tetrimino[i][j] == '#' && \
					ft_isalpha(tab[debut->y + i][debut->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static char		**placement(t_tetrimino *debut, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (debut->tetrimino[i][j] == '#')
				tab[debut->y + i][debut->x + j] = debut->lettre;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static char		**replacement(t_tetrimino *debut, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == debut->lettre)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int				place(t_tetrimino *debut, int taille_carre, char **tab)
{
	if (debut != NULL)
	{
		while (debut->y * debut->x < taille_carre * taille_carre)
		{
			if ((test_position(debut, tab, taille_carre)) == 1)
			{
				tab = placement(debut, tab);
				if (place(debut->suivant, taille_carre, tab) == 1)
					return (1);
				tab = replacement(debut, tab);
			}
			if (debut->x < taille_carre)
				debut->x++;
			else
			{
				debut->x = 0;
				debut->y++;
			}
		}
		debut->x = 0;
		debut->y = 0;
		return (0);
	}
	return (1);
}

char			**solve(t_tetrimino *debut, int taille_carre, char **tab_resolu)
{
	arrange(debut);
	tab_resolu = creation_tab(tab_resolu, taille_carre);
	while (place(debut, taille_carre, tab_resolu) == 0)
	{
		taille_carre++;
		debut->x = 0;
		debut->y = 0;
		free_tab(tab_resolu, taille_carre);
		tab_resolu = creation_tab(tab_resolu, taille_carre);
	}
	return (tab_resolu);
}
