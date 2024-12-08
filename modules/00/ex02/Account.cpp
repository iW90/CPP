/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:12:06 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 20:12:28 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <cstdio>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Features
void Account::makeDeposit(int deposit) {
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;	
}

bool Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > _amount) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::checkAmount(void) const {
	return _amount;
}

// Getters
int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
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
	std::cout << buffer;
}

// Constructor
Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
	{
		_totalAmount += initial_deposit;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	}

// Destructor
Account::~Account(void)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	}
