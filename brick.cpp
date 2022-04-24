#include "brick.h"
#include "brickMgr.h"

brick::brick(float x, float y, float xl, float yl, float xr, float yr)
	:position(x, y), positionLS(xl, yl), positionRS(xr, yr)
{	
}

brick::brick()
{
	shape.setSize(Vector2f(100.f, 50.f));
	shape.setPosition(position);
	shape.setFillColor(Color::White);

	//shapeLS.setSize(Vector2f(0, 0));
	shapeLS.setPosition(0,0);
	shapeLS.setFillColor(Color::Blue);

	shapeRS.setSize(Vector2f(100, 1080));
	//shapeRS.setPosition(0, 0);
	shapeRS.setFillColor(Color::Red);
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
	shapeLS.setSize(Vector2f(x, 1080));
	shapeRS.setPosition(Vector2f(x + 100, 0));
}

float brick::GetPositionX()
{
	return position.x;
}

float brick::GetPositionY()
{
	return position.y;
}



