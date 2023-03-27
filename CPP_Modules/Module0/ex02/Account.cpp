#include "Account.hpp"
#include <iostream>
#include <string>
#include <time.h>

/**
 * @brief Getter
 * @returns Private var information
*/
int     Account::getNbAccounts()        { return _nbAccounts; }
int     Account::getTotalAmount()       { return _totalAmount; }
int     Account::getNbDeposits()        { return _totalNbDeposits; }
int     Account::getNbWithdrawals()     { return _totalNbWithdrawals; }
void    Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:"   << getNbAccounts()    << ";";
    std::cout << "total:"      << getTotalAmount()   << ";";
    std::cout << "deposits:"   << getNbDeposits()    << ";";
    std::cout << "withdrawals:"<< getNbWithdrawals() << std::endl;
}

// Class constructor
Account::Account(int first_depo) {
    _nbDeposits    = 0;
    _nbWithdrawals = 0;
    _amount        = first_depo;
    _accountIndex  = _nbAccounts;

    _displayTimestamp();
    std::cout << "index:"   << _nbAccounts  << ";"
              << "ammount:" << _amount      << ";"
              << "created"  << std::endl;

    _totalAmount += _amount;
    _nbAccounts  += 1;
}
// Class destructor
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:"   << _accountIndex << ";"
              << "ammount:" << _amount       << ";"
              << "closed"   << std::endl;
}

void    Account::makeDeposit(int depo) {
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex   << ";"
              << "p_amount:"    << _amount         << ";"
              << "deposit"      << depo            << ";"
              << "amount:"      << _amount + depo  << ";"
              << "nb_deposits:" << _nbDeposits + 1 << std::endl;

    _totalNbDeposits += 1;
    _nbDeposits      += 1;
    _amount          += depo;
    _totalAmount     += depo;
}
bool    Account::makeWithdrawal(int withdraw) {
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex   << ";"
              << "p_amount:"    << _amount         << ";"
              << "withdrawal:";
    if (checkAmount() < withdraw) {
        std::cout << "refused"  << std::endl;
        return false;
    } else {
        std::cout << withdraw           << ";"
                  << "amount:"          << _amount - withdraw << ";"
                  << "nb_withdrawals:"  << _nbWithdrawals + 1 << std::endl;
        
        _nbWithdrawals      += 1;
        _amount             -= withdraw;
        _totalNbWithdrawals += 1;
        return true;
    }
}
int     Account::checkAmount()   const { return _amount; }
void    Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex  << ";"
              << "amount:"      << _amount        << ";"
              << "deposits:"    << _nbDeposits    << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}

// Setter for private vars
int Account::_nbAccounts =          Account::getNbAccounts();
int Account::_totalAmount =         Account::getTotalAmount();
int Account::_totalNbDeposits =     Account::getNbDeposits();
int Account::_totalNbWithdrawals =  Account::getNbWithdrawals();

void    Account::_displayTimestamp() {
    time_t      now = time(0);
    struct tm   tstruct;
    char        buf[80];

    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
    std::cout << "[" << buf << "] ";
}
