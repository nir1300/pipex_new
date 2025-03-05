/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:39 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 18:30:40 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = (t_list *)malloc(sizeof(t_list));
	if (first == NULL)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*content;
	t_list	*wut;

	content = "hello";
	wut = ft_lstnew(content);
	while (wut != NULL)
	{
		printf("%s", (char *)wut->content);
		wut = wut->next;
	}
}
*/
