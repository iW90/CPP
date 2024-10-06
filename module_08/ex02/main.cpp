/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:33:30 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/06 19:20:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << YELLOW << std::endl;
    
    //main do subject
    std::cout << "MutantStack: " << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\nList: " << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    // teste para iteração reversa
    std::cout << RESET YELLOW << std::endl;
    std::cout << "MutantStack: " << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();

        std::cout << "stack: ";
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nList: " << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::reverse_iterator rit = mstack.rbegin();
        std::list<int>::reverse_iterator rite = mstack.rend();

        std::cout << "stack: ";
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }
    
    // Test with std::string
    std::cout << RESET YELLOW << std::endl;
    std::cout << "MutantStack: " << std::endl;
    {
        MutantStack<std::string> stringStack;
        stringStack.push("She sells ");
        stringStack.push("seashells ");
        stringStack.push("by the ");
        stringStack.push("seashore.");

        for (MutantStack<std::string>::const_iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
            std::cout << *it;
        }
	    std::cout << std::endl;
    }

    std::cout << "\nList: " << std::endl;
    {
        std::list<std::string> stringStack;
        stringStack.push_back("She sells ");
        stringStack.push_back("seashells ");
        stringStack.push_back("by the ");
        stringStack.push_back("seashore.");

        for (std::list<std::string>::const_iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
            std::cout << *it;
        }
	    std::cout << std::endl;
    }
    
    std::cout << RESET << std::endl; 
    return 0;
}
