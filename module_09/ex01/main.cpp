/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:33:26 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/12 12:07:49 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No expression provided" << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.evaluate(argv[1]);
    return 0;
}


/* !Important:
 * Notações "5 1 2 + 4 * +" versus "5 1 2 + 4 *"
 * 
 * Notação Polonesa Reversa (RPN)
 * Na RPN, a operação deve ser finalizada antes que uma nova operação possa ser 
 * realizada. Isso significa que, para cada operador, devem existir pelo menos 
 * dois operandos disponíveis na pilha. Dessa forma, a segunda operação não é
 * válida porque não haveria um segundo operador.
 * 
 * Cálculo da expressão "5 1 2 + 4 *":
 *     5: Empilhamos 5. (Pilha: [5])
 *     1: Empilhamos 1. (Pilha: [5, 1])
 *     2: Empilhamos 2. (Pilha: [5, 1, 2])
 *     +: Desempilhamos 1 e 2, e somamos. (1 + 2 = 3)
 *     Pilha: [5, 3]
 *     4: Empilhamos 4. (Pilha: [5, 3, 4])
 *     *: Desempilhamos 3 e 4, e multiplicamos. (3 * 4 = 12)
 *     Pilha: [5, 12]
 *       Agora, a pilha contém 5 e 12. No entanto, como não há mais operadores para 
 *       processar, a expressão "5 1 2 + 4 *" é considerada incompleta, pois não 
 *       resultou em um único valor final.
 *
 * Cálculo da expressão "5 1 2 + 4 * +":
 *      Seguindo a mesma lógica do cálculo anterior, mas agora possuindo um operador 
 *       a mais no final, temos 
 *       +: Desempilhamos 5 e 12, e somamos. (5 + 12 = 17)
 *       Pilha: [17]
 *       Assim, o resultado da expressão "5 1 2 + 4 * +" é 17.
 */