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

	for (size_t i = 0; i <= container.size() - 1; i += 2)
	{
		if (container[i] < container[i + 1])
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
		else
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
	}

	T mainChain;
	for (size_t i = 0; i <= pairs.size() - 1; i++)
		mainChain.push_back(pairs[i].first);
	
	container.clear();
	fordJonsonSort(mainChain);
	
	T pendantChain;
	for (size_t i = 0; i <= mainChain.size() - 1; i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
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

	std::vector<int> indexs = JacobsthalSequence(pendantChain.size());
	for (size_t i = 0; i < indexs.size(); i++)
	{
		int currentIndex = indexs[i];
		if (currentIndex == 0)
			continue;
		int val = pendantChain[currentIndex];
		typename T::iterator pos = binarySearch(mainChain, val);
		mainChain.insert(pos, val);
	}

	if (hasOrphan)
	{
		typename T::iterator pos = binarySearch(mainChain, orphanElement);
		mainChain.insert(pos, orphanElement);
	}
	container = mainChain;
}

template <typename T>
typename T::iterator PmergeMe::binarySearch(T& container, int value)
{
	typename T::iterator low = container.begin();
	typename T::iterator high = container.end();

	while (low < high)
	{
		typename T::iterator mid = low + (std::distance(low, high) / 2);
		if (value < *mid)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}