/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:39:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 17:15:39 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Replacer.hpp"

int Replacer::replacer(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile;
	
    if (!_openFile(filename, inputFile))
        return 1;

    std::string content((std::istreambuf_iterator<char>(inputFile)), // Ler o conteúdo
                        std::istreambuf_iterator<char>());

    inputFile.close();

    _replace(content, s1, s2);

    std::string outputFileName = filename + ".replace";

    std::ofstream outputFile; // Abrir o arquivo de saída
    if (!_createFile(outputFileName, outputFile))
        return 1;

    outputFile << content; // Escrever a string modificada no arquivo de saída
    outputFile.close();

    return 0;
}


void Replacer::_replace(std::string &str, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return;

	std::string::size_type pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos) {
		str.erase(pos, s1.length());     // Remove s1
		str.insert(pos, s2);           	 // Insere s2 no lugar de s1

		pos += s2.length();              // Move pos para após s2
	}
}

bool Replacer::_openFile(const std::string& filename, std::ifstream& file) {
    file.open(filename.c_str(), std::ios::in);
    if (!file) {
        std::cerr << "Error to open " << filename << std::endl;
        return false;
    }
    return true;
}

bool Replacer::_createFile(const std::string& filename, std::ofstream& file) {
    file.open(filename.c_str(), std::ios::out);
    if (!file) {
        std::cerr << "Error to create " << filename << std::endl;
        return false;
    }
    return true;
}
