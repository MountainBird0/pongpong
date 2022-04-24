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

	brickMgr(const int& xCount, const int& yCount);	//블록을 카운트 만큼 세팅한다.
	~brickMgr();	//배열 전체의 동적할당을 해제한다. 
	
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

