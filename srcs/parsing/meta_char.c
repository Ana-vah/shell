/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:28:51 by vdescamp          #+#    #+#             */
/*   Updated: 2023/06/16 13:36:37 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

static t_meta	*malloc_command(void)
{
	t_meta	*meta;

	meta = (t_meta *)malloc(sizeof(t_meta));
	if (!meta)
	{
		perror("malloc");
		exit(1);
	}
	return (meta);
}

t_meta	*init_cmd_meta(void)
{
	t_meta	*meta;

	meta = malloc_command();
	meta->input_redir = 0;
	meta->output_redir = 0;
	meta->pipe = 0;
	meta->sgl_quote = 0;
	meta->dbl_quote = 0;
	return (meta);
}

int	check_meta(char *user_input, t_command *cmd)
{
	t_meta	*meta;

	meta = cmd->meta;
	if (check_quotes(user_input, meta))
		return (1);
	check_redirections(user_input, meta);
	check_pipe(user_input, meta);
	return (0);
}
