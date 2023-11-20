/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TempFile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboulkh <maboulkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:46:06 by elasce            #+#    #+#             */
/*   Updated: 2023/11/20 04:50:32 by maboulkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdio>

class TempFile {
    private:
    std::string fileName;
    std::FILE* std;
    std::FILE* fs;
    int fd;
    
    public:
    TempFile(std::string& file, FILE* std);
    ~TempFile();
    int write(std::string &str);
    int read(std::string &str);
    void rewind();
    // int dup();
    int resetFd();
};