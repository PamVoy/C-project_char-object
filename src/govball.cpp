#include "govball.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;


GovBall::GovBall(Board *pbd) : Ball(pbd)
{
    //ctor
}


GovBall::GovBall(Board *pbd) : Ball(pbd)
{
    locate(m_cx, m_cy);
    std::cout << ' ';
    m_cy = 3;
    m_dx = 0;
    m_dy = 1;
    m_ch = 'V';
    m_color = 15;
    m_speed = 3;
}

int GovBall::Run()
{
    m_tick++;
    if (m_cy==m_pbd->Getly()+1)
    {
        locate(m_cx, m_cy);
        cout << ' ';
        return 9999;
    }
    else if (m_cy==m_pbd->Getry()-1)
    {
        locate(m_cx, m_cy);
        cout << ' ';
        return 9999;
    }
    else
    {
        if (m_tick%m_speed) return m_cx*100+m_cy;
        locate(m_cx, m_cy);
        cout << ' ';
        //if (m_cx == m_pbd->Getlx()+1) m_dx = -m_dx;
        //if (m_cx == m_pbd->Getrx()-1) m_dx = -m_dx;
        //if (m_cy == m_pbd->Getly()+1) m_dy = -m_dy;
        //if (m_cy == m_pbd->Getry()-1) m_dy = -m_dy;
        m_cx = m_cx ;
        m_cy = m_cy + m_dy;

        locate(m_cx, m_cy);
        setColor(11);
        m_speed=25;
        cout << m_ch;
        return m_cx*100+m_cy;
    }

}



GovBall::~GovBall()
{

}
