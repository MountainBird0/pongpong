#include "brick.h"
#include "brickMgr.h"

brick::brick(float x, float y)
	:position(x, y),idxNum(0)
{
	
}

brick::brick()
{
	shape.setSize(Vector2f(100.f, 20.f));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

FloatRect brick::GetGlobalBounds()
{
	return shape.getGlobalBounds();

}
const RectangleShape& brick::GetShape()
{
	return shape;
}

void brick::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	shape.setPosition(position);
}

//void brick::SetIdxNum(int idx)
//{
//	
//}

