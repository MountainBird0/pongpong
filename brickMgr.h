#pragma once
#include <SFML/Graphics.hpp>
#include "brick.h"

class brickMgr
{
private:
	int xCount;
	int yCount;

public:
	brick* brickArray;

	brickMgr(const int& xCount, const int& yCount);	//����� ī��Ʈ ��ŭ �����Ѵ�.
	~brickMgr();	//�迭 ��ü�� �����Ҵ��� �����Ѵ�. 
	
	FloatRect GetGlobalBounds(int i);

	const RectangleShape& GetShape(int i);

	void DeleteBrick(int idx);	//idx�� ����� �����Ҵ��� ����.

	
};

