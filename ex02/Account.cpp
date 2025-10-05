/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaitlhaj <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-03 18:36:39 by oaitlhaj          #+#    #+#             */
/*   Updated: 2025-10-03 18:36:39 by oaitlhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>


	int Account::_nbAccounts = 0;
	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts 
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits 
	<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}


void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
	<< this->_amount << ";deposit:" << deposit << ";amount:"
	<< this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits
	<< std::endl;
	this->_amount += deposit;
	this->_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
	<< this->_amount << ";withdrawal:" << withdrawal << ";amount:"
	<< this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (1);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" 
	<< this->_amount << ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << "\n";
}


void	Account::_displayTimestamp( void )
{
	std::time_t timeInSeconds = std::time(0);          
    std::tm timeNow = *std::localtime(&timeInSeconds);
	std::cout << "[" << timeNow.tm_year + 1900 << std::setfill('0') 
	<< std::setw(2) << timeNow.tm_mon + 1
	<< std::setw(2) << timeNow.tm_mday 
	<< "_" << std::setw(2) << timeNow.tm_hour
	<< std::setw(2) << timeNow.tm_min
	<< std::setw(2) << timeNow.tm_sec
	<< "] " ;
}

