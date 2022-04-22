#include "Ball.h"
#include <cmath>

Ball::Ball(float x, float y, Bat &bat)
	:originalPosition(x, y), position(x, y), bat(bat)
{
	dir.x = 1.f;		//단위벡터를 만들자.
	dir.y = 1.f;

	float length = sqrt(dir.x * dir.x + dir.y * dir.y); //벡터의길이

	dir.x /= length;
	dir.y /= length;

	/*dir.x = 0.f;
	dir.y = 0.f;*/

	shape.setSize(Vector2f(10, 10));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

FloatRect Ball::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Ball::GetShape()
{
	return shape;
}

Vector2f Ball::GetSpeed()
{
	return dir;
}

void Ball::MoveBall(bool move, Keyboard::Key keyCode)
{
	isMoving = move;
	if(Keyboard::Right)
	{
		dir.x *= 1.f;		//단위벡터를 만들자.
		dir.y *= -1.f;
	}
	if (Keyboard::Left)
	{
		dir.x *= -1.f;		//단위벡터를 만들자.
		dir.y *= -1.f;
	}
}

float Ball::GetPosition(float x, float y)
{
	return x, y;	
}

void Ball::ReboundSides()	
{
	dir.x *= -1.f;
}

void Ball::ReboundBatOrTop()
{
	dir.y *= -1.f;
}

void Ball::Reboundbottom()
{
	//dir.y *= -1.f;
	position = originalPosition;
	isMoving = false;
}

void Ball::Update(float dt)
{
	if (isMoving)
	{
		// 판 참조, 변환 함수
		position += dir * dt * speed;
		
	}
	else
	{
		Vector2f batPos = bat.GetShape().getPosition();
		Vector2f batSize= bat.GetShape().getSize();

		position.x = batPos.x + batSize.x * 0.5f;
		position.y = batPos.y - 10;
	}
	shape.setPosition(position);
}
