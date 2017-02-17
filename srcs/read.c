/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:49:40 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/13 19:09:20 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**remplissage_tab(char **tab, char *buf)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	while (b < nombre_tetrimino(buf))
	{
		tab[b] = (char*)malloc(sizeof(char) * 20 + 1);
		if (tab[b] == NULL)
			return (NULL);
		while (c < 20)
		{
			tab[b][c] = buf[a];
			c++;
			a++;
		}
		tab[b][20] = '\0';
		c = 0;
		b++;
		a++;
	}
	tab[b] = NULL;
	return (tab);
}

char			**ft_read(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	g_nb_tetri = nombre_tetrimino(buf);
	tmp = (char**)malloc(sizeof(char *) * nombre_tetrimino(buf) + 1);
	if (tmp == NULL)
		return (NULL);
	if (premier_test(buf) == 0)
		return (NULL);
	tmp = remplissage_tab(tmp, buf);
	return (tmp);
}

t_tetrimino		*splittab(char **tab)
{
	int			a;
	t_tetrimino	*debut;
	t_tetrimino	*ptr;

	a = 1;
	debut = NULL;
	ptr = NULL;
	debut = nouveautetri(ft_strsplit(tab[0], '\n'), 0);
	ptr = debut;
	while (a < g_nb_tetri)
	{
		ptr->suivant = nouveautetri(ft_strsplit(tab[a], '\n'), a);
		ptr = ptr->suivant;
		a++;
	}
	ptr->suivant = NULL;
	return (debut);
}
