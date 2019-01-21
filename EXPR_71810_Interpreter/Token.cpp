#include "pch.h"
#include "Token.h"

Token::Token()
{
	this->type = "";
}

Token::Token(std::string otherType, int otherValue)
{
	this->type = otherType;
	this->value = otherValue;
}

void Token::SetType(std::string type)
{
	this->type = type;
}

std::string Token::GetType() const
{
	return this->type;
}

void Token::SetValue(int value)
{
	this->value = value;
}

int Token::GetValue() const
{
	return this->value;
}
