/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:54:00 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/16 13:58:06 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define NC			"\e[0m"
# define BRED		"\e[1;31m"
# define GREEN		"\e[32m"
# define BGREEN		"\e[1;32m"
# define BYELLOW	"\e[1;33m"
# define PURPLE		"\e[35m"
# define BPURPLE	"\e[1;35m"

# define MAX_ARGS	256
# define MAX_LINE	2048

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_meta {
	int		sgl_quote;
	int		dbl_quote;
	int		input_redir;
	int		output_redir;
	int		pipe;
}				t_meta;

typedef struct s_tokenizer
{
	char	**tokens;
	char	*current_token;
	int		current_token_len;
	int		token_count;
	char	quote_char;
}				t_tokenizer;

typedef struct s_command{
	char			**env;
	char			*raw_input;
	char			**args;
	int				arg_count;
	int				quote_pos_arg;
	t_meta			*meta;
	t_tokenizer		*tokens;
	char			*input_file;
	char			*output_file;
}				t_command;

typedef enum e_tokentype {
	TOKEN_DBL_QUOTE,
	TOKEN_SGL_QUOTE,
	TOKEN_PIPE,
	TOKEN_SGL_OUTPUT,
	TOKEN_SGL_INPUT,
	TOKEN_DBL_OUTPUT,
	TOKEN_DBL_INPUT,
}				t_tokentype;


typedef struct s_env{
	char			*var;
	struct s_env	*next;
}				t_env;

typedef struct s_env_list{
	t_env	*head;
}			t_env_list;

//minishell
int			prompt(char *input, char **env, t_env_list *env_list);
char		**tokenizer(char *user_input);

//EXECUTION
int			execution(t_command *command, t_env_list *env_list);
void		exec_cmd_with_redirection(char *cmd_path, char **cmd, \
							char *input_file, char *output_file);
char		*path_control(char *cmd_path, char **paths, t_command *cmd);
char		*check_acces(char *cmd_path);
char		*get_cmd_path(char **paths, char *cmd);
void		exec_builtin_with_redirection(t_command *cmd, t_env_list *env_list);
void		execute_with_pipe(t_command	*cmd, t_tokenizer *t);

//PARSER
t_command	*parser(char *user_input, char **env);

// BUILTINS
int			check_builtins(t_command *command);
void		exec_builtin(t_command *cmd, t_env_list *env_list);
void		echo_builtin(char	**args);
void		cd_builtin(char	**args);
void		pwd_builtin(void);
void		export_builtin(char **args, t_env_list *env_list);
void		unset_builtin(char *var_name, t_env_list *env_list);
void		env_builtin(t_env_list *env_list);
void		exit_builtin(void);

//META_CHAR
int			check_meta(char	*user_input, t_command *command);
int			check_quotes(char *input, t_meta *meta);
int			check_redirections(char *input, t_meta *meta);
int			check_pipe(char *input, t_meta *meta);
t_meta		*init_cmd_meta(void);
void		end_token(t_tokenizer *t);
void		handle_quote(char user_char, t_tokenizer *t);
void		handle_meta(char user_char, t_tokenizer *t);
void		handle_space(t_tokenizer *t);
void		handle_others(char user_char, t_tokenizer *t);

//ENVIRONMENT
t_env_list	dup_env(char **env);
char		*get_env_value(t_env *env_list, char *var_name);

//REDIRECTIONS
void		handle_redirection(t_command *cmd, char **tokens, int token_count);

#endif
