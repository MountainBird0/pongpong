#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
//�׸��� : RectangleShape 
//�̵� : �������� �̵��ϴ� �Լ�, ���������� �̵��ϴ� �Լ�. main�Լ����� �Է�ó��, �����϶� ������ �ӵ��� �ð�.

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
	RectangleShape shape; //Rectangle �׸��� �Լ�

	float speed = 1000.f;
	Sides moveDir = Sides::NONE;
public:
	Bat(float x, float y);

	FloatRect GetGlobalBounds();//�浹 üũ�ϱ� ����
	const RectangleShape & GetShape();

	void SetMoveDir(Sides side);
	void Update(float dt);
	Vector2f GetBatPosition(Bat bat);

};


