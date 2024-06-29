/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:48:16 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 11:16:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) {
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	
	IMateriaSource* src = new MateriaSource();
	AMateria *newMateria = new Ice();
	
	src->learnMateria(newMateria);
	src->learnMateria(new Cure());
	src->learnMateria(newMateria->clone());


	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);


	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
