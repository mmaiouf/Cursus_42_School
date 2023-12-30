/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mou3 <mou3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:34:44 by mmaiouf           #+#    #+#             */
/*   Updated: 2023/12/25 23:43:54 by mou3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libs/Libft/libft.h"

extern int	g_error;

typedef struct s_envp
{
	char	**env_array;
	int		env_len;
	char	*input;
	char	**array_redir;
	char	*file_redir_in;
	char	*file_redir_out;
	char	*eof_heredoc;
	int		stdout_copy;
	int		count_pipe_exec;
	char	*epur;
	char	*command_quotes;
	int		n_flag;
	int		quote_flag;
	int		error_flag_quote;
	int		n_pipe;
	int		n_redir_out;
	int		n_redir_in;
	int		n_single_quotes;
	int		n_double_quotes;
	char	*str_quotes_removed;
	char	*temp_name;
	char	*temp_value;
	char	*sub_export;
	char	**array_export;
	char	*sub_unset;
	char	**array_unset;
	char	**pipe_array;
	t_list	**pipe_list;
	int		fd_redir_in;
	char	*temp_sub_redir_in;
	char	*temp_sub_redir_out;
	char	*temp_lst;
	t_list	*temp2_lst;
	char	*temp3_lst;
}	t_envp;

// init
t_envp	*init_envp(char **envp);
t_envp	*init(char **envp);

// envp_utils
int		env_len(char **envp);
int		ft_var_is_in_env(char *env_var, char *my_var);
int		get_index(char *var_name, t_envp *s_envp);
void	realloc_env_array_export(t_envp *s_envp);
void	realloc_env_array_unset(t_envp *s_envp);
char	**sort_envp(char **envp);
void	print_export(t_envp *s_envp);

// signals
void	ft_signals(int signum);

// parsing_command
void	parsing_command(t_envp *s_envp);

// utils
int		count(char *str, char c);
char	*sub_redir(char **str, int i, t_envp *s_envp);
int		ft_is_only_spaces(char *str);
void	ft_close_fd(void);
int		path_exists(t_envp *s_envp);

// utils 2
char	*sub_before_redir_out(char *str, char c, t_envp *s_envp);
char	*sub_without_redir_in(char *str, char c, t_envp *s_envp);
int		ft_strlen_redir(char *str);

// exec_simple
int		run_child(char **parse, t_envp *s_envp);
void	run_simple(char *str, t_envp *s_envp);

// find_path
char	*check_path(char *command, int i, t_envp *s_envp);
char	*find_path(char *command, t_envp *s_envp);

// free
void	ft_free_str(char **str);
void	ft_free_list(t_list **list);
void	ft_free_env(t_envp *s_envp);
void	ft_lstdelete(t_list *lst);
void	ft_free_redir_in(t_envp *s_envp);

// free 2
void	ft_free_error_malloc(t_envp *s_envp);
void	ft_free_redir_out(t_envp *s_envp);

// is_builtin
int		is_builtin(char *command, t_envp *s_envp);
void	run_builtin(char *str, t_envp *s_envp);

// is_echo
int		is_echo(char *str, t_envp *s_envp);

// run cd
void	run_cd(char *command);

// export
void	run_export(char *str, t_envp *s_envp);
void	run_export2(char *sub2, t_envp *s_envp);
void	export_with_equal(char **str, t_envp *s_envp, int i);
void	ft_export(char *var_name, char *var_val, t_envp *s_envp);

// utils 3
int		ft_strlen_equal(char *str);
int		parse_pipe(char *str);
int		event(void);

// export_exec
void	export_exec_exist(char *var_name, char *var_val, t_envp *s_envp, int i);
void	export_exec_non_existent(char *var_name, char *var_val,	
			t_envp *s_envp, int i);

// run env
void	run_env(char *command, t_envp *s_envp);

// run pwd
void	run_pwd(char *temp);

// echo
void	run_echo(char *str, t_envp *s_envp);
void	echo_management(char *str, t_envp *s_envp);
// echo_utils
int		check_flag_n(char *str);
int		check_flag_n_empty(char *str);
void	exec_echo_without_n(char *str, t_envp *s_envp);
void	exec_echo_with_n(char *str, t_envp *s_envp);
void	print_echo_single_quote(char *str, int *i);
void	print_echo_double_quote(char *str, int *i, t_envp *s_envp);
void	echo_dollar_env(char *str, int *i, t_envp *s_envp);

// check_quotes
int		check_quotes(char *str, t_envp *s_envp);

//unset
void	run_unset(char *str, t_envp *s_envp);

// exit
int		run_exit(char *str, t_envp *s_envp);

// redir
void	run_redir(t_envp *s_envp);
void	redir_in(int i, t_envp *s_envp);
void	redir_out(int i, t_envp *s_envp);
void	redir2_out_handle(int i, t_envp *s_envp);
void	redir_out_handle(int i, t_envp *s_envp);
int		check_another_redir(t_envp *s_envp, int i);
void	redir2_in_handle(int i, t_envp *s_envp);
void	redir_in_handle(int i, t_envp *s_envp);
void	mixed_redir(char *str, char *temp, int fd, t_envp *s_envp);
void	mixed_redir2(char *str, char *temp, int fd, t_envp *s_envp);
void	here_doc(char *file, char *eof);
void	exec_dir(char *str, int fd, int i, t_envp *s_envp);
void	exec_redir(char *str, int fd, int new_fd, t_envp *s_envp);

// lst
t_list	**add_list(char **pipe_ar, t_list **lst, t_envp *s_envp);

// pipe
void	run_pipe(char *str, int n_pipe, t_envp *s_envp);
void	pipe_handler(t_list **mini, int countpipe, t_envp *s_envp);
void	exec_pipe(int *fd, int j, t_list *temp, t_envp *s_envp);

// quotes_management
char	*remove_quotes_specific(char *str, t_envp *s_envp);
int		get_index_max_quote(char *str);
char	*remove_quotes(char *str, t_envp *s_envp);
int		count_quotes(char *str);	

#endif