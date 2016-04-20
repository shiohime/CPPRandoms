#include "stdafx.h"
#include "LibPrint.h"

template<typename T>
void LibPrint::printVector(std::vector<T>& list)
{
	std::cout << stringVector(list);
}

template<typename T>
std::string LibPrint::stringVector(std::vector<T>& list)
{
	std::stringstream ss;
	ss << "(";
	for (int i = 0; i < list.size(); i++)
	{
		if (i < list.size() - 1)
		{
			ss << list[i] << ",";
		}
		else
		{
			ss << list[i] << ")";
		}
	}

	return ss.str();
}