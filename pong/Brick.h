#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Brick
{
private:
	Vector2f position;					//��ǥ����ֱ�
	RectangleShape shape;				//�簢�� �׷��ֱ�
	int idxNum = 0;						//�迭�� index

public:
	Brick(float x, float y);
	Brick();
	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();


	void SetPosition(float x, float y); //ù ��ǥ �����ֱ�
	void SetIdxNum(int idx);
	//void Update(float df);
};


