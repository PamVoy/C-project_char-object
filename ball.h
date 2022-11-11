#ifndef BALL_H
#define BALL_H

#include "board.h"

enum BallType {  BALL,COLORBALL, HIDDENBALL, GOVBALL, GOBALL, RUNBALL };

class Ball
{
public:
    Ball(Board *pbd);
    virtual BallType Type()
    {
        return BALL;
    }
    virtual ~Ball();
    virtual int Run();
    virtual int R();                // reflect when encount the playground boundary
    int getPos()
    {
        return 100*m_cx+m_cy;       // object position
    }
    int getmdx()
    {
        return m_dx;
    }
    void SetDelay(int s)
    {
        m_speed=s;
    }

    int m_dx;
protected:
    int m_cx;
    int m_cy;

    int m_dy;
    int m_color;
    int m_tick;
    int m_speed;
    char m_ch;
    Board *m_pbd;
};

#endif // BALL_H
