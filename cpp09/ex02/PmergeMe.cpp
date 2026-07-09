#include "PmergeMe.hpp"


std::vector<int>	PmergeMe::JacobsthalSequence(int	size)
{
	std::vector<int> jacobNumbers;
	int				 prevGroupIndex = 1;
	int				 currentGroupIndex = 1;

	while (prevGroupIndex < size)
	{
		int nextGroupIndex = currentGroupIndex + 2 * prevGroupIndex;
		int upperBound = nextGroupIndex < size ? nextGroupIndex : size;
		
		for (int i = upperBound; i >= currentGroupIndex + 1; i-=1)
			jacobNumbers.push_back(i - 1);

		if (nextGroupIndex >= size)
			break;

		prevGroupIndex = currentGroupIndex;
		currentGroupIndex = nextGroupIndex;
	}
	return jacobNumbers;
}

void	PmergeMe::initArgs(int	ac, char	**av)
{
	if (ac < 1)
		return;

	int i = 1;
	while (av[i])
	{
		int j = 0;
		if (av[i][0] == '\0')
			continue;
		while (av[i][j])
		{
			if (!std::isdigit(av[i][j]))
				throw parsingError("Error: invalid format.");
			j++;
		}
		
		long n = std::strtol(av[i], NULL, 10);
		if (n > 2147483647)
			throw parsingError("Error: overflow or negative number.");
		_vec.push_back((int)n);
		_deq.push_back((int)n);
		_before.push_back((int)n);
		i++;
	}
}

void	PmergeMe::printTime()
{

	std::cout << "Time to process a range of " << _before.size() 
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
			  << _timeVect << " us" << std::endl;
	
	std::cout << "Time to process a range of " << _before.size() 
			  << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
			  << _timeDeq << " us" << std::endl;
}

void PmergeMe::printFinalResult()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _before.size(); i++) {
        std::cout << _before[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
	std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
	{
        this->_deq = other._deq;
		this->_vec = other._vec;
		this->_before = other._before;
	}
    return (*this);
}

std::vector<int>& PmergeMe::getVec()
{
	return _vec;
}

std::deque<int>&  PmergeMe::getDeq() 
{
	return _deq;
}