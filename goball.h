#ifndef GOBALL_H
#define GOBALL_H

#include "ball.h"

class GoBall : public Ball
{
    public:
        int Run();
        BallType Type() { return GOBALL; }
        GoBall(Board *pbd);
        virtual ~GoBall();
    protected:
    private:
};

#endif // COLORBALL_H
