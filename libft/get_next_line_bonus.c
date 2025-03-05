/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:57:04 by codespace         #+#    #+#             */
/*   Updated: 2024/11/25 20:55:01 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_bonus(int fd)
{
	static char	*dest[1024];
	char		*ret_line;
	char		*buf;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!dest[fd])
	{
		dest[fd] = ft_strdup("");
		if (!dest[fd])
			return (NULL);
	}
	dest[fd] = read_lines(fd, dest[fd], buf);
	if (!dest[fd])
		return (NULL);
	ret_line = create_line(dest[fd]);
	if (!ret_line)
		return (ft_free(dest[fd], NULL, 0));
	dest[fd] = ft_remainder(dest[fd]);
	return (ret_line);
}

/*
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
}
*/