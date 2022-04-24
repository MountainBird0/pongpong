#pragma once

#include <SFML/Graphics.hpp>
#include "Bat.h";

using namespace sf;

class Ball
{
private:
	bool isMoving = false;
	Bat& bat;

	Vector2f originalPosition;
	
	Vector2f position;
	RectangleShape shape;

	float speed = 300.f;
	Vector2f dir;

public:
	Ball(float x, float y, Bat& ref);

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();
	
	Vector2f GetSpeed();

	void MoveBall(bool move);
	float GetPosition(float x, float y);

	void ReboundSides();
	void ReboundBatOrTop();
	void Reboundbottom();

	void StopBall();

	void Update(float dt);

	bool IsMoving() { return isMoving; }

	void InitialLeftDir();
	void InitialRightDir();
};

