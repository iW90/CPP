/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:26:16 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/15 17:00:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

#define MAX_VAL 750

struct s_test {
	int a;
	char b;
};

int main(int, char**)
{
    // Empty
    {
        std::cout << "EMPTY ARRAY" << std::endl;
        Array<int> emptyArray;
        std::cout << "Size: " << emptyArray.size() << std::endl;
    
        std::cout << std::endl;
        
        std::cout << "INVALID INDEX" << std::endl;
        try {
            std::cout << "emptyArray[5]: " << emptyArray[5] << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }

    // Resources
    int i;
    Array<int> intArray(5);
    Array<double> doubleArray(10);
    Array<int> intArrayCopy(intArray);
    Array<double> doubleArrayAssignment = doubleArray;
    Array<s_test> structArray(6);
    const Array<int> constIntArray(intArray);
    
    // Int
    {
        std::cout << "INT ARRAY" << std::endl;
        i = 0;
        while (i < 5) {
            intArray[i] = i;
            i++;
        }
        std::cout << "intArray size: " << intArray.size() << std::endl;
        std::cout << "intArray: ";
        i = 0;
        while (i < 5) {
            std::cout << intArray[i] << " ";
            i++;
        }
        std::cout << "\n" << std::endl;        
    }

    // Const
    {
        std::cout << "CONST INT" << std::endl;
        std::cout << "constIntArray size: " << constIntArray.size() << std::endl;
        std::cout << "constIntArray: ";
        i = 0;
        while (i < 5) {
            std::cout << constIntArray[i] << " ";
            i++;
        }
        std::cout << "\n" << std::endl;  
    }

    // Double
    {
        std::cout << "DOUBLE ARRAY" << std::endl;
        i = 0;
        while (i < 10) {
            doubleArray[i] = i / 2.0;
            i++;
        }
        std::cout << "doubleArray size: " << doubleArray.size() << std::endl;
        std::cout << "doubleArray: ";
        i = 0;
        while (i < 10) {
            std::cout << doubleArray[i] << " ";
            i++;
        }
        std::cout << "\n" << std::endl;  
    }

    // Copy constructor
    {
        std::cout << "COPY CONSTRUCTOR" << std::endl;
        std::cout << "intArrayCopy size: " << intArrayCopy.size() << std::endl;
        std::cout << "intArrayCopy: ";
        i = 0;
        while (i < 5) {
            std::cout << intArrayCopy[i] << " ";
            i++;
        }
        std::cout << "\n" << std::endl;  
    }

    // Assign Operator
    {
        std::cout << "ASSIGNMENT OPERATOR" << std::endl;
        std::cout << "doubleArrayAssignment size: " << doubleArrayAssignment.size() << std::endl;
        std::cout << "doubleArrayAssignment: ";
        i = 0;
        while (i < 10) {
            std::cout << doubleArrayAssignment[i] << " ";
            i++;
        }
        std::cout << "\n" << std::endl;  
    }

    // Struct
    {
        std::cout << "COMPLEX TYPE (STRUCT)" << std::endl;
        i = 0;
        while (i < 6) {
            structArray[i].a = i;
            structArray[i].b = 'a' + i;
            i++;
        }
        std::cout << "structArray size: " << structArray.size() << std::endl;
        std::cout << "structArray: ";
        i = 0;
        while (i < 6) {
            std::cout << structArray[i].a << structArray[i].b << " ";
            i++;
        }
        std::cout << "\n" << std::endl;  
    }

	return (0);
}