#pragma once
#include <vector>
#include <map>
#include <cmath>

class PathNode
{
public:
	int _x, _y;
	PathNode(int x, int y)
	{
		_x = x;
		_y = y;
	}

	inline void abs();

	friend inline PathNode& operator+(PathNode& one, PathNode& two);
	friend inline PathNode& operator-(PathNode& one, PathNode& two);
	friend bool operator<(PathNode& one, PathNode& two);
	bool operator()(PathNode& one, PathNode& two);
};

enum Direction { North = 0, West = 1, South = 2, East = 3 };

class CrossingPaths
{
public:
	static bool DoPathsCross(std::vector<int>& path);
	static bool DoPathsCrossFast(std::vector<int>& path);

private:
	static bool WillPathsCross(std::map<std::pair<int,int>, int>& pathMap, std::pair<int, int>& position, int changeX, int changeY);
	static bool IsNodeInMap(std::map<std::pair<int, int>, int>& pathMap, std::pair<int, int>& position);
};

