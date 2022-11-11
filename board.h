#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
    Board(int lx, int ly, int rx, int ry);     // main function setting : Board brd(1,1,40,30);
    int Getlx()
    {
        return m_lx;
    }
    int Getrx()
    {
        return m_rx;
    }
    int Getly()
    {
        return m_ly;
    }
    int Getry()
    {
        return m_ry;
    }
    int Score();
    int Kill();
    int Bonus();

    void Life()
    {
        life++;
    };
    void Gameover();
    void Flash();
    virtual ~Board();
protected:
private:
    void PlotBorder();
    int m_lx;
    int m_ly;
    int m_rx;
    int m_ry;
    int m_color;
    int m_score;
    char m_ch;
    int life;
};

#endif // BOARD_H
