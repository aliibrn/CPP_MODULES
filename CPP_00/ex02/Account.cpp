#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

void Account::_displayTimestamp( void ) {
    std::time_t now = std::time(0);
    std::tm *now_tm = std::localtime(&now);
    std::cout << "["
              << (now_tm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now_tm->tm_mon + 1)  
              << std::setw(2) << std::setfill('0') << now_tm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << now_tm->tm_hour
              << std::setw(2) << std::setfill('0') << now_tm->tm_min
              << std::setw(2) << std::setfill('0') << now_tm->tm_sec
              << "]";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
    << ";amount:" << _amount << ";deposits:" << _nbDeposits 
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount < withdrawal)
    {
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount 
                    << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << " index:" << _accountIndex 
                << ";p_amount:" << _amount + withdrawal 
                << ";withdrawal:" << withdrawal << ";amount:" << _amount 
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int     Account::checkAmount(void) const {
        return _amount;
}

int Account::getNbAccounts(){
    return _nbAccounts;
}
int Account::getTotalAmount( void ){
    return _totalAmount;
}
int	Account::getNbDeposits( void ){
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ){
    return _totalNbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";p_amount:" << _amount - deposit << ";deposit:" << deposit 
                 << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    _nbAccounts--;
    _totalAmount -= _amount;
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}