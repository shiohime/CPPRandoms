#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class LibPrint
{
public:
	template<typename T>
	static void printVector(std::vector<T>& list);
	
	template<typename T>
	static std::string stringVector(std::vector<T>& list);
};