/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 08:40:40 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/06 09:29:59 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP


# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value);

# include "easyfind.tpp"


# endif
