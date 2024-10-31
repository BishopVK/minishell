/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:52:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/24 14:32:18 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INCLUDES

//libft
#include "libft/libft.h"

//max int y min int
#include <stdint.h>
#include <limits.h>

// printf, readline, perror
#include <stdio.h>

// rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
#include <readline/readline.h>
#include <readline/history.h>

// malloc, free, exit, getenv
#include <stdlib.h>

// write, access, read, close, fork, getcwd, chdir, unlink, execve, dup, dup2,
// pipe, isatty, ttyname, ttyslot, tcsetattr, tcgetattr
#include <unistd.h>

// open, stat, lstat, fstat
#include <sys/stat.h>
#include <fcntl.h>

// wait, waitpid, wait3, wait4
#include <sys/wait.h>

// signal, sigaction
#include <signal.h>

// opendir, readdir, closedir
#include <sys/types.h>
#include <dirent.h>

// strerror
#include <string.h>

// ioctl
#include <sys/ioctl.h>

// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
#include <curses.h>
#include <term.h>

// errno
#include <errno.h>

// DEFINES
#define MAX_ARGS 70000
#define PATH "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

// ANSI escape sequences for colors
#define RESET "\001\033[0m\002"
#define RED "\001\033[31m\002"
#define GREEN "\001\033[32m\002"
#define YELLOW "\001\033[33m\002"
#define BLUE "\001\033[34m\002"
#define MAGENTA "\001\033[35m\002"
#define CYAN "\001\033[36m\002"
#define WHITE "\001\033[37m\002"
#define BOLD "\001\033[1m\002"

// GLOBAL VARIABLES
extern volatile sig_atomic_t	g_signal_received;

typedef enum e_param_type
{
	CMD,
	INFILE,
	HERE_DOC,
	DELIMITER,
	OUTFILE,
	APPEND,
	PIPE,
	PARAMS,
	BUILTING
}	t_param_type;

typedef struct s_env
{
	char			*variable;
	char			*content;
	int				order;
	struct s_env	*next;
}			t_env;

typedef struct s_execution
{
	int					n_command;
	char				**command;
	t_param_type		type;
	int					inf_pipe;
	int					outf_pipe;
	struct s_execution	*next;
}						t_execution;

typedef struct s_mini
{
	char		*user_prompt;
	t_execution	*exe_command;
	int			n_here_docs;
	t_list		*here_doc_files;
	int			n_commands;
	char		**env;
	int			nbr_env_nodes;
	t_env		*env_first_node;
	t_env		*env_iter;
	int			standard_fds[2];
}				t_mini;

typedef struct s_params
{
	char			*content;
	int				argc;
	t_param_type	type;
	t_bool			quotes;
	struct s_params	*next;
}	t_params;

typedef struct s_args
{
	char		*input;
	char		*input_trimed;
	char		*last_history;
	char		*args[MAX_ARGS];
	t_bool		quotes[MAX_ARGS];
	int			argc;
	char		*arg;
	char		*result;
	size_t		result_capacity;
	t_mini		*mini;
	char		*arg_ptr;
	t_bool		in_single_quote;
	t_bool		in_double_quote;
	t_bool		in_heredoc;
	t_params	*params;
}	t_args;

/*_____           _        _                         
 |  __ \         | |      | |                        
 | |__) | __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
 |  ___/ '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
 | |   | | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
 |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
                                __/ | |              
                               |___/|_|            */

// ╔═.✵.═════════════════════════════════════════════╗
// 					MAIN FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//					ERRORS_AND_EXIT.C				//
//////////////////////////////////////////////////////
void		free_args_at_exit(t_args *args);
void		free_at_exit(t_args *args);
void		error_mini_use(int argc, char **argv);
void		free_args_in_syntax_error(t_args *args);
int			closing_minishell(int is_piped, t_args *args);

