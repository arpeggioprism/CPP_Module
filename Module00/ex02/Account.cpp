#include "Account.hpp"
#include <iomanip>
#include <iostream>

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{

}

Account::Account(int initial_deposit)
{
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits++;
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{

}

void Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{
	
}

int Account::checkAmount(void) const
{

}

void Account::displayStatus(void) const
{

}

void Account::_displayTimestamp()
{
	time_t seconds = std::time(nullptr);
	std::cout << std::put_time(std::localtime(&seconds), "[%Y%m%d_%H%M%S] ");
}