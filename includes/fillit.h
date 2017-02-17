/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 02:26:58 by mdauphin          #+#    #+#             */
/*   Updated: 2017/02/13 19:06:24 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"

int g_nb_tetri;
# define BUFF_SIZE 4096

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				lettre;
	int					x;
	int					y;
	struct s_tetrimino	*suivant;
}						t_tetrimino;

t_tetrimino				*arrange(t_tetrimino *debut);
void					affichage(char **tab);
int						nombre_tetrimino(char *str);
char					**ft_read(char *argv);
t_tetrimino				*splittab(char **tab);
t_tetrimino				*nouveautetri(char **tetrimino, int num);
char					**solve(t_tetrimino *debut, int taille_carre,\
char					**tab_resolu);
char					**creation_tab(char **tab, int taille_carre);
void					free_tab(char **tab, int taille_tab);
int						check(char **tab);
int						premier_test(char *buf);
int						get_largeur(char *str);
int						get_hauteur(char *str);
int						espacediez(char *str);
int						diezcoller(char *str);
#endif
