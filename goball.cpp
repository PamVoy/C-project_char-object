#include "goball.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

GoBall::GoBall(Board *pbd) : Ball(pbd)
{


}

int GoBall::Run()
{
    m_tick++;
    if (m_tick%m_speed) return m_cx*100+m_cy;
    locate(m_cx, m_cy);
    cout << ' ';
    if (m_cx == m_pbd->Getlx()+1) m_dx = -m_dx;
    if (m_cx == m_pbd->Getrx()-1) m_dx = -m_dx;
    if (m_cy == m_pbd->Getly()+1) m_dy = -m_dy;
    if (m_cy == m_pbd->Getry()-1) m_dy = -m_dy;
    m_cx = m_cx + (m_dx);
    m_cy = m_cy;
    locate(m_cx, m_cy);
    setColor(6);
    m_speed=20;
    cout << 'H';
    return m_cx*100+m_cy;
}



GoBall::~GoBall()
{
    //dtor
}
