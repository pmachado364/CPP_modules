/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:18:51 by pmachado          #+#    #+#             */
/*   Updated: 2025/09/01 18:15:27 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
	std::time_t now = std::time(NULL); //tempo em segundos desde 1970
	std::tm *time = std::localtime(&now);
	std::cout	<< "["
				<< time->tm_year + 1900
				<< std::setw(2) << std::setfill('0') << time->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << time->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << time->tm_hour
				<< std::setw(2) << std::setfill('0') << time->tm_min
				<< std::setw(2) << std::setfill('0') << time->tm_sec
				<< "] ";
}

Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts; // índice da conta
	this->_amount = initial_deposit; // valor inicial
	this->_nbDeposits = 0; // número de depósitos ao início
	this->_nbWithdrawals = 0; // número de levantamentos ao início
	Account::_nbAccounts++; // incrementar o número de contas
	Account::_totalAmount += initial_deposit; // incrementar o total de dinheiro
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account(void) {
	
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
}

//getters
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

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
	int prev_amount = this->_amount; // guardar o valor inicial da conta
	this->_amount += deposit; // atualizar o valor da conta
	this->_nbDeposits++; // incrementar o número de depósitos na conta
	Account::_totalAmount += deposit; // atualizar o total de dinheiro
	Account::_totalNbDeposits++; // incrementar o número total de depósitos
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << prev_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int prev_amount = this->_amount; // guardar o valor inicial da conta
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << prev_amount << ";"
				<< "withdrawal:";
	
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return false; // não há dinheiro suficiente na conta
	}
	
	this->_amount -= withdrawal; // atualizar o valor da conta
	this->_nbWithdrawals++; // incrementar o número de levantamentos na conta
	Account::_totalAmount -= withdrawal; // atualizar o total de dinheiro
	Account::_totalNbWithdrawals++; // incrementar o número total de levantamentos
	std::cout	<< withdrawal << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::checkAmount(void) const {
	return this->_amount;
}

