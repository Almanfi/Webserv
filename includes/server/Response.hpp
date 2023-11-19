/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elasce <elasce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:50:59 by maboulkh          #+#    #+#             */
/*   Updated: 2023/11/19 03:29:00 by elasce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.hpp"
#include <ctime>
#include <sstream>

class Response
{
private:
    std::map<std::string, std::string> ResponseHeader;
    bool        isFile;
    std::string header;
    // std::string body;
    // std::string fileName;
    std::string code;
    std::string data;

    std::string findType(std::string& fileName);
    std::string date();
    std::string contentLength();
public:
    // Response(std::string& body);
    Response(std::string& code, std::stiring& data, bool isFile);
    ~Response();

};

	// code[100] = "Continue";
	// code[200] = "OK";
	// code[201] = "Created";
	// code[204] = "No Content";
	// code[400] = "Bad Request";
	// code[403] = "Forbidden";
	// code[404] = "Not Found";
	// code[405] = "Method Not Allowed";
	// code[413] = "Payload Too Large";
	// code[500] = "Internal Server Error";

Response::Response(std::string& code, std::string& data, bool isFile) : code(code), data(data), isFile(isFile) {
    ResponseHeader["Server"] = "webserv"; // sever.name();
    ResponseHeader["date"] = date(); // date();
    if (isFile) {
        ResponseHeader["content-type"] = findType(data); // content.findType();
        ResponseHeader["content-length"] = contentLength(); // content.lenth();
    }
    else {
        ResponseHeader["content-type"] = findType(".txt"); // content.findType();
        ResponseHeader["content-length"] = data.length(); // content.lenth();
    }
}


// Response::Response(std::string& body)
// {
//     StatusCode a;

//     fileName = "";
//     code = "200";
//     std::string StatusLine = a.statusLine(code);
//     // "HTTP-Version Status-Code Reason-Phrase\r\n"; //server.httpVer() + " " + status + phrase(status) + "\r\n";
//     ResponseHeader["Server"] = "webserv"; // sever.name();
//     ResponseHeader["date"] = date(); // date();
//     ResponseHeader["content-type"] = findType(fileName); // content.findType();
//     ResponseHeader["content-length"] = contentLength(); // content.lenth();

// /*
// HTTP/1.1 200 OK
// date: Fri, 17 Nov 2023 16:48:57 GMT
// content-type: text/html; charset=utf-8
// content-length: 1017
// x-request-id: a1bce949-f6af-4226-92a1-d746484b8a79
// cache-control: no-store, max-age=0
// accept-ch: sec-ch-prefers-color-scheme
// critical-ch: sec-ch-prefers-color-scheme
// vary: sec-ch-prefers-color-scheme
// x-adblock-key: MFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBANDrp2lz7AOmADaN8tA50LsWcjLFyQFcb/P2Txc58oYOeILb3vBw7J6f4pamkAQVSQuqYsKx3YzdUHCvbVZvFUsCAwEAAQ==_HDSApIK32dE8tmarsVRiNoDCy6ChdPP5Uy8Jjf116Tqg7be9w+AIiANsZh2PU+muk1bDI2ehY575ZFEH0KlcHA==
// set-cookie: parking_session=a1bce949-f6af-4226-92a1-d746484b8a79; expires=Fri, 17 Nov 2023 17:03:57 GMT; path=/
// */

// }

std::string Response::header() {
    std:: string header;
    char *SP = "\n";
    StatusCode a;

    header = a.statusLine(code);
    header += SP;
    for (std::map<std::string, std::string>::iterator it = ResponseHeader.begin(); *it != ResponseHeader.end(), i++) {
        header += it->first + ": " + it->second + SP;
    }
    header += SP;
    return (header);
}

std::string Response::contentLength() {
    size_t size;
    std::stringstream ss;
    if (isFile) {
        std::ifstream file(data.c_str());
        if (!file.is_open())
        {
            // throw
            code = "500";
            return "";
        }
        std::streampos start = file.tellg();
        file.seekg(0, std::ios::end);
        std::streampos end = file.tellg(); 
        size = end - start
        file.close();
    }
    else 
        size = data.length();
    ss << size;
    return ((std::string) ss.str());
}

std::string Response::date() {
    std::time_t   nowTime = std::time(NULL);
    std::tm* gmTime = std::gmtime(&nowTime);

    char    buffer[100];
    std::strftime(buffer, sizeof(buffer), "%a, %d %b %Y %X GMT", gmTime);
    return ((std::string) buffer);
}

std::string Response::findType(std::string& fileName) {
    std::map<std::string, std::string> type;
    type["default"] = "application/octet-stream";
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
    
    size_t i = fileName.find_last_of('.');
    if (i == std::string::npos)
        return (type["default"]);
    std::map<std::string, std::string>::const_iterator res = type.find(fileName.substr(i));
    if (res != type.end())
        return (res->second);
    else
        return (type["default"]);
}




Response::~Response()
{
}