//////////////////////////////////////////////////////
//				SIGNALS_AND_HISTORY.C				//
//////////////////////////////////////////////////////
void		signal_sigint(int sig);
void		handle_eof(void);
void		signal_here_doc(int sig);
void		histcontrol(t_args *args);

//////////////////////////////////////////////////////
//					INITIALIZE_MAIN.C				//
//////////////////////////////////////////////////////
void		initialize_structs(t_args *args, t_mini *mini, char **env);
void		create_minim_env_vars(t_mini *mini);
int			create_prompt(t_mini *mini);
int			initialize_main_loop(t_mini *mini, t_args *args, int is_piped);
void		trim_input(t_args *args);

// ╔═.✵.═════════════════════════════════════════════╗
// 					PARSE FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//						PARSE.C						//
//////////////////////////////////////////////////////
int			ft_tokenize(t_args *args, t_mini *mini);
int			parse(t_args *args, t_mini *mini);

//////////////////////////////////////////////////////
//					FT_TOKENIZE.C					//
//////////////////////////////////////////////////////
int			add_to_args(t_args *args, int *argc, t_mini *mini);

//////////////////////////////////////////////////////
//				TOKENIZE_OUT_OF_QUOTES.C			//
//////////////////////////////////////////////////////
int			out_of_quotes(char **input_ptr, t_args *args,
				int *argc, t_mini *mini);

//////////////////////////////////////////////////////
//					FT_RETOKENIZE.C					//
//////////////////////////////////////////////////////
int			ft_retokenize(t_params *params);

//////////////////////////////////////////////////////
//					EXPANDER.C						//
//////////////////////////////////////////////////////
char		*expander(t_args *args, t_mini *mini);

//////////////////////////////////////////////////////
//				EXPANDER_UTILS.C					//
//////////////////////////////////////////////////////
char		*expand_vars(t_args *args, size_t *i, size_t *j, t_mini *mini);
void		copy_chars_unless_its_quote(t_args *args, size_t *i, size_t *j);

//////////////////////////////////////////////////////
//				LIST_OF_PARAMS.C					//
//////////////////////////////////////////////////////
void		update_last_command_env_var(t_args *args);
void		del_params(t_args *args);
t_params	*add_argument_to_list(t_args *args, int *argc,
				t_bool *heredoc_found);

// ╔═.✵.═════════════════════════════════════════════╗
// 					ENV FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//					FT_LIST_ENV.C					//
//////////////////////////////////////////////////////
char		*ft_find_env(t_mini *mini, char *find);
void		free_env(t_mini *mini);
int			add_back_env(t_env *node, t_mini *mini);
t_env		*env_new(char *env);

//////////////////////////////////////////////////////
//					FT_ENV.C						//
//////////////////////////////////////////////////////
void		ft_export_env(char *new_env, t_mini *mini);
char		*ft_get_env(char *to_expand, t_mini *mini);
int			ft_set_env(char **env, t_mini *mini);

//////////////////////////////////////////////////////
//					FT_ENV_UNSET.C					//
//////////////////////////////////////////////////////
void		ft_unset_env(char *unset, t_mini *mini);

// ╔═.✵.═════════════════════════════════════════════╗
	// 				BUILT-INS FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//					FT_ECHO.C						//
//////////////////////////////////////////////////////
int			ft_built_echo(char **args);

//////////////////////////////////////////////////////
//					FT_EXIT.C						//
//////////////////////////////////////////////////////
int			ft_built_exit(t_args *args, char **exit_args);

//////////////////////////////////////////////////////
//					FT_EXPORT.C						//
//////////////////////////////////////////////////////
int			ft_built_export(char **args, t_mini *mini);

//////////////////////////////////////////////////////
//				FT_EXPORT_UTILS.C					//
//////////////////////////////////////////////////////
int			handle_first_letter(char **args, int *i, int *exit_status);
int			find_equal(char **args, int *i, int *j);
void		not_equal_case(char **args, int *i, t_mini *mini, int *exit_status);
int			equal_case(char **args, int *i, t_mini *mini, int *pos_equal);
int			loop_args(char	**args, t_mini *mini, int *i, int *exit_status);

