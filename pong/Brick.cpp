#include "Brick.h"
#include "BrickMgr.h"

Brick::Brick(float x, float y)
	:position(x, y), idxNum(0)
{

}

Brick::Brick()
{
	shape.setSize(Vector2f(100.f, 20.f));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

FloatRect Brick::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Brick::GetShape()
{
	return shape;
}

void Brick::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	shape.setPosition(position);
}
