/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:59 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/02 13:45:36 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <sys/signal.h>
# include <unistd.h>
# include <stdlib.h>

//utils
char		*ft_itoa(int n);
size_t	ft_strlen(char const *str);
int		ft_atoi(const char *str);

#endif