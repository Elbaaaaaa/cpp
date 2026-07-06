#include "PmergeMe.hpp"

template <typename T>
void 	PmergeMe::fordJonsonSort(T& container)
{
	int		orphanElement;
	bool	hasOrphan = false;

	if (container.size() <= 1)
		return ;
	if (container.size() % 2 != 0)
	{
		orphanElement = container.back();
		container.pop_back();
		hasOrphan = true;
	}
	std::vector<std::pair<int, int> > pairs;

	for (int i = 0; i <= container.size() - 1; i += 2)
	{
		if (container[i] < container[i + 1])
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
		else
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
	}

	T mainChain;
	for (int i = 0; i <= pairs.size() - 1; i++)
		mainChain.push_back(pairs[i].first);
	
	container.clear();
	fordJonsonSort(mainChain);
	
	T pendantChain;
	for (int i = 0; i <= mainChain.size() - 1; i++)
	{
		for (int j = 0; j < pairs.size(); j++)
		{
			if (mainChain[i] == pairs[j].first)
			{
				pendantChain.push_back(pairs[j].second);
				pairs[j].first = -1;
				break;
			}
		}
	}

	mainChain.insert(mainChain.begin(), pendantChain[0]);
}

template <typename T>
typename T::iterator PmergeMe::binarySearch(T& container, int value)
{

}