/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:12:06 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/10 21:15:36 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <cstdio>
#include <iostream>

// Features
void Account::makeDeposit(int deposit) {
	
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (!withdrawal)
		return false;
	return true;
}

int Account::checkAmount(void) const {
	return getTotalAmount();
}

void Account::displayStatus(void) const {
}


		// Getters
		int Account::getNbAccounts(void) {
			return _nbAccounts;
		}

		int Account::getTotalAmount(void) {
			return _totalAmount;
		}

int Account::getNbDeposits(void) {
	return 0;
}

int Account::getNbWithdrawals(void) {
	return 0;
}

void Account::displayAccountsInfos(void) {
}


		// Private
		void Account::_displayTimestamp(void) {
			// Obter o tempo atual
			std::time_t currentTime = std::time(0);

			// Converter para tempo local
			std::tm* localTime = std::localtime(&currentTime);

			// Buffer para armazenar o timestamp formatado
			char buffer[20];

			// Formatar o timestamp usando strftime para obter partes separadas
			std::strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", localTime);

			// Exibir o timestamp
			std::cout << buffer << std::endl;
		}

		// Constructor
		Account::Account(int initial_deposit) {
			_amount = initial_deposit;
		}

		// Destructor
		Account::~Account(void) {
		}
