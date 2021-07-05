/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:59 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/06 00:10:55 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <sys/signal.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	error_exit(int *tem);

#endif
