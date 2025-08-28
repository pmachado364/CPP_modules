#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

public:

	typedef Account		t;
	
	//getters - informações globais
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	//setters - informações específicas da conta
	void	makeDeposit( int deposit ); // depósito
	bool	makeWithdrawal( int withdrawal ); // levantamento
	int		checkAmount( void ) const; // saldo
	void	displayStatus( void ) const; // status

private:
	//global variables - informações gerais
	static int	_nbAccounts; // número de contas
	static int	_totalAmount; // quantia total
	static int	_totalNbDeposits; // número total de depósitos
	static int	_totalNbWithdrawals; // número total de levantamentos

	static void	_displayTimestamp( void );

	//instance variables - informações específicas da conta
	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __ACCOUNT_H__ */