#ifndef RPN_H
#define RPN_H

#include <stack>
#include <iostream>

class RPN
{
	private:
		std::stack<int> _tokens;

	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);

		void	initializeTokens(std::string tokens);
		void	processInput(char operators);

		class NotEnoughNumbers : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: not enaught numbers, please enter atleast 2.";
				}
		};
		
		class CantDivideByZero : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: You cannot divide by zero.";
				}
		};

		class IncorrectInput : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: Your input is incorrect, correct input [+ - * / or numbers from 0 to 9].";
				}
		};
		
		class SomethingWentWrong : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: There is more than 1 number in stack. (only the final resulat should be there.)";
				}
		};
};














#endif