#include "pch.h"
#include "Interpreter.h"

Interpreter::Interpreter()
{
	this->text = "";
	this->position = 0;
	this->currentToken = Token();
}

Interpreter::Interpreter(std::string text)
{
	this->text = text;
}

/*std::string Interpreter::Error() const throw()
{
	return "Error parsing input";
}*/

int Interpreter::ConverCharToInt(char charToInt)
{
	//std::string convertedChar = convertedChar.append(1, charToString);
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

	default: std::cout << "Error vuv convertchartoint" << std::endl;
		return -1;//Error();
		break;
	}
//	return;
}

Token Interpreter::GetNextToken()
{
	//this->text = "";

	if (this->position > text.length() - 1)
	{
		return Token("EOF");
	}
	
	char currentChar = this->text[this->position];

	if (currentChar >= '0' && currentChar <= '9')
	{
		Token token = Token("INTEGER", ConverCharToInt(currentChar));
		this->position++;
		return token;
	}

	if (currentChar == '+')
	{
		Token token = Token("PLUS", ConverCharToInt(currentChar));
		this->position++;
		return token;
	}
	std::cout << "Error vuv getnextoken" << std::endl; //Error();
}

void Interpreter::Eat(std::string tokenType)
{
	if (currentToken.GetType() == tokenType)
	{
		currentToken = GetNextToken();
	}
	else
	{
		std::cout << "Error vuv eat" << std::endl; //Error();
	}
}

int Interpreter::Expr()
{
	this->currentToken = GetNextToken();

	Token leftNum = this->currentToken;
	this->Eat("INTEGER");

	Token operatorPlus = this->currentToken;
	this->Eat("PLUS");

	Token rightNum = this->currentToken;
	this->Eat("INTEGER");

	int result = leftNum.GetValue() + rightNum.GetValue();
	return result;
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

