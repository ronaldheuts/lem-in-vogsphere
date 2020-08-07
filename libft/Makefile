# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rheuts <rheuts@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/12 13:45:24 by rheuts        #+#    #+#                  #
#    Updated: 2020/08/07 18:12:31 by rheuts        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

NAME = libft.a

OBJS = srcs/ft_memset.o srcs/ft_bzero.o srcs/ft_memcpy.o srcs/ft_memmove.o \
srcs/ft_memchr.o srcs/ft_memcmp.o srcs/ft_strlen.o srcs/ft_strdup.o \
srcs/ft_strcpy.o srcs/ft_strncpy.o srcs/ft_strcat.o srcs/ft_strncat.o \
srcs/ft_strlcat.o srcs/ft_strchr.o srcs/ft_strrchr.o srcs/ft_strstr.o \
srcs/ft_strnstr.o srcs/ft_strcmp.o srcs/ft_strncmp.o srcs/ft_atoi.o \
srcs/ft_isalpha.o srcs/ft_isdigit.o srcs/ft_isalnum.o srcs/ft_isascii.o \
srcs/ft_isprint.o srcs/ft_toupper.o srcs/ft_tolower.o srcs/ft_memccpy.o \
srcs/ft_memalloc.o srcs/ft_memdel.o srcs/ft_strnew.o srcs/ft_strdel.o \
srcs/ft_strclr.o srcs/ft_striter.o srcs/ft_striteri.o srcs/ft_strmap.o \
srcs/ft_strmapi.o srcs/ft_strequ.o srcs/ft_strnequ.o srcs/ft_strsub.o \
srcs/ft_strjoin.o srcs/ft_strtrim.o srcs/ft_strsplit.o srcs/ft_itoa.o \
srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_putendl.o srcs/ft_putnbr.o \
srcs/ft_putchar_fd.o srcs/ft_putstr_fd.o srcs/ft_putendl_fd.o \
srcs/ft_putnbr_fd.o srcs/ft_lstnew.o srcs/ft_lstdelone.o srcs/ft_lstdel.o \
srcs/ft_lstadd.o srcs/ft_lstiter.o srcs/ft_lstmap.o srcs/ft_lstback.o \
srcs/ft_nlen.o srcs/ft_strndup.o srcs/ft_printf_buffer_flags.o \
srcs/ft_printf_cspfp.o srcs/ft_printf_diouxx.o srcs/ft_printf_initialize.o \
srcs/ft_printf_ischecks.o srcs/ft_printf_len.o srcs/ft_printf_lltoa.o \
srcs/ft_printf_length_specifier.o srcs/ft_printf_state_base.o \
srcs/ft_printf_state_multi.o srcs/ft_printf_floats.o \
srcs/ft_printf_buffer_flags_two.o srcs/ft_printf_binstrfun.o \
srcs/ft_printf_stringcalc.o srcs/ft_printf_binaryconv.o \
srcs/ft_printf_dectrim.o srcs/ft_printf.o srcs/ft_printf_buffer_mgmt.o \
srcs/get_next_line.o srcs/ft_isgraph.o srcs/ft_atol.o \

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJS) *~

fclean: clean
	@rm -f $(NAME)

re: fclean all
