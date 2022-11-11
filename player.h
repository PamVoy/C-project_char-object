#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include <string>

class Player
{
public:
    Player(Board *pbd);
    int getPos()
    {
        return m_cx*100+m_cy;
    }
    //void up();
    //void down();
    void left();
    void right();
    virtual ~Player();
protected:
private:
    Board *m_pbd;
    int m_cx;
    int m_cy;
    int m_color;
    //char m_ch = 'o' ;
    //char m_er = ' ' ;
    std::string m_ch="=======";
    std::string m_er="       ";
};

#endif // PLAYER_H
