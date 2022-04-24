#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"

class BrickMgr
{
private:
	int xCount;
	int yCount;

public:
	Brick* brickArray;

	BrickMgr(const int& xCount, const int& yCount);	//블록을 카운트 만큼 세팅한다.
	~BrickMgr();	//배열 전체의 동적할당을 해제한다. 

	FloatRect GetGlobalBounds(int i);

	const RectangleShape& GetShape(int i);

	void DeleteBrick(int idx);	//idx의 블록의 동적할당을 해제.
};

