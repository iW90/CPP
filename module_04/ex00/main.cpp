/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:33:35 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 20:06:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	{
		std::cout << "\nAnimals:" << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		dog->makeSound();
		cat->makeSound();
		animal->makeSound();
		delete animal;
		delete dog;
		delete cat;
	}
	{
		std::cout << "\nStranger Animals:" << std::endl;
		const WrongCat* cat = new WrongCat();
		const WrongCat* animal = new WrongAnimal();
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		animal->makeSound();
		delete animal;
		delete cat;
	}

	return 0;
}