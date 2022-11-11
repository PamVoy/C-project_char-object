#include "govball.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;


GovBall::GovBall(Board *pbd, Ball *pt) : Ball(pbd)
{
    //system("color B7 ");
    //int site = ball.getPos
    int dd = pt->getmdx();           // get ball object position

    if(dd>0){                        // m_dx = +1, m_cx: +1
       int cc = pt->getPos();
       m_cx= (cc/100)+1;
       m_cy=(cc%100)+1;
    }

     if(dd<0){                       // m_dx = -1, m_cx: -1
       int cc = pt->getPos();
       m_cx= (cc/100)-1;
       m_cy=(cc%100)+1;
    }

    //locate(m_cx , m_cy);
    //std::cout << ' ';
    //m_cy = 3;

    m_ch = 'V';

    m_color = 12;
    m_speed = 3;
}

int GovBall::Run()
{
    m_tick++;
    if (m_cy==m_pbd->Getly()+1) {locate(m_cx, m_cy);cout << ' ';return 9999;}              // object doesn't display beyond boundaries
    else if (m_cy==m_pbd->Getry()-1) {locate(m_cx, m_cy);cout << ' ';return 9999;}
    else {
      if (m_tick%m_speed) return m_cx*100+m_cy;

        if(m_cy <= m_pbd->Getry()-1  &&  m_cy >= m_pbd->Getly()+1){                // object displays in the boundaries
           if(m_cx <= m_pbd->Getrx()-1  &&  m_cx >= m_pbd->Getlx()+1){
              locate(m_cx, m_cy);
              cout << ' ';                                                         // erase 'V', then display ' '

                m_cx = m_cx ;
                m_cy = m_cy + m_dy;                                                // object moves on y-axis +1

                locate(m_cx, m_cy);
                setColor(12);
                m_speed=10;
                cout << m_ch;                                                       // display 'V'                                                                         
              return m_cx*100+m_cy;
           }
        }
    }

}



GovBall::~GovBall()
{
   cout << " ";
}
