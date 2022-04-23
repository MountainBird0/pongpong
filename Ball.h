#pragma once

#include <SFML/Graphics.hpp>
#include "Bat.h";

using namespace sf;



class Ball //얘는 지가 알아서 움직이드라~
{
private:
	bool isMoving = false;
	Bat& bat;

	Vector2f originalPosition;
	
	Vector2f position;
	RectangleShape shape;

	float speed = 500.f;
	Vector2f dir;

public:
	Ball(float x, float y, Bat& ref);

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();
	
	Vector2f GetSpeed();

	void MoveBall(bool move, Keyboard::Key keyCode = Keyboard::Right);
	float GetPosition(float x, float y);

	void ReboundSides();
	void ReboundBatOrTop();
	void Reboundbottom();

	void Update(float dt);

	bool IsMoving() { return isMoving; }

};

