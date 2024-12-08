/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:34:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/06 13:23:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <climits>
# include <set>

# define RESET         		"\033[0m"
# define YELLOW        		"\033[33m"

class Span {
    private:
        unsigned int    _maxSize;
        std::set<int>   _numbers;
        Span();

    public:
        ~Span();
        Span(unsigned int number);
        Span(const Span& other);
        Span&   operator=(const Span& other);

        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
};

#endif