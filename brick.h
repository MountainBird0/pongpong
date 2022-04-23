#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class brick
{
private:
	Vector2f position;					//좌표찍어주기
	RectangleShape shape;				//사각형 그려주기
	int idxNum = 0;						//배열의 index

public:
	brick(float x, float y);
	brick();
	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();


	void SetPosition(float x, float y); //첫 좌표 적어주기
	//void SetIdxNum(int idx);
	//void Update(float df);
};

