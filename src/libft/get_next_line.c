/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:57:58 by jukim             #+#    #+#             */
/*   Updated: 2018/04/19 18:29:18 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*data[1024];
	char		*temp;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (data[fd] == NULL)
			data[fd] = ft_strnew(1);
		temp = ft_strjoin(data[fd], buf);
		ft_strdel(&data[fd]);
		data[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && data[fd] == NULL)
		return (0);
	return (get_line(fd, data, line));
}

/*
** if failed to open (fd = -1) OR buffer size is
** less than 1 OR the line is empty
**
** while the file contains more than 0 byte;
** reads bytes from the buffer(file)
**
** 		set '\0' at the end of buffer
**
** 		create a new string with a fresh memory area with the size of 2
**
** 		insert buffer into data[fd] and let that become temp
**
** 		free and empty data[fd]
**
** 		let an empty array, data[fd], be temp
**
** 		if '\n' is found in buffer, break loop
**
** if the file could not be read (ret < 0) return (-1)
**
** if the file has 0 byte and data[fd] is empty return (0)
**
** if get_line return (1), return (1)
*/

int	get_line(int fd, char **data, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while (data[fd][i] != '\n' && data[fd][i] != '\0')
		i++;
	if (data[fd][i] == '\n')
	{
		*line = ft_strsub(data[fd], 0, i);
		temp = ft_strdup(data[fd] + i + 1);
		ft_strdel(&data[fd]);
		data[fd] = temp;
		if (data[fd][0] == '\0')
			ft_strdel(&data[fd]);
	}
	else if (data[fd][i] == '\0')
	{
		*line = ft_strdup(data[fd]);
		ft_strdel(&data[fd]);
	}
	return (1);
}
/*
** while the data from fd isn't '\n' and '\0',
** keep moving on to the next character
**
** if data at fd read '\n'
**
** 		set a line from input as a string
**
** 		set temp to data[fd] excluding line
**
** 		free data[fd] and set it NULL
**
** 		set data[fd] to temp
**
** 		if the data[fd][0] becomes '\0', free data[fd]
**
** else if data at fd read '\0'
**
** 		copy the last line from the data to *line
**
** 		free data[fd] and set it NULL
**
** return 1
*/
