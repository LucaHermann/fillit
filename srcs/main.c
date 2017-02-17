/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:52:50 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/17 18:52:41 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		affichage(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

static int	definition_taille_carre(void)
{
	int		taille_carre;
	float	float_nb;

	float_nb = ft_sqrt((float)(g_nb_tetri) * 4.0);
	taille_carre = (int)float_nb;
	if (taille_carre == float_nb)
		return (taille_carre);
	return (taille_carre);
}

void		free_tab(char **tab, int taille_tab)
{
	int i;

	i = 0;
	while (i < taille_tab)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

int			main(int argc, char **argv)
{
	t_tetrimino	*debut;
	char		**tab;

	debut = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_putendl("error\n");
		return (-1);
	}
	if ((tab = ft_read(argv[1])) == NULL)
	{
		ft_putendl("error\n");
		return (-1);
	}
	if (check(tab) == 0)
	{
		ft_putendl("error\n");
		free_tab(tab, g_nb_tetri + 1);
		return (-1);
	}
	debut = splittab(tab);
	free_tab(tab, g_nb_tetri + 1);
	affichage(solve(debut, definition_taille_carre(), NULL));
	return (0);
}
