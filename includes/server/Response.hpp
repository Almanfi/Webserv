/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulkh <maboulkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:59 by maboulkh          #+#    #+#             */
/*   Updated: 2023/11/20 07:00:04 by maboulkh         ###   ########.fr       */
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
#include <ctime>
#include "../helpers/StatusCode.hpp"

class Response
{
private:
    std::map<std::string, std::string> ResponseHeader;
    std::string _header;
    std::ifstream file;
    // std::string body;
    // std::string fileName;
    std::string code;
    std::string data;
    size_t size;

    std::string findType(std::string& fileName);
    std::string findType(const char* FileName);
    std::string date();
    std::string contentLength();
    std::string newUrl();
    std::string AllowedMethod();
public:
    // Response(std::string& body);
    Response(std::string& code, std::string& data);
    ~Response();
    std::string header();
    std::string body();
    size_t write(char *buffer, size_t size);
};
