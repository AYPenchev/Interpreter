#include "pch.h"
#include "Interpreter.h"

Interpreter::Interpreter()
{
	this->text = "";
	this->position = 0;
	this->currentToken = Token();
	this->currentChar = this->text[this->position];
}

Interpreter::Interpreter(std::string text)
{
	this->text = text;
	this->position = 0;
	this->currentToken = Token();
	this->currentChar = this->text[this->position];
}

void Interpreter::Error()
{
	throw std::exception("error");
}

int Interpreter::ConverCharToInt(char charToInt)
{
	switch (charToInt)
	{
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break; 
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case '+': return -1; break;

	default: Error();
		return -1;
		break;
	}
}

Token Interpreter::GetNextToken()
{
	while (this->currentChar != '\0')
	{
		if (this->currentChar == ' ')
		{
			this->skipAnyWhitespace();
			continue;
		}
		
		if (this->currentChar >= '0' && this->currentChar <= '9')
		{
			Token token = Token(GetINTEGER(), this->readMultiDigitNumber());
			return token;
		}

		if (this->currentChar == '+')
		{
			this->advance();
			Token token = Token(GetPLUS(), this->currentChar);
			return token;
		}

		if (this->currentChar == '-')
		{
			this->advance();
			Token token = Token(GetMINUS(), this->currentChar);
			return token;
		}

		Error();
	}
	return Token(GetENDOF());
}

void Interpreter::Eat(std::string tokenType)
{
	if (this->currentToken.GetType() == tokenType)
	{
		this->currentToken = GetNextToken();
	}
	else
	{
		Error();
	}
}

int Interpreter::Expr()
{
	this->currentToken = GetNextToken();

	Token leftNum = this->currentToken;
	this->Eat(GetINTEGER());

	Token oper = this->currentToken;
	if (oper.GetType() == GetPLUS())
	{
		this->Eat(GetPLUS());
	}
	else
	{
		this->Eat(GetMINUS());
	}

	Token rightNum = this->currentToken;
	this->Eat(GetINTEGER());

	int result;
	if (oper.GetType() == GetPLUS())
	{
		result = leftNum.GetValue() + rightNum.GetValue();
	}
	else
	{
		result = leftNum.GetValue() - rightNum.GetValue();
	}

	return result;
}

void Interpreter::advance()
{
	this->position += 1;
	
	if (this->position > this->text.length() - 1)
	{
		this->currentChar = '\0';
	}
	else
	{
		this->currentChar = this->text[this->position];
	}
}

void Interpreter::skipAnyWhitespace()
{
	while (this->currentChar != '\0' && this->currentChar == ' ')
	{
		this->advance();
	}
}

int Interpreter::readMultiDigitNumber()
{
	std::string result = "";
	while (this->currentChar != '\0' && this->currentChar >= '0' && this->currentChar <= '9')
	{
		result += this->currentChar;
		this->advance();
	}
	return converStringToInt(result);
}

int Interpreter::converStringToInt(std::string stringToBeConverted)
{
	int convertedString = 0; 
	for (int i = stringToBeConverted.length() - 1, j = 1; i >= 0 ; i--, j *= 10)
	{
		convertedString += ((int)stringToBeConverted[i] - '0') * j;
	}
	return convertedString;
}

void Interpreter::SetText(std::string text)
{
	this->text = text;
}

std::string Interpreter::GetText() const
{
	return this->text;
}

void Interpreter::SetPosition(int position)
{
	this->position = position;
}

int Interpreter::GetPosition() const
{
	return this->position;
}

void Interpreter::SetCurrentToken(Token currentToken)
{
	this->currentToken = currentToken;
}

Token Interpreter::GetCurrentToken() const
{
	return this->currentToken;
}

void Interpreter::SetCurrentChar(char currentChar)
{
	this->currentChar = currentChar;
}

char Interpreter::GetCurrentChar() const
{
	return this->currentChar;
}

std::string Interpreter::GetINTEGER() const
{
	return this->INTEGER;
}

std::string Interpreter::GetPLUS() const
{
	return this->PLUS;
}

std::string Interpreter::GetENDOF() const
{
	return this->ENDOF;
}

std::string Interpreter::GetMINUS() const
{
	return this->MINUS;
}