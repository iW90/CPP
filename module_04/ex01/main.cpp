/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:33:35 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 20:29:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int size = 10;
    const int halfSize = size / 2;
    
    Animal* animals[size];

    // Preenche metade do array com Dog e a outra metade com Cat
    for (int i = 0; i < halfSize; ++i) {
        animals[i] = new Dog();
    }
    for (int i = halfSize; i < size; ++i) {
        animals[i] = new Cat();
    }

    // Mostra os tipos e sons dos animais
    for (int i = 0; i < size; ++i) {
        std::cout << animals[i]->getType() << " ";
        animals[i]->makeSound();
    }

    // Deleta todos os animais
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    return 0;

	return 0;
}