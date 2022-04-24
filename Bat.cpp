#include "Bat.h"

Bat::Bat(float x, float y)
	: position(x, y)
{
	shape.setSize(Vector2f(500,5));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

FloatRect Bat::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Bat::GetShape()
{
	return shape;
}

void Bat::SetMoveDir(Sides side)
{
	moveDir = side;
}

void Bat::StopBat()
{
	speed = 0;
}

void Bat::Update(float dt)
{
	Vector2f dir;
	switch (moveDir)
	{
	case Sides::LEFT:
		dir.x = -1.f;
		break;
	case Sides::RIGHT:
		dir.x = 1.f;
		break;
	
	}
	position += dir * dt * speed;
	shape.setPosition(position);
}
Vector2f Bat::GetBatPosition(Bat bat)
{
	return bat.position;
}
//벡터 : 방향에 대한 정보와, 길이로 되어있는 정보
// 여기선 방향으로 쓰겠다..
// 단위 벡터 : 길이를 1로 맞춘다.
