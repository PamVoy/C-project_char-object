#include "board.h"
#include "rlutil.h"
#include <cstdio>

using namespace std;
using namespace rlutil;

Board::Board(int lx, int ly, int rx, int ry)     // set and draw game's playgroung boundary
{
    //system("color B7 ");
    m_lx = lx;
    m_ly = ly;
    m_rx = rx;
    m_ry = ry;
    m_color = WHITE;
    m_ch = '#';                        // draw boundary by '#" element
    m_score = 6000;                    // end game time limit count down 
    life = 0;
    PlotBorder();                      // draw game's playgroung boundary
    //ctor
}

int Board::Score()                     // score = end game time limit count down
{
    int left = (m_lx + m_rx)/2 - 3;   
    locate(left, m_ry);
    setColor(WHITE);
    printf(" %05d ", m_score--);       // time limit count down
    if(m_score==0)return 0;
    else return m_score;
}

void Board::Gameover()                 // game over information 
{
    int left = (m_lx + m_rx)/2 - 5;
    int top  = (m_ly + m_ry)/2 - 2;
    locate(left, top);
    setColor(WHITE);
    printf(" TIME'S UP ");
    locate(left-2, top+1);
    printf("              ");
    locate(left-2, top+2);
    printf(" SCORE = %05d ", life);
    locate(left-2, top+3);
    printf("              ");
    locate(left-2, top+4);
    printf(" press any key");
    msleep(3000);
    getch();

    system("cls");
    system("color 70");
    printf(" \n             Thanks For Palying !  \n \n \n \n");
    Sleep(10);
    printf("     Game Designers:   \n");
    Sleep(25);
    printf("\n  \n           Pam  ,  Kris  ,  Van  ,  Cliff \n \n \n ");
    Sleep(25);
    printf("    Advisor :   \n");
    Sleep(25);
    printf("\n  \n           Prof. Wang \n \n");
    msleep(6000);
    getch();

}

int Board::Kill()                  // life = 0 (initial setting)
{
    life=life+4;                   // kill 
    PlotBorder();
    return life;

}

int Board::Bonus()
{
    life=life+10;                  // kill 
    PlotBorder();
    return life;

}
void Board::Flash()                // game's playgroung boundary color change
{
    int original = m_color;
    m_color = 11;
    PlotBorder();
    msleep(150);
    m_color = 13;
    PlotBorder();
    msleep(150);
    m_color = original;
    PlotBorder();
}

void Board::PlotBorder()             // draw game's playgroung boundary
{
    setColor(m_color);
    for (int i=m_lx; i<=m_rx; i++)
    {
        locate(i, m_ly);
        cout << m_ch;
    }
    for (int i=m_ly; i<=m_ry; i++)
    {
        locate(m_lx, i);
        cout << m_ch;
    }
    for (int i=m_ly; i<=m_ry; i++)
    {
        locate(m_rx, i);
        cout << m_ch;
    }
    for (int i=m_lx; i<=m_rx; i++)
    {
        locate(i, m_ry);
        cout << m_ch;
    }
    locate(m_lx+4, m_ly);
    cout << " SCORE = " << life << " ";
}

Board::~Board()
{
    //dtor
}
