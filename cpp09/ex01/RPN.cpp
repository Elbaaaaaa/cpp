#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
	std::cout << "RPN copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->_tokens = other._tokens;
    return (*this);
}

void	RPN::processInput(char operators)
{
	if (_tokens.size() < 2)
		throw NotEnoughNumbers();
	
	int nb = _tokens.top();
	_tokens.pop();

	int nb2 = _tokens.top();
	_tokens.pop();
	
	int res;
	if (operators == '/' && nb == 0)
		throw CantDivideByZero();
	switch (operators)
	{
		case '+':
			res = nb2 + nb;
			break;
		case '*':
			res = nb2 * nb;
			break;
		case '/':
			res = nb2 / nb;
			break;
		case '-':
			res = nb2 - nb;
			break;
	}
	_tokens.push(res);
}
void RPN::initializeTokens(std::string tokens)
{
	for (size_t i = 0; i < tokens.length(); i++)
	{
		if (tokens[i] == ' ')
			continue;
		else if (isdigit(tokens[i]))
			_tokens.push(tokens[i] - '0');
		else if (tokens[i] == '+' || tokens[i] == '-' ||tokens[i] == '*' ||tokens[i] == '/')
			processInput(tokens[i]);
		else
			throw IncorrectInput();
	}
	
	if (_tokens.size() != 1)
		throw SomethingWentWrong();
	
	std::cout  << _tokens.top() << std::endl;
	_tokens.pop();
}