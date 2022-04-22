#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include "brick.h"
#include "brickMgr.h"
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

    textMessage.setString("press enter to start");
    textScore.setString("score = 0");
    textLife.setString("Life = 3");

    textMessage.setCharacterSize(75);
    textScore.setCharacterSize(50);
    textLife.setCharacterSize(50);

    textMessage.setFillColor(Color::White);
    textScore.setFillColor(Color::White);
    textLife.setFillColor(Color::White);

    textScore.setPosition(20, 20);
    textLife.setPosition(20, 80);


    RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);
    /*RectangleShape blks[rows][col];
    blocks(blks);*/
    
    Bat bat(1920.f * 0.5f, 1080.f - 100.f);
    Ball ball(1920.f * 0.5f, 970.f, bat);
    //brick brick(50.f, 50.f);

    brickMgr brickArr(ySize, xSize);

    int aSize = ySize * xSize;

    /*for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            brickArr(&i, &j);
        }
    }*/
    

    // ㅇㅇㅇ
    // brickMgr bricks(0, 0);

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
                ball.MoveBall(true, Keyboard::Left);
            }

            dir = Sides::LEFT;
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (!ball.IsMoving())
            {
                ball.MoveBall(true, Keyboard::Right);
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

                //brickArr.brickArray[i] = NULLptr;

                for (int j = i; j < aSize - 1; j++)
                {
                    brickArr.brickArray[j] = brickArr.brickArray[j + 1];
                }
                //delete[i] brickArr.brickArray;
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

        //DrawBlocks(blks);

        //window.draw(bricks.GetShape(0));

        //delete[] brickArr.brickArray;

        window.display();
    }

    return 0;
}