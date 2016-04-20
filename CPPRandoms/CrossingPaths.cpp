#include "stdafx.h"
#include "CrossingPaths.h"

bool CrossingPaths::DoPathsCrossFast(std::vector<int>& path)
{
	//Paths can't cross if there's less than 4 inputs in the vector
	for (int i = 3; i < path.size(); i++)
	{

		if (path[i] >= path[i - 2] && path[i - 1] <= path[i - 3]) return true;
		if (i >= 4 && path[i - 1] == path[i - 3] && path[i] + path[i - 4] >= path[i - 2]) return true;
		if (i >= 5 && path[i - 2] - path[i - 4] >= 0 && path[i] >= path[i - 2] - path[i - 4] && path[i - 1] >= path[i - 3] - path[i - 5] && path[i - 1] <= path[i - 3]) return true;
	}
	return false;
}
bool CrossingPaths::DoPathsCross(std::vector<int>& path)
{
	std::map<std::pair<int, int>, int> pathMap;
	Direction currentDirection = North;
	std::pair<int, int> current{ 0,0 };
	std::pair<int, int> previous = current;

	//ensure we add the starting position
	pathMap.emplace(current, 1);

	for (std::vector<int>::iterator it = path.begin(); it != path.end(); it++)
	{
		int changeX = 0, changeY = 0;
		switch (currentDirection)
		{
		case North:
			changeY += *it;
			break;
		case West:
			changeX -= *it;
			break;
		case South:
			changeY -= *it;
			break;
		case East:
			changeX += *it;
			break;
		default:
			break;
		}

		if (WillPathsCross(pathMap, current, changeX, changeY))
		{
			return true;
		}

		currentDirection = static_cast<Direction>((currentDirection + 1) % 4);
	}

	return false;
}

bool CrossingPaths::WillPathsCross(std::map<std::pair<int, int>, int>& pathMap, std::pair<int, int>& position, int changeX, int changeY)
{
	bool hasCrossed = false;
	bool isNegative = false;
	if (changeX != 0)
	{
		isNegative = changeX < 0;
		for (int i = 0; i < std::abs(changeX); i++)
		{
			position.first += isNegative ? -1 : 1;

			if (!hasCrossed)
			{
				hasCrossed = IsNodeInMap(pathMap, position);
			}
			pathMap.emplace(position, 1);
		}
	}

	else 
	{
		isNegative = changeY < 0;
		for (int i = 0; i < std::abs(changeY); i++)
		{
			position.second += isNegative ? -1 : 1;
			if (!hasCrossed)
			{
				hasCrossed = IsNodeInMap(pathMap, position);
			}
			pathMap.emplace(position, 1);
		}
	}

	return hasCrossed;
}

bool CrossingPaths::IsNodeInMap(std::map<std::pair<int, int>, int>& pathMap, std::pair<int, int>& position)
{
	std::map<std::pair<int, int>, int>::iterator it = pathMap.find(position);

	//Check if value is in map
	return it != pathMap.end();
}














inline void PathNode::abs()
{
	_x = std::abs(_x);
	_y = std::abs(_y);
}

inline PathNode& operator+(PathNode& one, PathNode& two)
{
	PathNode output{ one._x + two._x, one._y + two._y };
	return output;
}

inline PathNode& operator-(PathNode& one, PathNode& two)
{
	PathNode output{ one._x - two._x, one._y - two._y };
	return output;
}

bool PathNode::operator()(PathNode& one, PathNode& two)
{
	{
		// one < two
		if (one._x < two._x)
		{
			return true;
		}

		// one and two have the same x
		if (one._x == two._x)
		{
			// one's y is less than two's
			if (one._y < two._y)
			{
				return true;
			}
		}

		//two is >= one
		return false;
	}
}