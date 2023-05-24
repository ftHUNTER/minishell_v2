/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:22:16 by rchmouk           #+#    #+#             */
/*   Updated: 2023/05/24 07:54:06 by rchmouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int				*tab;
	char			**name;
	char			**arg;
	struct s_list	*next;
}					t_parc;

typedef struct s_index
{
	int				index;
	int				arg_i;
}					t_index;

typedef struct s_count
{
	int				count_dir;
	int				count_arg;
}					t_count;

typedef struct s_list2
{
	char			*var;
	char			*val;
	struct s_list2	*next;
}					t_env;

int					*string_to_nbr(char *str);
int					*string_to_nbr2(char *str);
char				**p_split_pro(char *str, int len);
t_parc				*ft_fill_lst(char **container);
void				ft_lst_add_back(t_parc *lst, t_parc *new);
void				free_all(t_parc *all, char **container, char *buffer);
int					ft_count_arg(char **container, int j);
void				count_dir(int *j, int *count_dir, int count_arg,
						char **cont);
void				remoev_cout(t_parc *all);
void				ft_lst_add_back2(t_env *lst, t_env *new);
t_env				*ft_fill_lst2(char **env);
char				*ft_expand(char *str, t_env *env, int i);
void				str_free(char *s1, char *s2, char *s3, char *s4);
char				*replace_free(char *s1, char *env);

#endif