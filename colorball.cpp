#include "colorball.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

ColorBall::ColorBall(Board *pbd) : Ball(pbd)
{
    //system("color B7 ");
    //ctor
}

int ColorBall::Run()
{
    m_tick++;
    m_speed = 25;
    if (m_tick%  ((m_speed)) ) return m_cx*100+m_cy;
    m_cy = 3;                                                     // spwan new runball at fixed y-axis position
    locate(m_cx, m_cy);
    cout << ' ';
    if (m_cx == m_pbd->Getlx()+1) m_dx = -m_dx;                   // reflect when encount the playground boundary
    if (m_cx == m_pbd->Getrx()-1) m_dx = -m_dx;
    //if (m_cy == m_pbd->Getly()+1) m_dy = -m_dy;
    //if (m_cy == m_pbd->Getry()-1) m_dy = -m_dy;
    m_cx += m_dx;
    //m_cy += m_dy;
    locate(m_cx, m_cy);
    setColor(m_color++);
    if (m_color>15) m_color=0;
    m_ch = 'B';
    cout << m_ch;
    return m_cx*100+m_cy;
}



ColorBall::~ColorBall()
{
    //dtor
}
