/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:10:27 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 23:22:40 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>

# include "../libft/libft.h"

# define BUFFER_SIZE 1024

# define EMPTY 0
# define IN 1
# define IN_TWO 2
# define OUT 3
# define OUT_TWO 4

# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define DOBINP 6
# define PIPE 7

# define NOT_EXECUTED 0
# define EXECUTED 1

# define DEFAULT 0
# define CHILD 1
# define PARENT 2

# define ER_NON 0
# define ER_MAIN 1
# define ER_MAL 2
# define ER_WRONG_CMD 3
# define ER_DUP 10
# define ER_FORK 11
# define ER_OPEN 12
# define ER_CLOSE 13
# define ER_EXECVE 20
# define ER_PATH 21
# define ER_PIPE 22
# define ER_EXIT 255

# define TMP_PATH "/tmp"
# define TMP_FILE "/_tmpfile_shell"

# define SHLVL_DEFAULT 2

typedef struct s_quotes
{
	bool	dble;
	bool	solo;
}	t_quotes;

typedef struct s_parse
{
	t_quotes	quotes;
	int			i;
	int			begin_str;
	int			pipe;
	int			size;
	bool		flag;
	int			token_amount;
	int			index_token;
}			t_parse;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_env_variable
{
	char	*key;
	char	*val;
}	t_env_variable;

typedef struct s_envs_lst
{
	t_env_variable		*data;
	struct s_envs_lst	*next;
}	t_envs_lst;

typedef struct s_shell
{
	pid_t	pid;
	int		std_in;
	int		std_out;
	int		f_in;
	int		f_out;
	int		process_level;
	int		exit_status;
	char	*tmpfile;
	int		shlvl;
	bool	executed;
	bool	is_running;
}	t_shell;

/* Parsing and tokenize */

// parsing
bool		ft_parse(t_shell *shell, t_envs_lst *env, char *str, char *user);

// pre-parsing
bool		ft_preparse(char *str, char *user);

// check seps and redirects
bool		ft_check_redirect(char *str, int *i, char *user);
bool		ft_check_seps(char *str, int *i, char *user);

// parse handling
int			ft_parse_handling(t_shell *shell, t_envs_lst *env, char *str);

// process tokening
bool		ft_process_tokening(t_shell *shell, char **commands,
				t_envs_lst *env);

// parsing init
t_quotes	ft_quotes_init(void);
t_parse		ft_parse_init(void);

// quotes
void		ft_quotes_plus(t_token *coms);
bool		ft_set_quote_status(t_quotes *quotes, char ch);
bool		ft_is_outside_quotes(t_quotes *quotes);

// parsing utils
bool		ft_strchr_bo(const char *s, int c);
bool		ft_is_whitespace(char c);
bool		ft_skip_tabulation(char *str);
char		*ft_trim_tabulation(char *str);

// split commands
char		**ft_split_command(t_envs_lst *env, char *str,
				t_parse *parse, t_shell *shell);

// get commands
char		**ft_get_commands(char *str, int pipe);

// concat commands
char		*ft_grow_up_str(t_envs_lst *env, char *str,
				t_shell *shell, bool *flag);

// parsing dollar
bool		ft_search_dollar(char *str);
char		*ft_parse_dollar(t_envs_lst *env, t_parse *parse,
				char *str, t_shell *shell);

// create tokens
bool		ft_token_new(char **coms, t_parse *parse, char *str);

// amount tokens
int			ft_token_amount(char *com);

// tolowercase environment (env)
void		ft_low_up_token(char **coms);

// expand quotes for CMD
void		ft_addon_token(t_token *coms);

// token list utils
t_token		*ft_create_token(char *content);
void		ft_tokenadd_back(t_token **lst, t_token *new);

// token conversation to struct
t_token		*ft_conv_to_struct(char **coms, t_token **fin_coms);

void		ft_parse_envs_to_lst(t_envs_lst **envs, char **env);
char		**ft_parse_env_to_arr(t_envs_lst **envs);
void		ft_token_struct_free(t_token *lst);

// replace line (add info)
void		rl_replace_line(const char *text, int clear_undo);

/* Signals */

void		ft_tty_mask(void);
void		ft_start_signals(void);
void		ft_c_handle(int sig);
void		ft_c_handle_fork(int sig);
void		ft_slash_handle_fork(int sig);
void		ft_sig_ignore(int sig);
void		ft_sig_heredoc(int sig);
void		ft_sig_empty(int sig);

