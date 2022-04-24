#include "brickMgr.h"

BrickMgr::BrickMgr(const int& xCount, const int& yCount)
	:xCount(xCount), yCount(yCount)
{
	brickArray = new Brick[xCount * yCount];

	float xPos = 1920.f * 0.5f - 80 * (xCount * 1.0f);
	float yPos = 170 + 0.f;

	for (int i = 0; i < yCount; i++)
	{
		for (int j = 0; j < xCount; j++)
		{
			brickArray[xCount * i + j].SetPosition(xPos, yPos);
			xPos += 170.f;
		}

		yPos += 70.f;
		xPos = 1920.f * 0.5f - 80 * (xCount * 1.0f);
	}
}

BrickMgr::~BrickMgr()
{
	delete[] brickArray;
}

FloatRect BrickMgr::GetGlobalBounds(int i)
{
	return brickArray[i].GetGlobalBounds();
}

const RectangleShape& BrickMgr::GetShape(int i)
{

	return brickArray[i].GetShape();
}

void BrickMgr::DeleteBrick(int idx)
{
}