/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:54:58 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/15 15:39:12 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Construction with no parameter
template <typename T>
Array<T>::Array() : data(NULL), len(0) {}

// Constructor with array len
//	(creates an array of n elements initialized by default).
template <typename T>
Array<T>::Array(unsigned int n) : len(n) {
	if (n > 0) {
		data = new T[n];
		for (unsigned int i = 0; i < n; ++i) {
			data[i] = T();
		}
	} else {
		data = NULL;
	}
}

// Destructor
template <typename T>
Array<T>::~Array() {
	delete[] data;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : len(other.len) {
	if (len > 0) {
		data = new T[len];
		for (unsigned int i = 0; i < len; ++i) {
		data[i] = other.data[i];
		}
	} else {
		data = NULL;
	}
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] data;
		len = other.len;
		if (len > 0) {
			data = new T[len];
			for (unsigned int i = 0; i < len; ++i) {
				data[i] = other.data[i];
			}
		} else {
			data = NULL;
		}
	}
	return *this;
}

// Subscript operator
//	Elements can be accessed through the subscript operator: [].
template <typename T>
T& Array<T>::operator[](int index) {
	if (index < 0 || static_cast<unsigned int>(index) >= len) {
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

// Subscript operator with const
template <typename T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || static_cast<unsigned int>(index) >= len) {
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

// Size function
//	Returns the number of elements in the array
template <typename T>
unsigned int Array<T>::size() const {
	return this->len;
}
