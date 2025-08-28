/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:18:51 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/28 18:39:04 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
	std::time_t now = std::time(NULL); //tempo em segundos desde 1970
	std::tm *lt = std::localtime(&now); //converte para hora local
	std::cout<<"["<< (lt->tm_year + 1900) //ano desde 1900
		
} 