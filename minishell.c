/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:19:17 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/24 21:48:58 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_parc	*all;
	char	*buffer;
	char	**container;
	int		len;
	t_env	*env_list;
	t_parc	*tmp;
	int		i;
	int		j;

	env_list = ft_fill_lst2(env);
	while (ac && av)
	{
		buffer = readline(">minishell: ");
		if (buffer != NULL && buffer[0])
		{
			add_history(buffer);
			buffer = ft_expand(buffer, env_list, 0);
			len = ft_strlen(buffer);
			container = p_split_pro(buffer, len);
			all = ft_fill_lst(container);
			remoev_cout(all);
			i = 0;
			tmp = all;
			j = 0;
			while (tmp)
			{
				i = 0;
				j = 0;
				while (tmp->arg[i])
					printf("%s\n", tmp->arg[i++]);
				printf("-------\n");
				while (tmp->name[j])
					printf("%s\n", tmp->name[j++]);
				printf("==============================\n");
				tmp = tmp->next;
			}
			free_all(all, container, buffer);
		}
		if (buffer == NULL)
			printf("\n");
	}
}