//////////////////////////////////////////////////////
//					FT_UNSET.C						//
//////////////////////////////////////////////////////
int			ft_built_unset(char **args, t_mini *mini);

//////////////////////////////////////////////////////
//					FT_PWD.C						//
//////////////////////////////////////////////////////
int			ft_built_pwd(char **args, t_mini *mini);

//////////////////////////////////////////////////////
//					FT_CD.C							//
//////////////////////////////////////////////////////
int			ft_built_cd(char **args, t_mini *mini);

//////////////////////////////////////////////////////
//					FT_ENV.C						//
//////////////////////////////////////////////////////
int			ft_built_env(char **args, t_mini *mini);

// ╔═.✵.═════════════════════════════════════════════╗
//					HERE_DOC FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//						HERE_DOC.C					//
//////////////////////////////////////////////////////
int			*get_here_doc(t_params *iter_params, t_args *args, int i);

//////////////////////////////////////////////////////
//					HERE_DOC_LOOP.C					//
//////////////////////////////////////////////////////
int			here_doc_loop(int fd, t_params *param, t_mini *mini);

// ╔═.✵.═════════════════════════════════════════════╗
//					REDIRECTOR FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//					NEW_RED_EXE.C					//
//////////////////////////////////////////////////////
int			new_red_exe(t_args *args, t_mini *mini);
void		close_inf_outf(t_mini *mini);
void		dup_redirections(t_execution *iter_exe);

//////////////////////////////////////////////////////
//					REDIRECTOR.C					//
//////////////////////////////////////////////////////
int			errors_and_n_commands(t_params *iter, t_mini *mini);
int			fill_exe_redirections(t_params *iter_params,
				t_execution *iter_exe, t_args *args, t_mini *mini);

//////////////////////////////////////////////////////
//				FIND_REDIRECTIONS.C					//
//////////////////////////////////////////////////////
void		fill_infile(t_params *iter_params,
				t_execution *iter_exe, t_mini *mini);
void		fill_here_doc(int fd, t_execution *iter_exe, t_mini *mini);
void		fill_append(t_params *iter_params,
				t_execution *iter_exe, t_mini *mini);
void		fill_outfile(t_params *iter_params,
				t_execution *iter_exe, t_mini *mini);
void		fill_pipe(t_execution *iter_exe);

// ╔═.✵.═════════════════════════════════════════════╗
//					EXECUTION FOLDER
// ╚═════════════════════════════════════════════.✵.═╝

//////////////////////////////////////////////////////
//				EXECUTION_STRUCTURE.C				//
//////////////////////////////////////////////////////
int			create_execution_struct(t_mini *mini);
void		exe_struct_free(t_mini *mini);

//////////////////////////////////////////////////////
//					START_EXECUTING.C				//
//////////////////////////////////////////////////////
int			start_executing(t_execution *iter_exe, int status,
				t_mini *mini, t_args *args);

//////////////////////////////////////////////////////
//				EXECUTE_COMMANDS.C					//
//////////////////////////////////////////////////////
int			execute(t_execution *iter_exe, t_mini *mini, t_args *args);
void		close_restant_fds(t_execution *exe_command, t_mini *mini, int i);
void		free_last_env(t_mini *mini);

//////////////////////////////////////////////////////
//					FIND_PATH.C						//
//////////////////////////////////////////////////////
char		*get_path_command(char **kid, char **env, char *path_mid);
void		fill_exe(t_params *iter_params, t_execution *iter_exe);

//////////////////////////////////////////////////////
//				EXECUTION_UTILS.C					//
//////////////////////////////////////////////////////
int			check_built_ins(char **command, t_execution *iter_exe,
				t_mini *mini, t_args *args);
int			be_built_ins(char **command);
int			create_fork(t_execution *iter_exe, t_mini *mini, t_args *args,
				int exit_status);
void		close_fds(t_execution *iter_exe);
