# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-hou <mvan-hou@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/07 18:24:45 by mvan-hou      #+#    #+#                  #
#    Updated: 2020/08/07 19:34:19 by mvan-hou      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = libft/libft.a

OBJS = srcs/main.o srcs/iscommand.o srcs/iscomment.o \
srcs/iscoordinate.o srcs/isroom.o srcs/isroomname.o srcs/ischaracter.o \
srcs/getname.o srcs/getcoordinates.o srcs/algorithm.o \
srcs/isduplicateroom.o srcs/newroom.o srcs/gethash.o \
srcs/newtable.o srcs/printlist.o srcs/freetable.o srcs/addlist.o \
srcs/addtable.o srcs/freelist.o srcs/islink.o srcs/getroom.o srcs/addlink.o \
srcs/islinkname.o srcs/newlink.o srcs/isants.o srcs/newlemin.o srcs/newline.o \
srcs/addline.o srcs/newmap.o srcs/loadmap.o srcs/validatemap.o srcs/bfs.o \
srcs/queue.o srcs/freemap.o srcs/freelemin.o srcs/dfs.o srcs/max_paths.o\
srcs/isduplicatelink.o srcs/newcoordinatestable.o srcs/freelinks.o \
srcs/loadrooms.o srcs/loadlinks.o srcs/moveants.o srcs/cleanup.o \
srcs/redirect.o srcs/dfs2.o srcs/redirect2.o srcs/redirect3.o srcs/input.o \
srcs/score1.o srcs/score2.o srcs/score3.o \

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	@$(CC) $(LIBS) -o $@ $^

%.o : %.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "$@"

libft/libft.a: FORCE
	@make -C libft/

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME) libft/libft.a

re: fclean all

FORCE:
