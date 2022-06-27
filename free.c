/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:24:41 by anggonza          #+#    #+#             */
/*   Updated: 2022/06/27 12:41:47 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	empty_env_element(void *element)
{
	t_env	*_element;

	_element = (t_env *)element;
	free(_element->variable);
	if (_element->value)
		free(_element->value);
	free(_element);
}

void	free_env(t_list **list)
{
	ft_lstclear(list, &empty_env_element);
}

void	ft_free_list(t_list **liste)
{
	t_list	*temp;

	while (*liste)
	{
		temp = *liste;
		*liste = (*liste)->next;
		free(temp);
	}
	liste = NULL;
}

void	free_lexer(t_list **lexer)
{
	t_list	*tmp;

	tmp = NULL;
	while (*lexer)
	{
		free(((t_lexer *)((*lexer)->content))->text);
		free((t_lexer *)((*lexer)->content));
		tmp = *lexer;
		*lexer = (*lexer)->next;
		free(tmp);
	}
}
