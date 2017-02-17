/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bordel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:56:52 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/13 15:41:41 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_largeur(char *str)
{
	int		i;
	int		largeur;
	int		line;

	i = 0;
	largeur = 0;
	line = 0;
	while (i < 4)
	{
		if (str[i] == '#' || str[i + 5] == '#' || str[i + 10] == '#' ||\
						str[i + 15] == '#')
		{
			largeur++;
			if (line > 0)
				return (0);
		}
		else if (largeur > 0)
			line++;
		i++;
	}
	return (largeur);
}

int		get_hauteur(char *str)
{
	int		i;
	int		hauteur;
	int		line;

	i = 0;
	hauteur = 0;
	line = 0;
	while (i < 19)
	{
		if (str[i] == '#' || str[i + 1] == '#' || str[i + 2] == '#' ||\
					str[i + 3] == '#')
		{
			hauteur++;
			if (line > 0)
				return (0);
		}
		else if (hauteur > 0)
			line++;
		i = i + 5;
	}
	return (hauteur);
}

int		espacediez(char *str)
{
	int		i;
	int		j;
	int		erreur;

	i = 0;
	j = 0;
	erreur = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			j++;
		if (j == 2 && str[i] == '#')
		{
			while (str[i + 1 + erreur] != '#' && str[i + erreur] != '\0')
				erreur++;
			if (erreur > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int		diezcoller(char *str)
{
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' || str[i - 1] == '#' || str[i + 5] == '#' ||\
						str[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
