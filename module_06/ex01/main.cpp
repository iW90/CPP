/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:54:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/02 19:45:30 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
#include <typeinfo>


int main() {
    Data* data = new Data;
    data->product = "Book";
    data->price = 180.5;
    data->quantity = 5;

    Data* newData = NULL;
    
    std::cout << "Data pointer address: " << data << std::endl;
    std::cout << "NewData pointer address: " << newData << std::endl;


    uintptr_t raw = Serializer::serialize(data);
    newData = Serializer::deserialize(raw);


    if (newData == data) {
        std::cout << "\nDeserialization successful: pointers match." << std::endl;
    } else {
        std::cout << "\nDeserialization failed: pointers do not match." << std::endl;
    }

    std::cout << "\nProduct: " << newData->product << std::endl;

    data->quantity += 2;
    std::cout << "New quantity data: " << newData->quantity << std::endl;
    std::cout << "Original quantity: " << data->quantity << std::endl;

    delete data;

    return 0;
}



/* REINTERPRET CAST
 *      tipo_desejado* ptr = reinterpret_cast<tipo_desejado*>(ptr_original);
 * 
 * Permite realizar conversões de tipos de maneira mais flexível, mas também 
 * mais arriscada. É utilizado principalmente para converter um ponteiro 
 * de um tipo para outro, independentemente da hierarquia de tipos.
 * 
 * Use reinterpret_cast em:
 *  - Conversões entre ponteiros (por exemplo, converter um ponteiro 
 *      de um tipo para um ponteiro de outro tipo completamente diferente).
 *  - Tipos de dados que não têm relação, como um ponteiro de um objeto para 
 *      um ponteiro de um tipo de dado primitivo (por exemplo, de void* para 
 *      um tipo específico).
 *  - Programação de sistemas embarcados, pois pode ser necessário mapear 
 *      endereços de hardware para ponteiros.
 * 
 * Características:
 * - Comportamento Indefinido: Usar reinterpret_cast pode levar a comportamento 
 *      indefinido, especialmente se você tentar acessar membros de um tipo que 
 *      não foram corretamente alinhados ou que não têm a estrutura apropriada.
 * - Portabilidade: O código que utiliza reinterpret_cast pode não ser portátil 
 *      entre diferentes plataformas, pois a representação dos tipos de dados 
 *      pode variar.
 * - Não realiza verificações de segurança: Ao contrário de static_cast, 
 *      reinterpret_cast não faz checagens de tipo, então você pode acabar com 
 *      ponteiros que não são válidos.
 */