/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:31:23 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 18:31:19 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	char	*content;
// 	t_list	*first;

// 	content = "hello";
// 	first = ft_lstnew(content);
// 	ft_lstadd_front(&first, ft_lstnew(" there "));
// 	ft_lstadd_front(&first, ft_lstnew("loser"));

// 	while (first != NULL)
// 	{
// 		printf("%s", (char *)first->content);
// 		first=first->next;
// 	}
// }