#include "Bat.h"

Bat::Bat(float x, float y)
	: position(x, y)
{
	shape.setSize(Vector2f(200, 5));
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

void Bat::StopBat()
{
	isMoving = false;
	dir.x *= 0.f;
	dir.y *= 0.f;
}

void Bat::SetMoveDir(Sides side)
{
	moveDir = side;
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
//���� : ���⿡ ���� ������, ���̷� �Ǿ��ִ� ����
// ���⼱ �������� ���ڴ�..
// ���� ���� : ���̸� 1�� �����.