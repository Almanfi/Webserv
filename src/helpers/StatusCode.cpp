/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulkh <maboulkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:04:08 by maboulkh          #+#    #+#             */
/*   Updated: 2023/11/17 21:05:27 by maboulkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

StatusCode::StatusCode()
{
    reasonPhrase["100"] = "Continue";
    reasonPhrase["101"] = "Switching Protocols";
    reasonPhrase["200"] = "OK";
    reasonPhrase["201"] = "Created";
    reasonPhrase["202"] = "Accepted";
    reasonPhrase["203"] = "Non-Authoritative Information";
    reasonPhrase["204"] = "No Content";
    reasonPhrase["205"] = "Reset Content";
    reasonPhrase["206"] = "Partial Content";
    reasonPhrase["300"] = "Multiple Choices";
    reasonPhrase["301"] = "Moved Permanently";
    reasonPhrase["302"] = "Found";
    reasonPhrase["303"] = "See Other";
    reasonPhrase["304"] = "Not Modified";
    reasonPhrase["305"] = "Use Proxy";
    reasonPhrase["307"] = "Temporary Redirect";
    reasonPhrase["400"] = "Bad Request";
    reasonPhrase["401"] = "Unauthorized";
    reasonPhrase["402"] = "Payment Required";
    reasonPhrase["403"] = "Forbidden";
    reasonPhrase["404"] = "Not Found";
    reasonPhrase["405"] = "Method Not Allowed";
    reasonPhrase["406"] = "Not Acceptable";
    reasonPhrase["407"] = "Proxy Authentication Required";
    reasonPhrase["408"] = "Request Timeout";
    reasonPhrase["409"] = "Conflict";
    reasonPhrase["410"] = "Gone";
    reasonPhrase["411"] = "Length Required";
    reasonPhrase["412"] = "Precondition Failed";
    reasonPhrase["413"] = "Payload Too Large";
    reasonPhrase["414"] = "URI Too Long";
    reasonPhrase["415"] = "Unsupported Media Type";
    reasonPhrase["416"] = "Range Not Satisfiable";
    reasonPhrase["417"] = "Expectation Failed";
    reasonPhrase["426"] = "Upgrade Required";
    reasonPhrase["500"] = "Internal Server Error";
    reasonPhrase["501"] = "Not Implemented";
    reasonPhrase["502"] = "Bad Gateway";
    reasonPhrase["503"] = "Service Unavailable";
    reasonPhrase["504"] = "Gateway Timeout";
    reasonPhrase["505"] = "HTTP Version Not Supported";
}

std::string StatusCode::statusLine(std::string& code)
{
    std::string line;
    line = "http/1.1"; // serverconfig.httpV();
    line += " " + code + " " + reasonPhrase[code];
    return (line);
}


StatusCode::~StatusCode()
{
}
