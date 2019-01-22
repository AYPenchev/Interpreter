#pragma once
#include <iostream>
#include <string>
#include "Token.h"

class Lexer
{
public:
	Lexer();
	Lexer(std::string text);

	Lexer & operator=(const Lexer & other);

	void copy(const Lexer & other);

	void Error();

	void advance();

	void skipAnyWhitespace();

	int readMultiDigitNumber();

	int converStringToInt(std::string stringToBeConverted);

	Token GetNextToken();
	
	void SetText(std::string text);
	std::string GetText() const;

	void SetPosition(int position);
	int GetPosition() const;

	void SetCurrentChar(char currentChar);
	char GetCurrentChar() const;

	std::string GetINTEGER() const;
	std::string GetPLUS() const;
	std::string GetENDOF() const;
	std::string GetMINUS() const;
	std::string GetPRODUCT() const;
	std::string GetDIVISION() const;
	std::string GetREMAINDER() const;

private:
	std::string text;
	int position = 0;
	char currentChar;

	const std::string INTEGER = "INTEGER",
					  PLUS = "PLUS",
					  ENDOF = "EOF",
					  MINUS = "MINUS",
					  PRODUCT = "PRODUCT",
					  DIVISION = "DIVISION",
					  REMAINDER = "REMAINDER";
};