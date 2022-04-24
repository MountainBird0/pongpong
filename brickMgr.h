#pragma once
#include <SFML/Graphics.hpp>
#include "brick.h"

class brickMgr
{
private:
	int xCount;
	int yCount;

	
public:
	brick *brickArray;

	brickMgr(const int& xCount, const int& yCount);	//����� ī��Ʈ ��ŭ �����Ѵ�.
	~brickMgr();	//�迭 ��ü�� �����Ҵ��� �����Ѵ�. 
	
	FloatRect GetGlobalBounds(int i);
	const RectangleShape& GetShape(int i);

	FloatRect GGB_LS(int i)
	{
		return brickArray[i].GGB_LS();
	}
	const RectangleShape &GS_LS(int i)
	{
		return brickArray[i].GS_LS();
	}

	FloatRect GGB_RS(int i)
	{
		return brickArray[i].GGB_RS();
	}
	const RectangleShape &GS_RS(int i)
	{
		return brickArray[i].GS_RS();
	}
	


};

