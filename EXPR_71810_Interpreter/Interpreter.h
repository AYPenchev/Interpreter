#pragma once
#include <iostream>
#include <string>
#include "Token.h"
#include "Lexer.h"

class Interpreter 
{
public:
	Interpreter();
	Interpreter(Lexer lexer);

	void Error();
	void Eat(std::string tokenType);
	int Factor();
	int Expr();
	int term();

	void SetCurrentToken(Token currentToken);
	Token GetCurrentToken() const;

	void SetLexer(Lexer lexer);
	Lexer GetLexer() const;
private:
	Lexer lexer;
	Token currentToken;
};
