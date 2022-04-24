#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include "Brick.h"
#include "BrickMgr.h"
using namespace sf;
using namespace std;

#define xSize 5
#define ySize 10

#include <random>
#include <sstream>

//contant 점이 네모안에 들어왔나?
// 중심점이 어디들어갔는지 판단

int main()
{
    Font fontDIGI; // 폰트 파일 불러옴
    fontDIGI.loadFromFile("fonts/DS-DIGI.TTF");

    Text textMessage;
    textMessage.setFont(fontDIGI);
    Text textScore;
    textScore.setFont(fontDIGI);
    Text textLife;
    textLife.setFont(fontDIGI);
    Text textClear;
    textClear.setFont(fontDIGI);
    Text textGameOver;
    textGameOver.setFont(fontDIGI);
    Text textGameTitle;
    textGameTitle.setFont(fontDIGI);

    textMessage.setString("press enter to start");
    textScore.setString("score = 0");
    textLife.setString("Life = 3");
    textClear.setString("Clear!");
    textGameOver.setString("GameOver!");
    textGameTitle.setString("Pong Pong");


    textMessage.setCharacterSize(75);
    textScore.setCharacterSize(50);
    textLife.setCharacterSize(50);
    textClear.setCharacterSize(100);
    textGameOver.setCharacterSize(100);
    textGameTitle.setCharacterSize(200);

    textMessage.setFillColor(Color::White);
    textScore.setFillColor(Color::White);
    textLife.setFillColor(Color::White);
    textClear.setFillColor(Color::Yellow);
    textGameOver.setFillColor(Color::Red);
    textGameTitle.setFillColor(Color::Blue);

    textMessage.setPosition(800, 800);
    textScore.setPosition(20, 20);
    textLife.setPosition(20, 80);
    textClear.setPosition(800, 500);
    textGameOver.setPosition(700, 500);
    textGameTitle.setPosition(700, 100);

    RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);

    Bat bat(1920.f * 0.5f, 1080.f - 100.f);
    Ball ball(1920.f * 0.5f, 970.f, bat);

    BrickMgr brickArr(ySize, xSize);

    int aSize = ySize * xSize;

    bool prevColSide = false;
    bool prevColTop = false;
    bool prevColBat = false;
    bool prevColBri = false;

    Clock clock;

    int score = 0;
    int life = 3;

    while (window.isOpen())
    {
        Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Vector2f a = ball.GetSpeed();

        //input
        Sides dir = Sides::NONE;
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (!ball.IsMoving())
            {
                ball.MoveBall(true);
                ball.InitialLeftDir();
            }

            dir = Sides::LEFT;
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (!ball.IsMoving())
            {
                ball.MoveBall(true);
                ball.InitialRightDir();
            }
            dir = Sides::RIGHT;
        }

        bat.SetMoveDir(dir);

        FloatRect ballBound = ball.GetGlobalBounds();
        Vector2u windowSize = window.getSize();

        bool colSide = ballBound.left < 0.f || ballBound.left + ballBound.width > windowSize.x;
        bool colTop = ballBound.top < 0.f;
        bool colBat = ballBound.intersects(bat.GetGlobalBounds());

        //오른쪽, 왼쪽 벽에 부딪혔을때.
        if (!prevColSide && colSide)
        {
            ball.ReboundSides();
        }

        if (!prevColTop && colTop)
        {
            ball.ReboundBatOrTop();
        }

        if (!prevColBat && colBat)
        {
            ball.ReboundBatOrTop();
        }

        else if (ballBound.top + ballBound.height > windowSize.y)
        {
            ball.Reboundbottom();
            life--;
        }

        for (int i = 0; i < aSize; i++)
        {
            bool colBri = ballBound.intersects(brickArr.GetGlobalBounds(i));

            if (!prevColBri && colBri)
            {
                ball.ReboundBatOrTop();

                for (int j = i; j < aSize - 1; j++)
                {
                    brickArr.brickArray[j] = brickArr.brickArray[j + 1];
                }
                --aSize;
                score++;
            }
            prevColBri = colBri;
        }
        prevColSide = colSide;
        prevColTop = colTop;
        prevColBat = colBat;

        //update
        bat.Update(deltaTime);
        ball.Update(deltaTime);

        stringstream ss;
        ss << "Score = " << score;
        textScore.setString(ss.str());

        stringstream ls;
        ls << "Life = " << life;
        textLife.setString(ls.str());

        stringstream clear;
        clear << "Clear!";
        textClear.setString(clear.str());

        stringstream gameover;
        gameover << "GameOver!";
        textGameOver.setString(gameover.str());

        if (aSize == 0 || life == 0)
        {
            ball.StopBall();
            bat.StopBat();
        }

        //draw
        window.clear();
        window.draw(bat.GetShape());
        window.draw(ball.GetShape());

        window.draw(textScore);
        window.draw(textLife);

        for (int i = 0; i < aSize; i++)
        {
              window.draw(brickArr.GetShape(i));
        }
        if (score == 50)
        {
            window.draw(textClear);
        }
        if (life == 0)
        {
            window.draw(textGameOver);
        }
        window.display();
    }
    return 0;
}