/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulkh <maboulkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:42:29 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/20 05:00:15 by maboulkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./socket.hpp"
#include "./loadbalancer.hpp"
#include "./client.hpp"
#include "./cgi.hpp"
#include "./Response.hpp"

Socket   *server_init(const string host,const string port);
void     server_listen(Socket *server);