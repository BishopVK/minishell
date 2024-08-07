/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:52:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/07/22 13:56:16 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DEFINES

//libft
#include "libft/libft.h"

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

// Secuencias de escape ANSI para colores
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

// DEFINES
/* #define NUM_THREADS 5 */

// STRUCTURES

typedef enum s_bool
{
	t_false,
	t_true,
}	t_bool;


typedef struct s_fd
{
	int		inf;
	int		outf;
}	t_fd;

typedef struct s_mini
{
	int		pipes;
	t_fd	in_out;
}	t_mini;

/*_____           _        _                         
 |  __ \         | |      | |                        
 | |__) | __ ___ | |_ ___ | |_ _   _ _ __   ___  ___ 
 |  ___/ '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|
 | |   | | | (_) | || (_) | |_| |_| | |_) |  __/\__ \
 |_|   |_|  \___/ \__\___/ \__|\__, | .__/ \___||___/
                                __/ | |              
                               |___/|_|            */

//////////////////////////////////////////////////////
//						MAIN.C						//
//////////////////////////////////////////////////////
//int		main(void);

//////////////////////////////////////////////////////
//						PARSE.C						//
//////////////////////////////////////////////////////
int		parse(char *input);

//////////////////////////////////////////////////////
//					FT_TOKENIZE.C					//
//////////////////////////////////////////////////////
void	ft_tokenize(char *input, char *args[], int *argc);
//char	**ft_tokenize(char const *s, char c);