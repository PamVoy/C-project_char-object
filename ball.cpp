#include "ball.h"
#include <cstdlib>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

Ball::Ball(Board *pbd)
{
    //system("color B7 ");
    int t;
    m_pbd = pbd;                 // pointer of Board
    m_color = LIGHTBLUE;

    t = pbd->Getrx()-pbd->Getlx();  //length of x
    m_cx = pbd->Getlx()+3+(rand()%(t-5));                     // spawn new ball at ramdom x-axis position
    t = pbd->Getry()-pbd->Getly();
    //m_cy = pbd->Getly()+3+(rand()%(t-5));
    m_cy=6;                                                   // spawn new ball at fixed y-axis position
    locate(m_cx, m_cy);
    setColor(m_color);
    m_dx=m_dy=1;
    m_tick=0;
    m_speed=5;

}
int Ball::Run()
{
    m_tick++;
    if (m_tick%m_speed) return m_cx*100+m_cy;        // object move speed 
    locate(m_cx, m_cy);
    cout << ' ';                                     // erase 'W', then display ' '
    if (m_cx == m_pbd->Getlx()+1) m_dx = -m_dx;
    if (m_cx == m_pbd->Getrx()-1) m_dx = -m_dx;
    if (m_cy == m_pbd->Getly()+1) m_dy = -m_dy;
    if (m_cy == m_pbd->Getry()-1) m_dy = -m_dy;
    m_cx = m_cx + (m_dx);
    m_cy = m_cy;
    locate(m_cx, m_cy);
    setColor(14);
    m_speed=30;
    cout << 'W';                                      // dispaly 'W'
    return m_cx*100+m_cy;
}
int Ball::R()                                         // reflect when encount the playground boundary
{
    m_tick++;
    if (m_tick%m_speed) return m_cx*100+m_cy;
    locate(m_cx, m_cy);
    cout << ' ';
    if (m_cx == m_pbd->Getlx()+1) m_dx = -m_dx;
    if (m_cx == m_pbd->Getrx()-1) m_dx = -m_dx;
    if (m_cy == m_pbd->Getly()+1) m_dy = -m_dy;
    if (m_cy == m_pbd->Getry()-1) m_dy = -m_dy;
    m_cx += m_dx;
    m_cy += m_dy;
    locate(m_cx, m_cy);
    setColor(m_color);
    cout << m_ch;
    return m_cx*100+m_cy;
}

Ball::~Ball()                               // destructor for virtual function
{
    locate(m_cx, m_cy);
    std::cout << ' ';
}
