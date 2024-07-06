/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:33:35 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 10:26:29 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // {
    //     std::cout << "Leak tests" << std::endl;
    //     const int size = 4;
        
    //     Animal* animals[size];

    //     // Preenche metade do array com Dog e a outra metade com Cat
    //     for (int i = 0; i < size / 2; ++i) {
    //         animals[i] = new Dog();
    //         animals[size - i - 1] = new Cat();
    //     }

    //     // Novas ideias
    //     static_cast<Dog*>(animals[0])->setIdea("Fetch a stick", 0);
    //     static_cast<Dog*>(animals[0])->setIdea("To ask for affection", 1);
    //     static_cast<Dog*>(animals[1])->setIdea("Play with a ball", 99);
        
    //     static_cast<Cat*>(animals[2])->setIdea("Knock over a cup", 0);
    //     static_cast<Cat*>(animals[3])->setIdea("Summon a demon", 0);

    //     // Mostra os tipos e sons dos animais
    //     for (int i = 0; i < size; ++i) {
    //         std::cout << animals[i]->getType() << " ";
    //         animals[i]->makeSound();
    //     }

    //     // Deleta todos os animais
    //     for (int i = 0; i < size; ++i) {
    //         delete animals[i];
    //     }
    // }
    {
        std::cout << "Deep copy tests" << std::endl;
        Dog originalToto;
        
        originalToto.setIdea("Bark to door", 5);
        std::cout << originalToto.getIdea(5) << std::endl;

        Dog cloneToto = originalToto;
        // std::cout << cloneToto.getIdea(5) << std::endl;
    }
	return 0;
}