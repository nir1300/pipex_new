/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:49 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/19 18:30:50 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void ft_f(void *lst)
// {
//     while (*(char*)lst)
//     {
//         if (*(char*)lst >= 'a' && *(char*)lst <= 'z')
//             *(char*)lst -= 32;
//         *(char *)lst++;
//     }

// }

// int main(void)
// {
//     char *content = ft_strdup("hello");
//     t_list *first = ft_lstnew(content);
//     ft_lstadd_back(&first, ft_lstnew(ft_strdup(" there")));
//     ft_lstiter(first, ft_f);
//     while (first != NULL)
//     {
//         printf("%s", (char *)first->content);
//         first=first->next;
//     }
// }