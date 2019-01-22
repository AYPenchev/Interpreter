#include "pch.h"
#include "Lexer.h"

Lexer::Lexer()
{
	this->text = "";
	this->position = 0;
	this->currentChar = this->text[this->position];
}

Lexer::Lexer(std::string text)
{
	this->text = text;
	this->position = 0;
	this->currentChar = this->text[this->position];
}

Lexer& Lexer::operator=(const Lexer& other)
{
	if (this != &other)
	{
		//this->destroy();
		this->copy(other);
	}
	return *this;
}

void Lexer::copy(const Lexer& other)
{
	this->text = other.text;
	this->position = other.position;
	this->currentChar = other.currentChar;
}

void Lexer::Error()
{
	throw std::exception("error");
}

void Lexer::advance()
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

void Lexer::skipAnyWhitespace()
{
	while (this->currentChar != '\0' && this->currentChar == ' ')
	{
		this->advance();
	}
}

int Lexer::readMultiDigitNumber()
{
	std::string result = "";
	while (this->currentChar != '\0' && this->currentChar >= '0' && this->currentChar <= '9')
	{
		result += this->currentChar;
		this->advance();
	}
	return converStringToInt(result);
}

int Lexer::converStringToInt(std::string stringToBeConverted)
{
	int convertedString = 0;
	for (int i = stringToBeConverted.length() - 1, j = 1; i >= 0; i--, j *= 10)
	{
		convertedString += ((int)stringToBeConverted[i] - '0') * j;
	}
	return convertedString;
}

Token Lexer::GetNextToken()
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

		if (this->currentChar == '*')
		{
			this->advance();
			Token token = Token(GetPRODUCT(), this->currentChar);
			return token;
		}

		if (this->currentChar == '/')
		{
			this->advance();
			Token token = Token(GetDIVISION(), this->currentChar);
			return token;
		}

		if (this->currentChar == '%')
		{
			this->advance();
			Token token = Token(GetREMAINDER(), this->currentChar);
			return token;
		}

		Error();
	}
	return Token(GetENDOF());
}

void Lexer::SetText(std::string text)
{
	this->text = text;
}

std::string Lexer::GetText() const
{
	return this->text;
}

void Lexer::SetPosition(int position)
{
	this->position = position;
}

int Lexer::GetPosition() const
{
	return this->position;
}

void Lexer::SetCurrentChar(char currentChar)
{
	this->currentChar = currentChar;
}

char Lexer::GetCurrentChar() const
{
	return this->currentChar;
}

std::string Lexer::GetINTEGER() const
{
	return this->INTEGER;
}

std::string Lexer::GetPLUS() const
{
	return this->PLUS;
}

std::string Lexer::GetENDOF() const
{
	return this->ENDOF;
}

std::string Lexer::GetMINUS() const
{
	return this->MINUS;
}

std::string Lexer::GetPRODUCT() const
{
	return this->PRODUCT;
}

std::string Lexer::GetDIVISION() const
{
	return this->DIVISION;
}

std::string Lexer::GetREMAINDER() const
{
	return this->REMAINDER;
}
