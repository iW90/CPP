/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:39:21 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 17:06:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replacer {
	public:
		static int replacer(const std::string& filename, const std::string& s1, const std::string& s2);
		
	private:
		static void _replace(std::string &str, const std::string &s1, const std::string &s2);
		static bool _openFile(const std::string& filename, std::ifstream& file);
		static bool _createFile(const std::string& filename, std::ofstream& file);

};

#endif //REPLACER_HPP