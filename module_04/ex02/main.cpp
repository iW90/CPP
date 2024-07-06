/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:33:35 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:37:01 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	std::cout << "\nAAnimals:" << std::endl;
	//const AAnimal* animal = new AAnimal(); //Não é possível instanciar
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;

	return 0;
}