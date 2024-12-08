/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:21:46 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/02 19:43:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2)
        return 1;
    ScalarConverter::convert(av[1]);
}

/* STATIC CAST
 *      static_cast<tipo_desejado>(var);
 *
 * Permite realizar conversões de tipos de maneira segura em tempo de compilação.
 * Mais restrito em comparação com o dynamic_cast, mas oferece mais flexibilidade 
 *  do que um simples C-style cast.
 *
 * Use static_cast em:
 *   - Casos de certeza de que a conversão é válida e que os tipos estão relacionados.
 *   - Conversões entre tipos de dados primitivos (por exemplo, int para float).
 *   - Conversões entre ponteiros e inteiros (com cautela).
 *   - Conversões entre tipos de ponteiros que estão em uma hierarquia de classes 
 *       (base para derivada ou vice-versa) em uma hierarquia polimórfica.
 *
 * Características:
 * - Verificação em Tempo de Compilação: O static_cast faz a verificação de tipos 
 *      em tempo de compilação, o que significa que não há verificação em tempo de 
 *      execução. Se a conversão não for válida, você verá um erro de compilação.
 * - Sem Verificação de Segurança: Ao contrário do dynamic_cast, o static_cast não 
 *      verifica a validade da conversão em tempo de execução. Isso significa que, 
 *      se você tentar fazer um static_cast de um ponteiro de classe base para uma 
 *      classe derivada e o objeto não for realmente do tipo derivado, você poderá 
 *      acabar com um ponteiro inválido.
 * - Cuidado com Hierarquias de Classes: Ao usar static_cast para converter entre 
 *      ponteiros em hierarquias de classes, é sua responsabilidade garantir que 
 *      a conversão seja segura.
 */