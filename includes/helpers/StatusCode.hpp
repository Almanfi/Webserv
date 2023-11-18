/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elasce <elasce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:47:31 by maboulkh          #+#    #+#             */
/*   Updated: 2023/11/18 18:40:27 by elasce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>
#include <wait.h>
#include <errno.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdio>
#include <map>
#include <cstring>

class StatusCode
{
private:
    std::map<std::string, std::string> reasonPhrase;
public:
    StatusCode();
    ~StatusCode();
    std::string statusLine(std::string& code);
};
