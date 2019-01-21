#pragma once
#include <iostream>
#include <string>
#include "Token.h"

class Interpreter 
{
public:
	Interpreter();
	Interpreter(std::string text);
	
	void Error();
	Token GetNextToken();
	void Eat(std::string tokenType);
	int Expr();
	void advance();
	void skipAnyWhitespace();
	int readMultiDigitNumber();
	int converStringToInt(std::string stringToBeConverted);

	void SetText(std::string text);
	std::string GetText() const;

	void SetPosition(int position);
	int GetPosition() const;

	void SetCurrentToken(Token currentToken);
	Token GetCurrentToken() const;

	void SetCurrentChar(char currentChar);
	char GetCurrentChar() const;

	std::string GetINTEGER() const;
	std::string GetPLUS() const;
	std::string GetENDOF() const;
	std::string GetMINUS() const;
private:
	int ConverCharToInt(char charToInt);
	std::string text;
	int position = 0;
	Token currentToken;
	char currentChar;

	const std::string INTEGER = "INTEGER",
					  PLUS = "PLUS",
					  ENDOF = "EOF",
					  MINUS = "MINUS";
};
