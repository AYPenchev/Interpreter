#include "pch.h"
#include <iostream>
#include <exception>
#include "Token.h"
#include "Interpreter.h"

int main()
{
	std::string text;
	bool endFlag = true;

	while (endFlag)
	{
		std::cout << "calc> ";
		std::getline(std::cin, text);

		if (text == "End" || text == "end")
		{
			endFlag = false;
		}
		else
		{
			Lexer lexer = Lexer(text);
			Interpreter interpreter = Interpreter(lexer);
			int result = interpreter.Expr();
			std::cout << result << std::endl;
		}
	}
}
