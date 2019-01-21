#pragma once
#include <iostream>
#include <string>

class Token
{
public:
	Token();
	Token(std::string otherType, int otherValue = 0);

	void SetType(std::string type);
	std::string GetType() const;

	void SetValue(int value);
	int GetValue() const;

private:
	std::string type;
	int value;
};