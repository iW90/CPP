/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 08:38:56 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/06 09:32:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        // Insert num on vector
        std::vector<int> vec;
        vec.push_back(1);                       // Coloca 1 no final
        vec.push_back(2);                       // Coloca 2 no final
        vec.insert(vec.end(), 3);               // Coloca 3 no final
        vec.insert(vec.end(), 4);               // Coloca 4 no final
        vec.insert(vec.begin() + 1, 5);         // Coloca 5 na posição 1 (segunda posição)

        // Insert num on list
        std::list<int> lst;
        lst.push_back(10);                      // Coloca 10 no final
        lst.push_front(20);                     // Coloca 20 no início
        lst.push_back(30);                      // Coloca 30 no final
        lst.insert(lst.begin(), 50);            // Coloca 50 no início
        lst.insert(lst.end(), 60);              // Coloca 60 no final

        // Testando o vector
        std::cout << "Finding 3 in vector: ";
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Found: " << *it_vec << std::endl;

        // Testando o list
        std::cout << "Finding 20 in list: ";
        std::list<int>::iterator it_lst = easyfind(lst, 20);
        std::cout << "Found: " << *it_lst << std::endl;

        // Testando um valor não encontrado
        std::cout << "Finding 6 in vector: ";
        easyfind(vec, 6);

    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
