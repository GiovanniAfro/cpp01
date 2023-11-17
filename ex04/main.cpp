/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:18:04 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/17 17:01:56 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// Function to replace occurrences of s1 with s2 in a given string
void    replace(std::string& content, const std::string& s1, const std::string s2)
{
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
}

// Function to replace occurrences of s1 with s2 in a file
void    replaceInFile(const std::string& filename, const std::string s1, const std::string s2)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Error: unable to open input file." << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    replace(content, s1, s2);

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile)
    {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return;
    }

    outputFile << content;
    outputFile.close();

    std::cout << "Replacement completed. CheckMate " << filename << ".replace for the result." << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2> (you dumb:D)" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    replaceInFile(filename, s1, s2);

    return 0;
}