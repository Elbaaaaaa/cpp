# ifndef	PMERGEME_HPP
# define	PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>

class	PmergeMe
{
	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		std::vector<int>	_fordJhonSeq;

		double	_timeVect;
		double	_timeDeq;

	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);

		void	initArgs(int	ac, char	**av);
		void	printTime();
		void	printFinalResult();

		void	JacobsthalSequence(int	pendantChainSize);

		template <typename T>
		void	fordJonsonSort(T& container);

		template <typename T>
		typename T::iterator binarySearch(T& container, int value);

};

#include "PmergeMe.tpp"

# endif