#ifndef LEMIN_H
# define LEMIN_H

# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
#include <stdio.h>

typedef struct  s_lem
{
	int		nbp; //nb de chemins utilises
	char	**map;
	int		on;
    int		i;
	int		f;		//nb de fourmis;
	int		**fo;
	int		nb;		//nb de rooms;
	char	**names;	//noms des rooms seront sous se format "room0\nroom1\nroom2\nroom3\n" avec un strsplit on a un char** names[start] = nom de la salle start
	int		*x;	//coordonnees des rooms
	int		*y;
	int		start;
	int		startt;
	int		end;
	int		endd;
	int		tubes; //peut etre inutile mais le nombre de tubes
	int		*seen; //algo ce qui a était deja vu, passé
	int		lseen; //nombre de deja vu
	int		**lrooms; //nombre de laisons qu'a la salle
	int		**rooms; //liaisons entre les rooms  sous se format:	room0|				laisons1|liaisons2
																//		room1|				liasions1
	int		**paths;
	int		*seeen;
	int		*uftrace;
	int		lseeen;
	int		path; //nombre de chemins
	int		p;
	int		**range;
	int		**range2;
	int		**pass;
	int		**block;
	int		perfect;
	int		*rendu; //a refaire
	int		r;
	int		*tmprendu; // a refaire
	int		tmpr;
	int		*combi; // a refaire avec le tableau de corres
	int		c;
	int		onoff;
	int		max;
	int		*pri;
	int		*pri2;
	int		endalgo;
	int		**corr; //tableau de correspondance paths et pt
	int		***pt;	//tableau de chemins
	int		*xb;	//tableau du nombre de chemins de pt
	int		**cb;	//combi nodes bloques ligne 1, ligne 2 = tab bloques
}				t_lem;

void	print_cb(t_lem *data);
void	print_tabbb(t_lem *data, int ***tab, int *xb);
void	pt(t_lem *data);
int		cor(int v1, int j, t_lem *data);
int		bself(t_lem *data, int i, int c, int self);
int		block_self(t_lem *data, int e);
void    print_instant(t_lem *data);
void    print_ants_norm(t_lem *data, int nbf);
void	print_ants(t_lem *data);
int		*sort_path(t_lem *data, int *rendu, int nbrendu);
int		print_final(t_lem *data, int *tab, int r);
void	print_tab_normal_r(t_lem *data, int **tab, int nb);
int		delete_path(t_lem *data);
int		valid_path(t_lem *data);
int		same_path(t_lem *data, int x, int y);
int		ft_rendu(t_lem *data, int i);
void	print_paths_only(t_lem *data);
int		end_c(t_lem *data, int e, int k, int v1);
int		b(t_lem *data, int i, int c);
int		bo(t_lem *data, int i, int c, int s);
int		better(t_lem *data, int i, int c, int s);
int		create_alternative(t_lem *data, int r, int k, int v1);
int		creat_a(t_lem *data, int i, int j, int v1);
int		creat_alt(t_lem *data, int s, int i, int v1);
int		change(t_lem *data, int v1, int i);
int     count_shot(t_lem *data, int *rendu, int nbrendu);
int		cmp_shot(t_lem *data);
int		best_combi(t_lem *data, int e, int on);
int		copy_rendu(t_lem *data);
int		compatible(t_lem *data, int e);
int		fill_tmpr(t_lem *data, int v1);
int		nocompatible(t_lem *data, int i, int v1);
int		compare(t_lem *data, int v1);
int		search_valide(t_lem *data, int v1);
int		combinaison(t_lem *data, int e);
int		unblock(t_lem *data);
int		blocked(t_lem *data, int e);
int		end_cmp(t_lem *data, int e);
int		solve(t_lem *data, int end);
int		error(int i, t_lem *data);
int		room(char **str, t_lem *data, int on);
int		tubes(char **str, t_lem *data, int on);
int		comment(t_lem *data);
int		commande(char **strr, t_lem *data);
int		use(t_lem *data); //si la map est utilisable avec ce qu'n a deja return 1;
void	lemin(t_lem *data);
void	free_map(char **map);
int		ft_read(t_lem *data);
int		add_room(char *newname, t_lem *data, int x ,int y);
int		init_data(t_lem *data);
int		check_xy(int x, int y, t_lem *data);
void	fill_xy(int x, int y, t_lem *data);
void	fill_empty_tab(int *tab, int *tab2, int nb);
int		fourmis(char **strr, t_lem *data);
int		check_name(t_lem *data, int name);
int		check_names(t_lem *data, char *name);
int		find_path(t_lem *data);
int		algo(t_lem *data);
int		explore(t_lem *data, int e);
void	fill_seen(t_lem *data, int e);
int		alrdy_seen(t_lem *data, int c);
int		fill_rooms(t_lem *data, int a, int b);
int		index_names(t_lem *data, int s);
void	print_tab_normal(int *tab, int nb);
void	print_map(char **map, int nb);
void	print_tab(t_lem *data, int *tab, int nb);
void	print_tabb_name(t_lem *data, int **tab, int nb, int n);
void	print_tabb(int **tab, int nb, int n);
void	print_name(t_lem *data, int nb);
int		ret_names(t_lem *data, char *name);
int		find_l(t_lem *data, int a, int b);
void	print_coor(t_lem *data);
int		bfs(t_lem *data, int e);
void	new_path(t_lem *data, int e);
int		fill_seeen(t_lem *data, int e);
void	know(t_lem *data, int e, int *k, int *u);
void	c_path(int u, int k, int e, t_lem *data);
void	print_paths(t_lem *data);
int		find_place(t_lem *data, int c);
void    reset_cb(t_lem *data);
void    fill_cb(t_lem *data);

#endif