define HEAD                                                      


███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝                                                                   
endef
export HEAD

DEF_COLOR 	= \033[0;39m
YELLOW		= \033[0;93m
GREEN		= \033[0;92m
BLUE 		= \033[0;94m
CYAN		= \033[0;96m
PURPLE	 	= \033[0;35m
BOLD		= \033[1m
RED         = \033[0;91m


BG_GREEN	= \033[42m
NC			= \033[0m

LIBFT = libft.a

NAME = minishell

SRC_FILES = sources/cd.c \
			sources/check_quotes.c \
			sources/echo_utils.c \
			sources/echo_utils2.c \
			sources/echo.c \
			sources/env.c \
			sources/envp_utils.c \
			sources/envp_utils2.c \
			sources/export_exec.c \
			sources/export.c \
			sources/find_path.c \
			sources/free.c \
			sources/free2.c \
			sources/init.c \
			sources/is_builtin.c \
			sources/is_echo.c \
			sources/list.c \
			sources/main.c \
			sources/parsing_command.c \
			sources/pipe.c \
			sources/pwd.c \
			sources/quotes_management.c \
			sources/redir_exec.c \
			sources/redir_in_management.c \
			sources/redir_out_management.c \
			sources/redir.c \
			sources/run_exit.c \
			sources/run_simple.c \
			sources/signals.c \
			sources/unset.c \
			sources/utils.c \
			sources/utils2.c \
			sources/utils3.c

OBJ_FILES = ${SRC_FILES:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I /goinfre/homebrew/opt/readline/include
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
HEADER = headers/minishell.h
RM = rm -rf

all: libft $(NAME)

libft:
	make -C libs/Libft

%.o: %.c $(HEADER) Makefile libs/Libft/$(LIBFT)
		@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
		$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : $(OBJ_FILES) libs/Libft/$(LIBFT)
		$(CC) $(OBJ_FILES) -I $(HEADER) libs/Libft/$(LIBFT) $(READLINE) -o $(NAME)
		@echo "\n$(BG_GREEN)minishell successfuly compiled !$(NC)"
		@echo "$(RED)$(BOLD)$$HEAD$(DEF_COLOR)"

clean :
		make clean -C libs/Libft
		${RM} ${OBJ_FILES}
		@echo "$(CYAN)minishell object files cleaned!$(DEF_COLOR)"

fclean : clean
		make fclean -C libs/Libft
		${RM} $(NAME)
		${RM} $(LIBFT)
		@echo "$(CYAN)3$(DEF_COLOR)"
		@sleep 0.2
		@echo "$(CYAN)2$(DEF_COLOR)"
		@sleep 0.2
		@echo "$(CYAN)1$(DEF_COLOR)"
		@sleep 0.2
		@echo "$(GREEN)minishell executable files cleaned!$(DEF_COLOR)"



re : fclean all


.PHONY : all clean fclean re libft