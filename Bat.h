#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
//그리기 : RectangleShape 
//이동 : 왼쪽으로 이동하는 함수, 오른쪽으로 이동하는 함수. main함수에서 입력처리, 움직일때 기준은 속도와 시간.

enum class Sides
{
	LEFT,
	RIGHT,
	NONE,
};
class Bat
{
private:
	Vector2f position;
	RectangleShape shape; //Rectangle 그리기 함수

	float speed = 1000.f;
	Sides moveDir = Sides::NONE;
public:
	Bat(float x, float y);

	FloatRect GetGlobalBounds();//충돌 체크하기 위해
	const RectangleShape & GetShape();

	void SetMoveDir(Sides side);
	void Update(float dt);
	Vector2f GetBatPosition(Bat bat);

};


