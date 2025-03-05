/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:45 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 18:30:46 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

// int main(void)
// {
// 	char *content = "hello";
// 	t_list *first = ft_lstnew(content);
// 	ft_lstadd_back(&first, ft_lstnew("bye"));
// 	t_list *last = ft_lstlast(first);
// 	printf("%s", (char *)last->content);
// }
