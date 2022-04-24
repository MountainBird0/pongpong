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

    // 윈도우 생성
    RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);
    //window.setFramerateLimit(60); // 주어진 프레임 비율로 실행
    
    Bat bat(1920.f * 0.5f, 1080.f - 100.f);
    Ball ball(1920.f * 0.5f, 970.f, bat);

    brickMgr brickArr(ySize, xSize);

    int aSize = ySize * xSize;

    bool prevColSide = false;
    bool prevColTop = false;
    bool prevColBat = false;

    bool prevColBri = false;

    Clock clock; // 시계 시작

    int score = 0;
    int life = 3;


    // 게임루프
    while (window.isOpen()) // window가 오픈되어있는동안 프로그램을 실행
    {
        Time dt = clock.restart(); // 시계를 다시 시작
        float deltaTime = dt.asSeconds();

        // 사용자 이벤트 처리
        Event event;

        while (window.pollEvent(event)) // pollEvent : 이벤트가 처리대기중이면 true
        {
            if (event.type == Event::Closed)
                window.close();

        }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }

            // input
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

            //양옆          
            /*shapeLS.setPosition(0.f, 0.f);
            shapeRS.setSize(Vector2f(1920, 380));*/
            //shapeRS.setPosition(270.f, 0.f);
                     
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
                    bool colLS = ballBound.intersects(brickArr.GGB_LS(i));
                    bool colRS = ballBound.intersects(brickArr.GGB_RS(i));

                    if (colLS || colRS)
                    {
                        ball.ReboundSides();
                    }
                    else
                    {
                        ball.ReboundBatOrTop();
                    }

                    for (int j = i; j < aSize - 1;   j++)
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
        //window.draw(brickArr.GS_LS(1));
        //window.draw(brickArr.GS_RS(1));
        window.display();
    }

    return 0;
}