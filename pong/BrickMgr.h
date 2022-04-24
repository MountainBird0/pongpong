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

	BrickMgr(const int& xCount, const int& yCount);	//����� ī��Ʈ ��ŭ �����Ѵ�.
	~BrickMgr();	//�迭 ��ü�� �����Ҵ��� �����Ѵ�. 

	FloatRect GetGlobalBounds(int i);

	const RectangleShape& GetShape(int i);

	void DeleteBrick(int idx);	//idx�� ����� �����Ҵ��� ����.
};