/* Utils, builtins, execute */

// src/utils/env_utils_1.c
void		ft_add_env_var(t_envs_lst **envs, char *line);
void		ft_remove_env_var(t_envs_lst **envs, char *key);

// src/utils/env_utils_2.c
char		*ft_search_env_var(t_envs_lst **envs, char *key);
void		ft_free_envs(t_envs_lst **envs);
void		ft_update_shlvl(t_shell *shell, t_token *token, t_envs_lst **env);

// src/utils/check_env.syntax.c
bool		ft_check_env_syntax(char *key);

// src/utils/get_next_line.c
char		*ft_get_next_line(int fd);

// src/utils/print_errno_error.c
void		ft_print_errno_error(t_shell *shell, char *ts, t_envs_lst **envs);

// src/builtins/cd.c
void		ft_cd(t_shell *shell, t_envs_lst **envs, t_token *token);

// src/builtins/cd_utils.c
void		ft_handle_invalid_path(t_shell *shell, t_envs_lst **envs,
				char *path_to_go);
bool		ft_handle_empty_path(t_shell *shell, t_envs_lst **envs);

// src/builtins/echo.c
void		ft_echo(t_shell *shell, t_token *token);

// src/builtins/env.c
void		ft_env(t_shell *shell, t_envs_lst **envs);

// src/builtins/exit.c
void		ft_exit(t_shell *shell, t_envs_lst **envs, t_token *token);

// src/builtins/export.c
void		ft_export(t_shell *shell, t_envs_lst **envs, t_token *token);

// src/builtins/export_utils.c
char		**ft_get_sorted_keys(t_envs_lst **envs);
void		ft_free_sorted_keys(char **keys, int size);
void		ft_handle_export_error(t_shell *shell, t_envs_lst **envs,
				t_token *token);

// src/builtins/pwd.c
void		ft_pwd(t_shell *shell);

// src/builtins/unset.c
void		ft_unset(t_shell *shell, t_envs_lst **envs, t_token *token);

// src/execute/bin_utils.c
void		ft_launch_execve(t_envs_lst *env, char **args);
void		ft_set_signals(t_token *token);

// src/execute/execute_token.c
int			ft_check_pipe_io(t_shell *shell, t_token *prev);
bool		ft_execute_token(t_shell *shell, t_token *token, t_envs_lst *env);

// src/execute/get_tokens.c
t_token		*ft_get_prev_token(t_token	*token);
t_token		*ft_get_next_token(t_token	*token);

// src/execute/handle_path_var.c
void		ft_free_paths(char **paths, char *cmd_with_slash);

// src/execute/handle_redirects.c
bool		ft_prev_redirect(t_token *token);
void		ft_handle_redirections(t_shell *shell, t_token *token);
void		ft_handle_input(t_shell *shell, t_token *token, t_envs_lst *env);
void		ft_handle_dobinp(t_shell *shell, t_token *token, t_envs_lst *env);
int			ft_handle_pipe(t_shell *shell);

// src/execute/execute_cmd.c
void		ft_execute_cmd(t_shell *shell, t_token *token, t_envs_lst *env);

// src/execute/execute_builtins.c
bool		ft_is_builtin(t_token *token);
void		ft_execute_builtins(t_shell *shell, t_token *token,
				t_envs_lst *env);

// src/execute/execute_bins.c
void		ft_execute_bins(t_shell *shell, t_token *token, t_envs_lst *env);

// src/execute/redirect_utils.c
void		ft_handle_child_dobinp(int fd, char *eof);
void		ft_handle_parent_dobinp(t_shell *shell, int fd, pid_t pid,
				t_envs_lst *env);
int			ft_handle_child_pipe(t_shell *shell, int *fd);
int			ft_handle_parent_pipe(t_shell *shell, int *fd, pid_t pid);
int			ft_check_redirect_type(t_shell *shell, t_token *token,
				t_token *prev, t_envs_lst *env);

// errors/errors_1.c
void		ft_malloc_error(void);
void		ft_dup_error(void);
void		ft_fork_error(void);
void		ft_open_error(void);

// errors/errors_2.c
void		ft_close_error(void);
void		ft_execve_error(void);
void		ft_path_error(void);
void		ft_pipe_error(void);

#endif
