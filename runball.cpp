#include "runball.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;


RunBall::RunBall(Board *pbd) : Ball(pbd)
{
    m_cy = 5;                 // spwan new runball at fixed y-axis position
    //ctor
}

int RunBall::Run()
{
    m_tick++;
    m_speed = 14;
    if (m_tick%  (2*(m_speed)) ) return m_cx*100+m_cy;
    locate(m_cx, m_cy);
    cout << ' ';
    if (m_cx == m_pbd->Getlx()+1) m_dx = -m_dx;                  // reflect when encount the playground boundary
    if (m_cx == m_pbd->Getrx()-1) m_dx = -m_dx;
    if (m_cy == m_pbd->Getly()+1) m_dy = -m_dy;
    if (m_cy == m_pbd->Getry()-1) m_dy = -m_dy;
    m_cx = m_cx + (m_dx);           // move horizontally
    m_dy = -m_dy;                   // move verticallly
    m_cy = m_cy + (m_dy);           // jump verticallly

    locate(m_cx, m_cy);
    setColor(10);
    //if (m_color>15) m_color=0;
    m_ch = 'X';
    cout << m_ch;
    return m_cx*100+m_cy;
}


RunBall::~RunBall()
{
    //dtor
}
