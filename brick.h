#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class brick
{
private:
	Vector2f position;					//��ǥ����ֱ�
	RectangleShape shape;        //�簢�� �׷��ֱ�

	Vector2f positionLS;
	RectangleShape shapeLS;

	Vector2f positionRS;
	RectangleShape shapeRS;


public:
	brick(float x, float y, float xl, float yl, float xr, float yr);
	brick();

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();

	void SetPosition(float x, float y); //ù ��ǥ �����ֱ�
	float GetPositionX();
	float GetPositionY();


	FloatRect GGB_LS()
	{
		return shapeLS.getGlobalBounds();
	}
	const RectangleShape &GS_LS()
	{
		return shapeLS;
	}

	FloatRect GGB_RS()
	{
		return shapeRS.getGlobalBounds();
	}
	const RectangleShape &GS_RS()
	{
		return shapeRS;
	}


	//void SetIdxNum(int idx);
	//void Update(float df);
};

