#include "player.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

Player::Player(Board *pbd)
{
    //system("color B7 ");
    m_pbd = pbd;
    m_color = 9;
    m_ch;
    m_er;
    //for(int i=0; i<5 ; i++ ){
    m_cx = (m_pbd->Getlx() + m_pbd->Getrx()) / 2-3;
    //m_cy = (m_pbd->Getly() + m_pbd->Getry()) / 2;
    m_cy = m_pbd->Getry()-2;
    //locate(m_cx[i], m_cy);
    locate(m_cx, m_cy);
    setColor(m_color);
    cout << m_ch;
}
//ctor


/*void Player::up()
{
    if (m_cy > m_pbd->Getly()+1) {
        locate(m_cx, m_cy);
        cout << ' ';
        setColor(m_color);
        locate(m_cx, --m_cy);
        cout << m_ch;
    }
}

void Player::down()
{
    if (m_cy < m_pbd->Getry()-1) {
        locate(m_cx, m_cy);
        cout << ' ';
        setColor(m_color);
        locate(m_cx, ++m_cy);
        cout << m_ch;
    }
}*/

/*void Player::left()
{
    if (m_cx > m_pbd->Getlx()+1) {
        locate(m_cx, m_cy);
        cout << ' ';
        setColor(m_color);
        locate(--m_cx, m_cy);
        cout << m_ch;
    }
}

void Player::right()
{
    if (m_cx < m_pbd->Getrx()-1) {
        locate(m_cx, m_cy);
        cout << ' ';
        setColor(m_color);
        locate(++m_cx, m_cy);
        cout << m_ch;
    }
}*/

void Player::left()
{
    if (m_cx > m_pbd->Getlx()+1)
    {
        locate(m_cx, m_cy);
        cout << m_er;
        setColor(m_color);
        locate(--m_cx, m_cy);
        cout << m_ch;
    }
}

void Player::right()
{
    if (m_cx < m_pbd->Getrx()-7)
    {
        locate(m_cx, m_cy);
        setColor(LIGHTGREEN);
        cout << m_er;
        setColor(m_color);
        locate(++m_cx, m_cy);
        cout << m_ch;
    }
}

Player::~Player()
{
    //dtor
}
