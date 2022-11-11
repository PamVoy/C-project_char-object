#include <iostream>
#include <cstdio>
#include <vector>
#include "board.h"
#include "player.h"
#include "rlutil.h"
#include "govball.h"
#include "colorball.h"
#include "runball.h"
#include "bomb.h"
#include <string>



using namespace std;
using namespace rlutil;

int main()
{
    system("color EC");
    printf(" \n     KILL BEE   \n \n \n");
    Sleep(10);
    printf(" \n     Welcome Soldier!   \n \n");
    Sleep(10);
    printf("     Time Is Limit  \n \n");
    Sleep(25);
    printf("     Kill [B]  &  [X]  &  [W]   \n \n ");
    Sleep(25);
    printf("    Get [V]   \n \n ");
    Sleep(25);
    printf("    Move : <-  &  ->   \n \n");
    Sleep(25);
    printf("     Fire : Space  \n \n");
    Sleep(25);
    printf("     Good luck!");
    Sleep(10);
    printf("\n \n \n \n Press any key to start....");
    getch();
    msleep(1000);

    system("cls");
    system("color 07");
    //system("color B7 ");

    Board brd(1,1,40,30);
    brd.Score();
    Player p1(&brd);
    vector<Ball*> balls;
    int score, lastkey=0, bpos;
    Bomb *bb = NULL;
    Ball *b1 = new Ball(&brd);
    Ball *b2 = new Ball(&brd);
    Ball *b3 = new Ball(&brd);
    Ball *b4 = new Ball(&brd);

    balls.push_back(b1);
    balls.push_back(b2);
    balls.push_back(b3);
    balls.push_back(b4);
    //balls.push_back(new Ball(&brd));
    balls.push_back(new GovBall(&brd, b1));
    //balls.push_back(new GovBall(&brd, b2));
    //balls.push_back(new GovBall(&brd, b3));
    balls.push_back(new ColorBall(&brd));
    balls.push_back(new RunBall(&brd));
    balls.push_back(new RunBall(&brd));
    balls[0]->SetDelay(4);
    balls[1]->SetDelay(8);
    balls[2]->SetDelay(6);
    balls[3]->SetDelay(6);
    hidecursor();
    while (true)
    {
        if (kbhit())
        {
            int k = getkey();
            if (k==KEY_ESCAPE) break;

            if (k==KEY_LEFT) p1.left();
            if (k==KEY_RIGHT) p1.right();
            if (k==KEY_SPACE)
            {
                if (!bb)
                {
                    bb = new Bomb(&brd);
                    int pos = p1.getPos()+300;                  // bullet spawns in the middle of player
                    if (k==KEY_SPACE)
                    {
                        bb->setDir(0,-1);
                        bb->setPos(pos-1);                      // avoid the same position value
                    }

                }
            }
            if (k!=KEY_SPACE) lastkey = k;
        }
        for (vector<Ball*>::iterator it=balls.begin(); it!=balls.end(); it++)  //all balls position data 
        {if(score<=0){brd.Flash();msleep(1000);brd.Flash();msleep(1000);brd.Gameover();return 0;}
            int pos;
            if(bb)                               // bullet exsit
            {
                bpos = bb->Run();                //bullet = bpos
                if (bpos==8888)                  // object is beyond boundaries
                {
                    delete bb;
                    bb=NULL;
                }
            }
            pos = (*it)->Run();
            //if (pos == p1.getPos()){
            if (pos == p1.getPos() || pos == p1.getPos()+100 || pos == p1.getPos()+200 ||                                   // ball 'V' hit player
                    pos == p1.getPos()+300 || pos == p1.getPos()+400 || pos == p1.getPos()+500 || pos == p1.getPos()+600)
            {
                if(brd.Kill())
                {
                    Ball *todelete = (*it);
                    it=balls.erase(it);it--;
                    delete todelete;
                    brd.Life();
                    brd.Flash();
                    locate(pos/100,pos%100);
                    setColor(9);
                    cout<<'=';
                }

            }

            if (pos==bpos&&(*it)->Type()==BALL)                 // boject 'W'
            {
                 if(bb){
                    delete bb;
                    bb=NULL;
                    bpos=9998;
                 }

                brd.Flash();
                brd.Bonus();
                Ball *todelete = (*it);
                it=balls.erase(it);it--;
                delete todelete;

                locate(17,32);
                setColor(11);
                cout<< "Awesome!!";
                msleep(700);locate(17,32);cout<< "         ";

                balls.push_back(new Ball(&brd));
                delete bb;
                bb=NULL;

                //brd.Flash();
                continue;
            }

             if (pos==bpos&&(*it)->Type()==COLORBALL)      
            {
                if(bb){
                    delete bb;
                    bb=NULL;
                    bpos=9998;
                 }

                brd.Flash();
                brd.Bonus();brd.Bonus();brd.Bonus();
                brd.Bonus();brd.Bonus();brd.Bonus();
                brd.Bonus();brd.Bonus();brd.Bonus();
                brd.Bonus();
                Ball *todelete = (*it);
                it=balls.erase(it);it--;
                delete todelete;

                delete bb;
                bb=NULL;

                locate(17,32);
                setColor(11);
                cout<< "Show Time!!";
                msleep(700);locate(17,32);cout<< "           ";

                balls.push_back(new ColorBall(&brd));

                //brd.Flash();
                continue;
            }

             if (pos==bpos&&(*it)->Type()==RUNBALL)         // boject 'X'
            {
                if(bb){
                    delete bb;
                    bb=NULL;
                    bpos=9998;
                 }

                brd.Flash();
                brd.Bonus();brd.Bonus();brd.Bonus();
                brd.Bonus();brd.Bonus();
                Ball *todelete = (*it);
                it=balls.erase(it);it--;
                delete todelete;

                delete bb;
                bb=NULL;

                locate(17,32);
                setColor(11);
                cout<< "Sexy!!";
                msleep(700);locate(17,32);cout<< "      ";

                balls.push_back(new RunBall(&brd));

                //brd.Flash();
                continue;
            }

            if(pos==9999)                             // oblect 'V' is out of boundaries
            {
                Ball *todelete = (*it);
                it = balls.erase(it);it--;
                delete todelete;
            }


        }
        score = brd.Score();
        if (score%300==0) balls.push_back(new GovBall(&brd, b1));
        if (score%420==0) balls.push_back(new GovBall(&brd, b2));
        if (score%510==0) balls.push_back(new GovBall(&brd, b3));
        if (score%550==0) balls.push_back(new GovBall(&brd, b4));
        //if (score%1000==0) balls.push_back(new ColorBall(&brd));
        /*if (score%100==0) balls.push_back(new GovBall(&brd));*/
        msleep(10);
    }
    return 0;
}
