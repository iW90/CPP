/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:28 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:56:31 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	It creates a zombie, name it, and return it so you can use it outside of the function scope.
*/
Zombie *Zombie::newZombie(std::string name) {
	Zombie* zomb = new Zombie(name);
	zomb->announce();
		
	return zomb;
}

/*
	Memória Heap:

	A memória heap é uma área de memória mais dinâmica e expansível.
	As alocações e desalocações de memória na heap são feitas manualmente pelo programador (new).
	As variáveis ​​na heap têm tempo de vida indefinido, elas persistem até serem explicitamente desalocadas (delete).
	O acesso à memória heap é um pouco mais lento do que à memória stack, pois envolve alocações e desalocações mais complexas.
	A memória heap geralmente tem um tamanho muito maior do que a memória stack.
*/