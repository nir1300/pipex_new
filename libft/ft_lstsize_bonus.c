/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:32 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/12/05 17:55:01 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *content = "hello, ";
// 	t_list *first = ft_lstnew(content);
// 	ft_lstadd_back(&first, ft_lstnew("how's it going, "));
// 	ft_lstadd_back(&first, ft_lstnew("old sport?"));
// 	printf("%i\n", lstsize(first));
// }