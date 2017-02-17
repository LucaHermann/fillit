/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:59:03 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/13 18:18:34 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**creation_tab(char **tab, int taille_carre)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	tab = ft_memalloc(sizeof(char *) * taille_carre + 1);
	while (a < taille_carre)
	{
		tab[a] = ft_memalloc(sizeof(char *) * taille_carre + 1);
		a++;
	}
	a = 0;
	while (b < taille_carre)
	{
		while (a < taille_carre)
		{
			tab[b][a++] = '.';
		}
		tab[b][a] = '\0';
		a = 0;
		b++;
	}
	tab[b] = NULL;
	return (tab);
}

int			nombre_tetrimino(char *str)
{
	int		a;
	int		nb_tetri;

	a = 0;
	nb_tetri = 0;
	while (str[a] != '\0')
	{
		if (str[a] == '\n' && (str[a + 1] == '\n' || str[a + 1] == '\0'))
			nb_tetri++;
		a++;
	}
	return (nb_tetri);
}

t_tetrimino	*nouveautetri(char **tetrimino, int num)
{
	t_tetrimino *nouveau;

	nouveau = NULL;
	nouveau = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (nouveau == NULL)
		return (NULL);
	nouveau->tetrimino = tetrimino;
	nouveau->lettre = 'A' + num;
	nouveau->x = 0;
	nouveau->y = 0;
	nouveau->suivant = NULL;
	return (nouveau);
}
