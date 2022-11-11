#ifndef GOVBALL_H
#define GOVBALL_H

#include "ball.h"

class GovBall : public Ball
{
    public:
        int Run();
        BallType Type() { return GOVBALL; }
        GovBall(Board *pbd, Ball *parent  );
        virtual ~GovBall();

    protected:
    private:
};

#endif // COLORBALL_H
