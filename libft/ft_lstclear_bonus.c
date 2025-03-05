/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:39:06 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/11/25 16:27:13 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && *lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp;
		}
		*lst = NULL;
	}
}

// #include <stdio.h>

// void del(void *content)
// {
//     free(content);
// }

// int	main(void)
// {
// 	char	*content = "get in loser, ";
// 	t_list	*first = ft_lstnew(ft_strdup(content));
//     t_list *second = ft_lstnew(ft_strdup("delete"));
//     t_list *third = ft_lstnew(ft_strdup("we're going shopping"));

//     ft_lstadd_back(&first, second);
// 	ft_lstadd_back(&first, third);
//     ft_lstclear(&second, del);
// 	if (first)
//         printf("%s", (char *)first->content);
//     else
//         printf("NULL");
//     if (second)
//         printf("%s", (char *)second->content);
//     else
//         printf("NULL");
//     if (third)
//         printf("%s", (char *)third->content);
//     else
//         printf("NULL");
// }