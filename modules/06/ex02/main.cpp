/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:50:17 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/02 21:12:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

// Utils
void _identifyHelper(Base& p, void (*func)(Base&)) {
    try {
        func(p);
    } catch (std::exception&) {}
}

void _identifyA(Base& p) {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
}

void _identifyB(Base& p) {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
}

void _identifyC(Base& p) {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
}

//
void    identify(Base& p) {
    _identifyHelper(p, _identifyA);
    _identifyHelper(p, _identifyB);
    _identifyHelper(p, _identifyC);
}

void    identify(Base* p) {
    if      (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

Base*   generate(void) {
    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

int     main() {
    srand(static_cast<unsigned int>(time(0)));

    Base* p;
    for (int i = 1; i < 11; ++i) {
        std::cout << "Attempt: " << i << std::endl;
        p = generate();
        identify(p);
        identify(*p);
        delete p;
        std::cout << std::endl;
    }  
}

/* DYNAMIC CAST
 *      dynamic_cast<Derived*>(basePtr)
 *
 * Permite realizar a conversão segura de ponteiros ou referências de tipos de 
 * classes base para tipos de classes derivadas em hierarquias de herança. É 
 * especialmente útil quando se trabalha com classes polimórficas, ou seja, 
 * aquelas que têm pelo menos um método virtual.
 * 
 * Use dynamic_cast em:
 *  - Hierarquias de classes que envolvem polimorfismo, ou seja, quando você 
 *      tem uma classe base com métodos virtuais. Isso garante que você esteja 
 *      lidando com o tipo correto de objeto.
 *  - Conversões de Classe Base para Classe Derivada (por exemplo, quando você 
 *      tem um ponteiro ou referência de uma classe base e precisa acessá-lo 
 *      como uma classe derivada).
 *  - Casos onde a hierarquia é complexa e você não tem certeza do tipo do 
 *      objeto em tempo de execução. Se o tipo for conhecido, você pode preferir
 *      utilizar o static cast para ter melhor desempenho.
 * 
 * Características:
 * - Verificação de Tipo em Tempo de Execução: Ao contrário de static_cast, que 
 *      realiza a verificação em tempo de compilação, dynamic_cast faz uma 
 *      verificação em tempo de execução. Isso significa que ele garante que a 
 *      conversão seja válida, evitando problemas como conversões inválidas que 
 *      poderiam levar a comportamento indefinido.
 * - Classes Polimórficas: Para que dynamic_cast funcione, a classe base deve 
 *      ter pelo menos um método virtual. Isso permite que o compilador armazene 
 *      informações sobre a hierarquia de classes em uma tabela chamada "tabela 
 *      de tipos" (ou RTTI - Run-Time Type Information).
 * - Uso com Referências: Se você tentar usar dynamic_cast com referências, e a 
 *      conversão não for válida, ele lançará uma exceção std::bad_cast. Portanto, 
 *      é importante tratar essa exceção ao usar referências.
 * - Retorno: O dynamic_cast retorna um ponteiro ou referência do tipo desejado 
 *      se a conversão for bem-sucedida. Caso contrário, retorna NULL (para 
 *      ponteiros) ou lança uma exceção (para referências).
 * 
 * TABELA DE TIPOS E RTTI
 * - Tabela de Tipos: Quando você usa classes com herança e métodos virtuais, o 
 *  compilador gera uma estrutura de dados chamada tabela de tipos (ou "type info 
 *  table"). Esta tabela contém informações sobre os tipos das classes e é 
 *  associada a cada classe que tem pelo menos um método virtual.
 * - Identificação de Tipos: A RTTI permite que você identifique o tipo real de 
 *  um objeto em tempo de execução, mesmo quando você possui um ponteiro ou 
 *  referência de uma classe base. Isso é feito através dos operadores dynamic_cast 
 *  e typeid (lembrando que a função std::typeinfo é probida neste projeto).
 */