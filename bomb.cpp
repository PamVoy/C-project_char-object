#include "bomb.h"
#include "rlutil.h"

using namespace rlutil;

Bomb::Bomb(Board *pbd) : Ball(pbd)
{
    //system("color B7 ");
    locate(m_cx, m_cy);
    std::cout << ' ';
    m_cx = 20;
    m_cy = 3;
    m_dx = 0;
    m_dy = -1;                                         // ball movement y-axis : -1
    m_ch = '^';
    m_color = 15;
    m_speed = 15;
}

int Bomb::Run()
{
    int pos;
    pos = Ball::R();
    if (m_cx==m_pbd->Getlx()+1) return 8888;          // object is beyond boundaries
    if (m_cx==m_pbd->Getrx()-1) return 8888;
    if (m_cy==m_pbd->Getly()+1) return 8888;
    if (m_cy==m_pbd->Getry()-1) return 8888;
    return pos;
}

Bomb::~Bomb()
{
}
