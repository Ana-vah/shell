/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:57:09 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/19 09:55:46 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	execute_with_pipe(t_command	*cmd, t_tokenizer *t)
{
	printf("accessing execute_with_pipe\n");
	if (t != NULL && cmd != NULL)
	{
		printf("t->token_count = %d\n", t->token_count);
		if (cmd != NULL && cmd->meta != NULL)
		{
			printf("cmd->meta->pipe = %d\n", cmd->meta->pipe);
		}
	}
}

/*
void exec_pipeline(t_command **commands, int n, t_env_list *env_list) {
    int i;
    int in = 0;  // The input file descriptor for the first command.
    int fd[2];   // The file descriptors for the pipe.

    for (i = 0; i < n - 1; ++i) {
        pipe(fd);  // Create a new pipe.

        // The new process will write to fd[1] for the next command,
        // and read from in for the current command.
        spawn_proc(in, fd[1], commands[i], env_list);

        // We won't write to the input side of the pipe, so close it.
        close(fd[1]);

        // The next child process will read from the output side of the pipe.
        in = fd[0];
    }

    // The final command reads from the last pipe and writes to STDOUT.
    if (in != 0)
        dup2(in, 0);

    // Now that all the I/O redirections are set up, execute the final command.
    exec_cmd(commands[i]->cmd_path, commands[i]->args);
}

// This function spawns a new process to execute a command, and sets up
// the necessary file descriptor redirections for pipes.
void spawn_proc(int in, int out, t_command *cmd, t_env_list *env_list) {
    pid_t pid;

    if ((pid = fork()) == 0) {
        if (in != 0) {
            // If in is not standard input, replace standard input with in.
            dup2(in, 0);
            close(in);
        }

        if (out != 1) {
            // If out is not standard output, replace standard output with out.
            dup2(out, 1);
            close(out);
        }

        exec_cmd(cmd->cmd_path, cmd->args);
    }
}

*/
