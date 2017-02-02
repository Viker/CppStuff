#include <iostream>

using namespace std;

struct _Leds
{
    int id; 
    int x;
    int y;
    int color;
};

struct _Ball
{
    int posX = 0;
    int posY = 0;
};

int idCounter = 0; 

_Ball myBall; 


_Leds LedBoard[8][18];

void ShowContents() 
{
    for(int i=0; i < 8; i++)
    {
        if ( (i%2) == 0 )
        {
            for( int j = 0; j < 18; j++)
            {
                _Leds myled;
                myled.x = i;
                myled.y = j; 
                myled.id = idCounter;
                myled.color = 0;
                LedBoard[i][j] = myled;
                idCounter++;
          
            }
        }
        else
        {
            for( int j = 17; j >= 0; j--)
            {
               
                _Leds myled;
                myled.x = i;
                myled.y = j;
                myled.color = 0;
                myled.id = idCounter;
                LedBoard[i][j] = myled;
                idCounter++;
            }
        }
    }
}

void UpdatePlayerPosition(int x,int y)
{ 
    LedBoard[y][x].color = 1;
}


int main(){
    ShowContents();
 
             myBall.posX = 0; 
            myBall.posY = 0; 
            int moveSteps = 0; 

    while ( moveSteps != 15 ) 
    {
            myBall.posX++; 
            if(moveSteps < 5)
                myBall.posY++;
           moveSteps++; 

            UpdatePlayerPosition(myBall.posX,myBall.posY); 
               for(int i = 0; i < 18;i++ )
                {
                    std::cout << "[ " << LedBoard[0][i].color << " " << LedBoard[1][i].color << " " << LedBoard[2][i].color   << " " << LedBoard[3][i].color   << " " << LedBoard[4][i].color   << " " << LedBoard[5][i].color   << " " << LedBoard[6][i].color   << " " << LedBoard[7][i].color   << " ]" << std::endl;     
                }
                std::cout << "__________________________" << std::endl; 
    }
}


