/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:53 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/25 16:46:46 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	del(void *content)
{
	free(content);
}

/* #include <stdio.h>

int	main(void)
{
	char	*content;
	t_list	*first;
	t_list	*second;
	t_list	*third;

	content = "get in loser, ";
	first = ft_lstnew(content);
	second = ft_lstnew(ft_strdup("delete"));
	// why wont it work without strdup??
	third = ft_lstnew("we're going shopping");
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);
	ft_lstdelone(second, del);
	if (first)
		printf("%s", (char *)first->content);
	if (second)
		printf("%s", (char *)second->content);
	if (third)
		printf("%s", (char *)third->content);
} */
