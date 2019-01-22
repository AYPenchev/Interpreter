#include "pch.h"
#include "Interpreter.h"

Interpreter::Interpreter()
{
	this->lexer = Lexer();
	this->currentToken = Token();
}

Interpreter::Interpreter(Lexer lexer)
{
	this->lexer = lexer;
	this->currentToken = Token();
}

void Interpreter::Error()
{
	throw std::exception("error");
}

void Interpreter::Eat(std::string tokenType)
{
	if (this->currentToken.GetType() == tokenType)
	{
		this->currentToken = this->lexer.GetNextToken();
	}
	else
	{
		Error();
	}
}

int Interpreter::Factor()
{
	Token token = this->currentToken;
	this->Eat(this->lexer.GetINTEGER());
	return token.GetValue();
}

int Interpreter::Expr()
{
	this->currentToken = this->lexer.GetNextToken();

	int result = this->term();

	while (this->currentToken.GetType() == this->lexer.GetPLUS() ||
		   this->currentToken.GetType() == this->lexer.GetMINUS())
	{
		Token token = this->currentToken;
		if (token.GetType() == this->lexer.GetPLUS())
		{
			this->Eat(this->lexer.GetPLUS());
			result = result + this->term();
		}
		else if (token.GetType() == this->lexer.GetMINUS())
		{
			this->Eat(this->lexer.GetMINUS());
			result = result - this->term();
		}
	}

	return result;
}

int Interpreter::term()
{
	int result = this->Factor();

	while (this->currentToken.GetType() == this->lexer.GetPRODUCT() ||
		   this->currentToken.GetType() == this->lexer.GetDIVISION() ||
		   this->currentToken.GetType() == this->lexer.GetREMAINDER())
	{
		Token token = this->currentToken;
		
		if (token.GetType() == lexer.GetPRODUCT())
		{
			this->Eat(lexer.GetPRODUCT());
			result = result * this->Factor();
		}
		else if (token.GetType() == lexer.GetDIVISION())
		{
			this->Eat(lexer.GetDIVISION());
			result = result / this->Factor();
		}
		else if (token.GetType() == this->lexer.GetREMAINDER())
		{
			this->Eat(this->lexer.GetREMAINDER());
			result = result % this->Factor();
		}
	}
	return result;

	/*Token token = this->currentToken;
	this->Eat(GetINTEGER());
	return token.GetValue();*/
}

void Interpreter::SetCurrentToken(Token currentToken)
{
	this->currentToken = currentToken;
}

Token Interpreter::GetCurrentToken() const
{
	return this->currentToken;
}

void Interpreter::SetLexer(Lexer lexer)
{
	this->lexer = lexer;
}

Lexer Interpreter::GetLexer() const
{
	return this->lexer;
}
