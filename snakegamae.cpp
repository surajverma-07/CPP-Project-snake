#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

const int width = 20;
const int height = 20;
int x,y,fruitx,fruity,score;
bool GameOver;
enum eDirection {STOP =0,LEFT ,RIGHT,UP,DOWN};
eDirection dir;
int tailX[100],tailY[100];
int nTail;


void Setup()
{
    GameOver=false;
    dir = STOP;
    x= width/2;
    y= height/2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");//cls helps to clear our output screen
    for(int i=0 ; i<width+1 ; i++)
   {
     cout<<"#";
   }
     cout<<endl;

    for(int i=0; i<height ; i++)
    {
        for(int j=0 ; j<width ; j++)
        {
            if( j==0 || j==width-1)
            cout<<"#";
            if(i== y && j==x)
            cout<<"S";
            else if(i== fruity && j==fruitx)
            cout<<"*";
            else
            {
                bool print = false;
              for(int k=0 ; k< nTail ; k++)
              {
                if(tailX[k] == j && tailY[k] == i)
                {
                    cout<<"o";

                    print = true;
                }
              }
                if(!print)
                {
                    cout<<" ";
                }

            }
        }
        cout<<endl;
    }
    for(int i=0 ; i<width+1 ; i++)
   {
     cout<<"#";
   }
     cout<<endl;
     cout<<"Score : "<<score<<endl;

}
void Input()
{
   if(_kbhit())
   {
     switch (_getch())
     {
     case 'a':
        dir = LEFT;
        break;
        case 'd':
        dir = RIGHT;
        break;
        case 'w':
        dir = UP;
        break;
        case 's':
        dir = DOWN;
        case 'x':
        break;
        GameOver = true;
        break;
     }
   }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X , prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir)
    {
        case LEFT:
          x--;
        break;
        case RIGHT:
         x++;
         break;
        case UP:
         y--;
        break;
        case DOWN:
         y++;
        break;
        default:
        break;
    }
     //if(x > width && x<0  || y>height && y<0)
      //GameOver = true;
      if(x >= width)
       x=0;
      else if(x<0)
       x=width-1;

      if(y >=  height)
       y=0;
       else if(y<0)
     y= height-1;
      for(int i=0 ; i< nTail ; i++)
      {
        if(tailX[i]== x && tailY[i] == y)
        GameOver = true;
      }
      if(x== fruitx && y== fruity)
      {
        score +=10;
        fruitx = rand() % width;//get fruits at random process
    fruity = rand() % height;
         nTail++;
      }
}

int main()
{
   Setup();
   while(!GameOver)
   {
      Draw();
      Input();
      Logic();
      // _sleep(100);
      Sleep(30);//slow the speed of snake
   }
  return 0;
}
