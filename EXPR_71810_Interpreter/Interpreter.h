#pragma once
#include <iostream>
#include <string>
//#include <exception>
#include "Token.h"

class Interpreter //: public std::exception
{
public:
	Interpreter();
	Interpreter(std::string text);
	
	//virtual std::string Error() const throw();
	Token GetNextToken();
	void Eat(std::string tokenType);
	int Expr();

	void SetText(std::string text);
	std::string GetText() const;

	void SetPosition(int position);
	int GetPosition() const;

	void SetCurrentToken(Token currentToken);
	Token GetCurrentToken() const;
private:
	int ConverCharToInt(char charToInt);
	std::string text;
	int position = 0;
	Token currentToken;
} /*myException*/;
