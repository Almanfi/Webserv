/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulkh <maboulkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:59 by maboulkh          #+#    #+#             */
/*   Updated: 2023/11/17 22:16:25 by maboulkh         ###   ########.fr       */
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

class Response
{
private:
    std::map<std::string, std::string> ResponseHeader;
    std::string header;
    std::string body;
public:
    Response(std::string& body);
    ~Response();

    std::string findType(std::string& fileName);
};

Response::Response(std::string& body)
{
    StatusCode a;

    std::string StatusLine = a.statusLine();
    // "HTTP-Version Status-Code Reason-Phrase\r\n"; //server.httpVer() + " " + status + phrase(status) + "\r\n";
    ResponseHeader["date"] = "webserv"; // sever.name();
    ResponseHeader["content-type"] = ""; // content.findType();
    ResponseHeader["content-length"] = ""; // content.lenth();
    ResponseHeader["Server"] = "webserv"; // sever.name();

/*
HTTP/1.1 200 OK
date: Fri, 17 Nov 2023 16:48:57 GMT
content-type: text/html; charset=utf-8
content-length: 1017
x-request-id: a1bce949-f6af-4226-92a1-d746484b8a79
cache-control: no-store, max-age=0
accept-ch: sec-ch-prefers-color-scheme
critical-ch: sec-ch-prefers-color-scheme
vary: sec-ch-prefers-color-scheme
x-adblock-key: MFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBANDrp2lz7AOmADaN8tA50LsWcjLFyQFcb/P2Txc58oYOeILb3vBw7J6f4pamkAQVSQuqYsKx3YzdUHCvbVZvFUsCAwEAAQ==_HDSApIK32dE8tmarsVRiNoDCy6ChdPP5Uy8Jjf116Tqg7be9w+AIiANsZh2PU+muk1bDI2ehY575ZFEH0KlcHA==
set-cookie: parking_session=a1bce949-f6af-4226-92a1-d746484b8a79; expires=Fri, 17 Nov 2023 17:03:57 GMT; path=/
*/

}

std::string Response::findType(std::string& fileName) {
    std::map<std::string, std::string> type;
    type[".aac"] = "audio/aac";
    type[".abw"] = "application/x-abiword";
    type[".arc"] = "application/x-freearc";
    type[".avif"] = "image/avif";
    type[".avi"] = "video/x-msvideo";
    type[".azw"] = "application/vnd.amazon.ebook";
    type[".bin"] = "application/octet-stream";
    type[".bmp"] = "image/bmp";
    type[".bz"] = "application/x-bzip";
    type[".bz2"] = "application/x-bzip2";
    type[".cda"] = "application/x-cdf";
    type[".csh"] = "application/x-csh";
    type[".css"] = "text/css";
    type[".csv"] = "text/csv";
    type[".doc"] = "application/msword";
    type[".docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    type[".eot"] = "application/vnd.ms-fontobject";
    type[".epub"] = "application/epub+zip";
    type[".gz"] = "application/gzip";
    type[".gif"] = "image/gif";
    type[".htm"] = "text/html";
    type[".html"] = "text/html";
    type[".ico"] = "image/vnd.microsoft.icon";
    type[".ics"] = "text/calendar";
    type[".jar"] = "application/java-archive";
    type[".jpg"] = "image/jpeg";
    type[".jpeg"] = "image/jpeg";
    type[".js"] = "text/javascript";
    type[".json"] = "application/json";
    type[".jsonld"] = "application/ld+json";
    type[".mid"] = "audio/midi, audio/x-midi";
    type[".midi"] = "audio/midi, audio/x-midi";
    type[".mjs"] = "text/javascript";
    type[".mp3"] = "audio/mpeg";
    type[".mp4"] = "video/mp4";
    type[".mpeg"] = "video/mpeg";
    type[".mpkg"] = "application/vnd.apple.installer+xml";
    type[".odp"] = "application/vnd.oasis.opendocument.presentation";
    type[".ods"] = "application/vnd.oasis.opendocument.spreadsheet";
    type[".odt"] = "application/vnd.oasis.opendocument.text";
    type[".oga"] = "audio/ogg";
    type[".ogv"] = "video/ogg";
    type[".ogx"] = "application/ogg";
    type[".opus"] = "audio/opus";
    type[".otf"] = "font/otf";
    type[".png"] = "image/png";
    type[".pdf"] = "application/pdf";
    type[".php"] = "application/x-httpd-php";
    type[".ppt"] = "application/vnd.ms-powerpoint";
    type[".pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    type[".rar"] = "application/vnd.rar";
    type[".rtf"] = "application/rtf";
    type[".sh"] = "application/x-sh";
    type[".svg"] = "image/svg+xml";
    type[".tar"] = "application/x-tar";
    type[".tif"] = "image/tiff";
    type[".tiff"] = "image/tiff";
    type[".ts"] = "video/mp2t";
    type[".ttf"] = "font/ttf";
    type[".txt"] = "text/plain";
    type[".vsd"] = "application/vnd.visio";
    type[".wav"] = "audio/wav";
    type[".weba"] = "audio/webm";
    type[".webm"] = "video/webm";
    type[".webp"] = "image/webp";
    type[".woff"] = "font/woff";
    type[".woff2"] = "font/woff2";
    type[".xhtml"] = "application/xhtml+xml";
    type[".xls"] = "application/vnd.ms-excel";
    type[".xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    type[".xml"] = "application/xml";
    type[".xul"] = "application/vnd.mozilla.xul+xml";
    type[".zip"] = "application/zip";
    type[".3gp"] = "video/3gpp;";
    type[".3g2"] = "video/3gpp2;";
    type[".7z"] = "application/x-7z-compressed";
    size_t  i;

    i = fileName.find_last_of('.');
    std::map<std::string, std::string>::const_iterator res = type.find(std::string(fileName.c_str() + i));
    if (res != type.end())
        return (res->second);
    else
        return ("application/octet-stream");
}




Response::~Response()
{
}
