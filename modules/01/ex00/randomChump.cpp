/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:21 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:55:24 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	It creates a zombie, name it, and the zombie announces itself.
*/
void Zombie::randomChump(std::string name) {
	Zombie zomb(name);
	zomb.announce();
}

/*
	Memória Stack:

	A memória stack é uma área de memória reservada para funções e variáveis locais.
	As variáveis ​​criadas na stack têm um tempo de vida limitado ao escopo da função que as cria.
	As variáveis ​​são alocadas e desalocadas automaticamente pelo compilador à medida que a execução do programa avança e as funções são chamadas e retornam.
	O acesso à memória stack é rápido, pois as alocações e desalocações são simplesmente feitas movendo um ponteiro.
	A memória stack tem tamanho limitado.
*/