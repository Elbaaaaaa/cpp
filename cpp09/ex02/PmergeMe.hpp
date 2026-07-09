# ifndef	PMERGEME_HPP
# define	PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

class	PmergeMe
{
	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	_before;

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

		std::vector<int>& getVec();
		std::deque<int>&  getDeq();
		
		std::vector<int>	JacobsthalSequence(int	size);

		template <typename T>
		void	fordJonsonSort(T& container);

		template <typename T>
		typename T::iterator binarySearch(T& container, int value);
		

		class parsingError : public std::exception {
			private:
				std::string _msg;
			public:
				parsingError(const std::string& msg) : _msg(msg) {}
				virtual ~parsingError() throw() {}
				virtual const char* what() const throw() { return _msg.c_str(); }
		};

};

#include "PmergeMe.tpp"

# endif