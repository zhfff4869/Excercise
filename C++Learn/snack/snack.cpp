#include <iostream>
#include <random>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <Windows.h>
using namespace std;
#include <time.h>

bool gameOver; //游戏结束标志
bool gameWin;  //游戏胜利标志
bool stop;     //暂停标志
bool hit;      //方向键按下标志
//边界
const int width = 50;
const int height = 20;
//蛇的坐标，食物坐标和分数
int x, y, fruitX, fruitY, score;
//蛇每�?点的坐标
vector<int> tailX, tailY;
//蛇的默认长度
int ntail;

enum Direction
{
    KEEP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
};
Direction Dir;

//开始菜单
void menu()
{
    int a;
    cout << "--------------------------------" << endl;
    cout << "|           snack              |" << endl;
    cout << "|          1.new game          |" << endl;
    cout << "|          2.show look         |" << endl;
    cout << "|          3.quit              |" << endl;
    cout << "--------------------------------" << endl;
    cout << "-->select:";
    cin >> a;
    switch (a)
    {
    case 1:
        stop = false;
        break;
    case 2:
        cout << "width:" << width << "height:" << height << endl;
        stop = true;
        break;
    case 3:
        gameOver = true;
        return;
    default:
        break;
    }
}

//初始化
void setup()
{
    //根据当前时间设置随机数
    srand(time(NULL));
    Dir = KEEP;
    gameOver = false; //游戏结束标志
    gameWin = false;
    stop = true; //暂停标志
    hit = false; //方向键按下标志
    //初始化蛇身坐标
    tailX.clear();
    tailY.clear();
    tailX.resize(200);
    tailY.resize(200);
    //蛇的默认长度
    ntail = 3;
    //蛇的起始位置
    x = width / 2;
    y = height / 2;
    //食物的位置
    fruitX = rand() % width+1;  
    fruitY = rand() % height;
    score = 0;
}
//绘制界面
void draw()
{

    if (stop == true)
    {
        return;
    }
    system("cls"); //清屏
    cout << "score:" << score << endl;

    //line 1

    for (int i = 0; i <= width + 1; i++) //width+bound,bound=2
    {
        cout << "-";
    }
    cout << endl;

    //center
    for (int p = 0; p <height; p++) //高度
    {
        for (int q = 0; q <= width+1; q++) //宽度
        {
            if (q == 0 || q == width + 1) //bound,|占用了2宽度
            {
                cout << "|";
            }

            else
            {
                if (p == fruitY && q == fruitX) //食物的随机坐标,食物范围fruitX=[1,width],fruitY=[0,height-1]
                {
                    cout << 0;
                }
                else
                {
                    bool print = false;
                    for (int i = 0; i < ntail; i++) //搜索蛇的坐标是否包括该点
                    {
                        if (tailX[i] == q && tailY[i] == p)
                        {
                            cout << "*";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }
            }
        }
        cout << endl;
    }

    //last line
    for (int i = 0; i <= width + 1; i++)
    {
        cout << "-";
    }
}

//按键输入控制
void input()
{
    /*     bool key = false;
    int time = 0;
    while (time < 30)
    {
        Sleep(5);
        if (kbhit())
        {
            key = true;
            break;
        }
        time++;
    } */
    if (_kbhit()) //检测是否有键盘按下
    {
        //_getch();   //因为上下左右键是两个字节，先把第一个字节接收，然后用后一个字节判断
        switch (_getch()) //如果按的是数字键盘，就不用接收第一个字节了
        {
        case '4':
        case 75: //左键
            if (Dir == RIGHT)
                break;
            Dir = LEFT;
            hit = true;
            break;
        case '8':
        case 72: //上键
            if (Dir == DOWN)
                break;
            Dir = UP;
            hit = true;
            break;
        case '5': //下键
        case 80:
            if (Dir == UP)
                break;
            Dir = DOWN;
            hit = true;
            break;
        case '6':
        case 77: //右键
            if (Dir == LEFT)
                break;
            Dir = RIGHT;
            hit = true;
            break;
        case 'x':
        case 27: //ESE
            gameOver = true;
            break;
        case 32: //空格
            stop = !stop;
            break;
        default:
            cout << endl
                 << "unused key" << endl;
            stop = true;
            break;
        }
    }
    else if (!hit && stop == false) //没有按方向键也没有stop时的起始运动方向
    {
        x++; //起始向右运动
    }
}

//判断蛇长度
void logic()
{
    if (stop == true)
    {
        return; //疑问
    }
    //根据方向来改变x,y
    switch (Dir)
    {
    case UP:
        y--; //注意y为高度，上意味着减少高度
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    }
    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameOver = true;
        //clearscreen
        system("cls");
    }
    for (int i = 1; i < ntail - 1; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            break;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        //吃了食物，长度加1
        ntail++;
        score += 10;
        //更新下个食物位置
        fruitX = rand() % width+1;
        fruitY = rand() % height;
    }
    //win condition
    if (score > 100)
    {
        gameWin = true;
    }

    //遍历整条蛇的长度，body往后面的空间移动
    for (int i = ntail - 1; i > 0; i--)
    {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    //重新获取当前位置
    tailX[0] = x;
    tailY[0] = y;
}

void GameOver()
{
    system("cls");
    cout << "--------------------------------------------" << endl;
    cout << "|                                          |" << endl;
    cout << "|                                          |" << endl;
    cout << "|                GameOver                  |" << endl;
    cout << "|                                          |" << endl;
    cout << "|                                          |" << endl;
    cout << "--------------------------------------------" << endl;
}
void GameWin()
{
    system("cls");
    cout << "--------------------------------------------" << endl;
    cout << "|                                          |" << endl;
    cout << "|                                          |" << endl;
    cout << "|                GameWin!                  |" << endl;
    cout << "|                                          |" << endl;
    cout << "|                                          |" << endl;
    cout << "--------------------------------------------" << endl;
}

int main()
{
    bool quit = false;
    while (!quit)
    {
        setup();
        menu();
        logic();
        draw();
        //loop吃蛇画面
        while (!gameOver && !gameWin)
        {
            input();
            logic();
            draw();
            Sleep(100);
        }
        if (gameOver)
        {
            GameOver();
        }
        else
        {
            GameWin();
        }
        cout << "really quit(1)?:" << endl;
        cin >> quit;
        if (quit)
        {
            return 0;
        }
        else
        {
            system("cls");
        }

        system("pause");
    }
    return 0;
}
