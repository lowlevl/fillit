/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:40 by lroux             #+#    #+#             */
/*   Updated: 2018/11/21 18:20:07 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <fcntl.h>

typedef struct		s_point {
	char			x;
	char			y;
}					t_point;

typedef struct		s_fill {
	t_point			points[4];
	char			letter;
	struct s_fill	*next;
}					t_fill;

typedef struct		s_map {
	int				w;
	char			*map;
	int				size;
}					t_map;

# define RCF_FAIL -1
# define RCF_KEK 0
# define RCF_EOF 1

void				filladd(t_fill **list, t_fill *new);
int					filllen(t_fill *list);
void				fillfree(t_fill *list);
void				usage(char *name);
void				error(void);
void				clean(void);
int					rcf(t_fill **list, char *filename);
void				moveorigin(t_fill *list);

//scott's testing
t_map	create_map(int map_width);
int		find_square(t_fill *list, t_map *map, int map_size);
void	print_map(t_map *map, int list_size);
void	fillappend(t_fill **lst, t_fill *new);
t_fill	*fillnew(t_point *points, int num);
void	print_points(t_point *points);
void	fillprint(t_fill **lst);
void	print_map(t_map *map, int list_size);
int		master_function(t_fill *list, t_map *map);
#endif