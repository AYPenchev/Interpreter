#include "pch.h"
#include <iostream>
#include <exception>
#include "Token.h"
#include "Interpreter.h"

int main()
{
	std::string text;
	while (true)
	{
		//try
		//{
			std::cout << "calc> ";
			std::cin >> text;
			if (text == "End" || text == "end")
			{
				break;
			}
			//throw myException;
		//}
		//catch (std::exception& e)
		//{
		//	std::cout << e.what() << std::endl;
			//break;
		//}
		Interpreter interpreter = Interpreter(text);
		int result = interpreter.Expr();
		std::cout << result << std::endl; 

	}
}
