#ifndef RUNBALL_H
#define RUNBALL_H

#include "ball.h"

class RunBall : public Ball
{
public:
    int Run();
    BallType Type(){return RUNBALL;}
    RunBall(Board *pbd);
    virtual ~RunBall();
protected:
private:
};

#endif // COLORBALL_H
