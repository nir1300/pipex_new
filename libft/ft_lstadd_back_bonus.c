/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:31:17 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/25 20:54:33 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst != NULL)
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
	else
		*lst = new;
}

/*
int	main(void)
{
	char	*content;
	t_list	*first;

	content = "hello";
	first = ft_lstnew(content);
	ft_lstadd_back(&first, ft_lstnew(" there "));
	ft_lstadd_back(&first, ft_lstnew("loser"));
	while (first != NULL)
	{
		printf("%s", (char *)first->content);
		first = first->next;
	}
}
*/
