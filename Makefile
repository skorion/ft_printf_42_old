NAME = libftprintf.a
INC = ft_printf.h
FILE =	ft_printf.c \
		delet_all.c \
		get_next_symbol_type.c \
		get_next_end_or_param.c \
		make_dlist_with_new_print.c \
		print_answer.c \
		pars.c \
		read_all.c \
		formating.c \
		format_c.c \
		format_di.c \
		format_fF.c \
		format_o.c \
		format_p.c \
		format_proc.c \
		format_s.c \
		format_u.c \
		format_x.c \
		set_stars.c \
		new_t_print.c \
		print_delet.c \
		print_set_poiter.c \
		print_set_printed.c \
		print_set_type.c \
		get_lpf.c \
		get_pp.c \
		get_ps.c \
		get_pw.c \
		is_a_flag.c \
		get_nan_and_inf.c \
		set_len_print.c



OBJ =	ft_printf.o \
		delet_all.o \
		get_next_symbol_type.o \
		get_next_end_or_param.o \
		make_dlist_with_new_print.o \
		print_answer.o \
		pars.o \
		read_all.o \
		formating.o \
		format_c.o \
		format_di.o \
		format_f.o \
		format_o.o \
		format_p.o \
		format_proc.o \
		format_s.o \
		format_u.o \
		format_x.o \
		set_stars.o \
		new_t_print.o \
		print_delet.o \
		print_set_poiter.o \
		print_set_printed.o \
		print_set_type.o \
		get_lpf.o \
		get_pp.o \
		get_ps.o \
		get_pw.o \
		is_a_flag.o \
		get_nan_and_inf.o \
		set_len_print.o


all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): %.o : %.c $(INC)
	@gcc -Wall -Wextra -Werror -c $< -I $(INC)

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
