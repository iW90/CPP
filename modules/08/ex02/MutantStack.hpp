/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:34:16 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/06 19:04:18 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

# define RESET         		"\033[0m"
# define YELLOW        		"\033[33m"

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        ~MutantStack();
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        
        //iterators
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();

        const_iterator begin() const;
        const_iterator end() const;
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif


/* Override
 * Herdando std::stack<T> (classe que implementa a estrutura de dados do tipo 
 * pilha), podemos sobrescrever a stack quando nos referirmos ao seu contêiner 
 * subjacente, usando um alias de tipo para contornar a falta de iterador.".
 */




