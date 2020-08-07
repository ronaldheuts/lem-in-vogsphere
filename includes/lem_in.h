/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:52:04 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 18:14:17 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>

# include <stdio.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct		s_link
{
	struct s_room	*room;
	struct s_link	*next;
	int				on;
}					t_link;

typedef struct		s_room
{
	char			*name;
	char			*xy;
	int				hashname;
	int				hashxy;
	int				v;
	int				level;
	int				p_id;
	int				a_id;
	struct s_link	*link;
	struct s_room	*nextname;
	struct s_room	*nextxy;
}					t_room;

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_map
{
	struct s_line	*head;
	struct s_line	*tail;
	int				n_rooms;
}					t_map;

typedef struct		s_data
{
	struct s_map	*map;
	struct s_room	**hashtable;
	struct s_room	**xytable;
	struct s_room	*start;
	struct s_room	*end;
	struct s_line	*walker;
	struct s_path	*paths;
	char			**rooms;
	char			roomtype;
	int				iter;
	int				alter;
	long long		ants;
	int				max;
	int				score;
}					t_data;

enum				e_roomtypes
{
	ROOM_DEFAULT,
	ROOM_START,
	ROOM_END
};

typedef struct		s_path
{
	struct s_path	*next;
	struct s_pnode	*path;
	int				length;
	int				ants;
}					t_path;

typedef struct		s_pnode
{
	struct s_pnode	*head;
	struct s_pnode	*next;
	struct s_pnode	*prev;
	struct s_room	*room;
	int				ant_id;
}					t_pnode;

typedef struct		s_queue
{
	struct s_link	*head;
	struct s_link	*tail;
	int				len;
}					t_queue;

void				addtail(t_line **tail, t_line *new);
void				addhead(t_line **head, t_line *new);

int					addtable(t_data *lemin);
int					addlistlink(t_data *lemin);
void				addlistnamebucket(t_room **head, t_room *new);
void				addlistxybucket(t_room **head, t_room *new);
void				countrooms(t_map *input);
int					validatemap(t_data *lemin);

int					inputcheck(char *s, t_room **head);

int					check_input(t_map *input, t_data **lemin);
void				print_input(t_data *lemin);

int					isants(t_data *lemin);

int					iscommand(t_data *lemin);
int					iscomment(const char *s);
int					iscoordinate(char *s, int *i);
int					ischaracter(char c, char d);
int					isduplicatelink(t_room *head, char *new);
int					isduplicateroom(t_room *head, char *new);
int					isduplicatexy(t_room *head, char *new);

int					islink(t_data *lemin);
int					islinkname(char *s);
int					isroom(char *s);
int					isroomname(char *s, int *i);

void				freelemin(t_data **lemin);
void				freelinks(t_link **head);

void				freelist(t_room **head);
void				freemap(t_map *p);
void				freerooms(t_data *lemin);
void				freetable(t_room **hashtable, int size);

char				*getcoordinates(char *s, int *i);
char				*getroomname(char *s, int *i);
t_room				*getroom(char *s, t_data *lemin);

unsigned int		hash(char *s, int n_rooms);

int					loadmap(t_map *input);

int					loadrooms(t_data *lemin);
int					loadlinks(t_data *lemin);
void				moveants(t_data *lemin);

t_data				*newlemin(t_map *input);
t_line				*newline(char *s);
t_link				*newlink(char *s, t_data *lemin);
t_map				*newmap(void);
t_room				*newroom(t_data *lemin);
char				**newcoordinatestable(int size);
t_room				**newtable(unsigned int size);

int					ft_isalnum(int c);

void				printlist(t_room *head);
void				printlink(t_link *head);
void				queueants(t_data *lemin);

int					remove_from_queue(t_queue *queue);
int					add_item(t_queue *queue, t_link *link);
int					add_to_queue(t_room *room, t_queue *queue,
					t_data *lemin, int type);
void				initialize_queue(t_queue *queue);
int					create_levels(t_room *start, t_room *end, t_data *lemin);
t_path				*get_paths(t_data *lemin, int p_id);
t_path				*compare(t_data *lemin);
int					max_paths(t_room *start, t_room *end);
int					algorithm(t_data *lemin);
void				remove_link(t_room *room1, t_room *room2);
void				clean_map(t_data *lemin);

t_path				*store_paths(t_data *lemin, int count);
int					start_end(t_data *lemin);

t_path				*compare_paths(t_data *lemin, int p_count);
int					calculate_score(t_path *paths, t_data *lemin);
int					get_score(t_path *paths);
void				free_path(t_path *paths);
int					redirect(t_data *lemin);

void				cut_tail(t_path *path);
t_pnode				*start_end_path(t_data *lemin);
t_pnode				*new_node(t_room *room, t_pnode *next);
t_path				*new_path(void);
int					get_path_data(t_pnode *path);

int					count_links(t_room *room, int iter);
int					compare_block(t_room *old, t_room *new, t_room *room);
t_room				*end_link(t_room *room, t_data *lemin);
int					valid_end_link(t_room *room, t_data *lemin);
int					at_end(t_room *room, t_data *lemin);
t_link				*best_rlink(t_room *room, t_data *lemin);

void				distribute_ants(t_path *paths, int count, int ants);
int					next_queue_length(t_path *paths);
void				sort_paths(t_path *paths);
int					shortest_queues(t_path *paths);

#endif
