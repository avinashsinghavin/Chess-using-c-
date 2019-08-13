#include<bits/stdc++.h>
using namespace std;
int player=1;
vector< vector<string> > chess(10,vector<string>(10));
void display();
void insertvalue();
void check(string,string,int);
//===============player 1 all player=======
void p1(int,int,int,int);
void P(int,int,int,int);
void N(int,int,int,int);
void K(int,int,int,int);
void R(int,int,int,int);
void B(int,int,int,int);
int Q1(int,int,int,int);
int Q2(int,int,int,int);
void Q(int,int,int,int);
//===============player 2 all player========
void p2(int,int,int,int);
void p(int,int,int,int);
void n(int,int,int,int);
void k(int,int,int,int);
void r(int,int,int,int);
void b(int,int,int,int);
int q1(int,int,int,int);
int q2(int,int,int,int);
void q(int,int,int,int);
//================main program=================
int main()
{
    cout<<"    Let's Play A Game of Chess"<<endl;
    insertvalue();//inset

    //-----------------------rest program------------------
    //----------------------player selection---------------
    int gameon=1,z=1;
    string mov1,mov2;
    while(gameon!=0)
    {
        if(z==0)
            break;
        //display
//----------------------player 1--------------------------;
        while(z!=0)
        {
            cout<<endl<<endl;
            if(player==1)
            {
                display();
                cout<<"Enter The Option given below"<<endl;
                cout<<"Player 1 Turn!"<<endl;
                cout<<"Enter 0 For Quit Enter 1 for conti. "<<endl;
                cin>>gameon;
                if(gameon==0)
                {
                    cout<<"Player 2 Win "<<endl;
                    break;
                }
                cout<<"\nEnter The move (char must be caps)"<<endl;
                cin>>mov1>>mov2;
                check(mov1,mov2,1);
            }
            if(player==2)
            {
                display();
                cout<<"Enter The Option given below"<<endl;
                cout<<"Player 2 Turn!"<<endl;
                cout<<"Enter 0 For Quit Enter 1 for conti. "<<endl;
                cin>>gameon;
                if(gameon==0)
                {
                    cout<<"Player 1 Win "<<endl;
                    break;
                }
                cout<<"\nEnter The move (char must be caps)"<<endl;
                cin>>mov1>>mov2;
                check(mov1,mov2,2);
            }
        }
    }
}
//======================player 1 check point==============
void p1(int x,int y,int xx,int yy)
{
    if((x>0 && x<9) && (xx>0 && xx<9) && (yy>0 && yy<9) &&(y>0 && y<9)&&((chess[yy][xx][0]!='P')||(chess[yy][xx][0]!='N')||(chess[yy][xx][0]!='K')||(chess[yy][xx][0]!='Q')||(chess[yy][xx][0]!='B')||(chess[yy][xx][0]!='R')))
    {
    //--------------P--------------------
        if(chess[y][x][0]=='P')
            P(x,y,xx,yy);
    //-------------------N-------------------
        if(chess[y][x][0]=='N')
            N(x,y,xx,yy);
    //---------------------King----------------
        if(chess[y][x][0]=='K')
            K(x,y,xx,yy);
    //----------------------R------------------
        if(chess[y][x][0]=='R')
            R(x,y,xx,yy);
    //----------------------B---------------------
        if(chess[y][x][0]=='B')
            B(x,y,xx,yy);
    //-----------------------Q------------------------
        if(chess[y][x][0]=='Q')
            Q(x,y,xx,yy);
    }
    else
        cout<<"Invalid Move"<<endl;
}

//==========================player 1 pay point==============
void Q(int x,int y,int xx,int yy)
{
    int a=Q1(x,y,xx,yy);
    int b=Q2(x,y,xx,yy);
    if(a==1 || b==1)
    {
        chess[yy][xx]='Q';
        chess[y][x]=' ';
        player=1;
        if(chess[yy][xx][0]=='K')
                cout<<"Player 2 Wins"<<endl;
    }
    else
        cout<<"Invalid Move";
}
void B(int x,int y,int xx,int yy)
{
    int a,b;
    a=xx-x;
    if(a<0)
        a=-a;
    b=yy-y;
    if(b<0)
        b=-b;
    if(a==b)
    {
        chess[yy][xx]='B';
        chess[y][x]=' ';
        player=2;
        if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
    }
}
int Q1(int x,int y,int xx,int yy)
{
    int a,b;
    a=xx-x;
    if(a<0)
        a=-a;
    b=yy-y;
    if(b<0)
        b=-b;
    if(a==b)
        return 1;
    if(a!=b)
        return 0;
}

int Q2(int x,int y,int xx,int yy)
{
    cout<<"In Q2"<<endl;
    if((xx==x&&yy<9)||(yy==y &&(xx<9)))
        return 1;
    else
        return 0;
}
void R(int x,int y,int xx,int yy)
{
    if((xx==x&&yy<9)||(yy==y &&(xx<9)))
    {
        chess[yy][xx]='R';
        chess[y][x]=' ';
        player=2;
        if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
    }
    else
        cout<<"Invalid move"<<endl;
}
void K(int x,int y,int xx,int yy)
{
    if((xx==x+1 && yy==y+1)||(xx==x-1 && yy==y+1)||(x==xx&&yy==y+1)||(x==xx&&yy==y-1)||(xx==x-1 && y==yy) ||(xx==x-1 && yy==y-1)||(xx==x+1 && yy==y-1))
        if(chess[yy][xx][0]!='P'&&chess[yy][xx][0]!='Q'&&chess[yy][xx][0]!='N'&&chess[yy][xx][0]!='B'&&chess[yy][xx][0]!='R')
        {
            chess[yy][xx]='K';
            chess[y][x]=' ';
            player=2;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
}
void N(int x,int y,int xx,int yy)
{
    if((xx==x+2 && yy==y-1)||(xx==x+1 && yy==y-2)||(xx==x-1 && yy==y-2)||(xx==x-2 && yy==y-1)||(xx==x+2 && yy==y+1)||(xx==x+1 && yy==y+2)||(xx==x-2 && yy==y+1)||(xx==x-1 && yy==y+2))
    {
        chess[yy][xx]='N';
        chess[y][x]=' ';
        player=2;
        if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
    }
    else
        cout<<"Wrong Move"<<endl;
}
void P(int x,int y,int xx,int yy)
{

    if(x==1)
    {
        if(((yy==y+1)||(yy==y+1 && xx==x+1 && chess[x+1][y+1][0]!='\n')||(y+2==yy))&&(chess[xx][yy][0]!='P'||chess[xx][yy][0]!='R'||chess[xx][yy][0]!='N'||chess[xx][yy][0]!='B'||chess[xx][yy][0]!='K'||chess[xx][yy][0]!='Q'))
        {
            chess[yy][xx]='P';
            chess[y][x]=' ';
            player=2;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
        else
            cout<<"invalid move Enter Again";
    }
    else if(x==8)
    {
        if(yy==y+1||(yy==y+1 && xx==x-1 && chess[xx-1][yy-1][0]!='\n')||y+2==yy)
        {
            chess[yy][xx]='P';
            chess[y][x]=' ';
            player=2;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
        else
            cout<<"invalid move Enter Again";
    }
    else
    {
        if((yy==y+1)||(yy==y+2)||((yy==y+1 && xx==x-1 )|| (xx==x+1 &&yy==y+1) && (chess[xx][yy][0]!='\n')))
        {
            chess[yy][xx]='P';
            chess[y][x]=' ';
            player=2;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
    }
}
//======================player 2 check point==============
void q(int x,int y,int xx,int yy)
{
    int a=q1(x,y,xx,yy);
    int c=q2(x,y,xx,yy);
    if(a==1 || c==1)
    {
        chess[yy][xx]='q';
        chess[y][x]=' ';
        player=1;
        if(chess[yy][xx][0]=='K')
        {
            cout<<"Player 2 Win"<<endl;
        }

    }
    else
        cout<<"Invalid Move";

}
int q1(int x,int y,int xx,int yy)
{
    int a,b;
    a=xx-x;
    if(a<0)
        a=-a;
    b=yy-y;
    if(b<0)
        b=-b;
    if(a==b)
        return 1;
    if(a!=b)
        return 0;
}

int q2(int x,int y,int xx,int yy)
{
    if((xx==x&&yy<9)||(yy==y &&(xx<9)))
        return 1;
    else
        return 0;
}
void p2(int x,int y,int xx,int yy)
{
    if((x>0 && x<9) && (xx>0 && xx<9) && (yy>0 && yy<9) &&(y>0 && y<9)&&(chess[yy][xx][0]!='p')&&chess[yy][xx][0]!='n'&&chess[yy][xx][0]!='k'&&chess[yy][xx][0]!='q'&&chess[yy][xx][0]!='b'&&chess[yy][xx][0]!='r')
    {
        if(chess[y][x][0]=='p')
            p(x,y,xx,yy);
        if(chess[y][x][0]=='n')
            n(x,y,xx,yy);
        if(chess[y][x][0]=='k')
            k(x,y,xx,yy);
        if(chess[y][x][0]=='r')
            r(x,y,xx,yy);
        if(chess[y][x][0]=='b')
            b(x,y,xx,yy);
    }
    else
        cout<<"Invalid Move"<<endl;

}

//==========================player 2 Play point==============
void r(int x,int y,int xx,int yy)
{
    if((xx==x&&yy<9)||(yy==y &&(xx<9)))
    {
        chess[yy][xx]='r';
        chess[y][x]=' ';
        player=1;
    if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
    }
    else
        cout<<"Invalid move"<<endl;
}
void b(int x,int y,int xx,int yy)
{
    int a,b;
    a=xx-x;
    if(a<0)
        a=-a;
    b=yy-y;
    if(b<0)
        b=-b;
    if(a==b)
    {
        chess[yy][xx]='b';
        chess[y][x]=' ';
        player=1;
        if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
    }
}
void k(int x,int y,int xx,int yy)
{
    if((xx==x+1 && yy==y+1)||(xx==x-1 && yy==y+1)||(x==xx&&yy==y+1)||(x==xx&&yy==y-1)||(xx==x-1 && y==yy) ||(xx==x-1 && yy==y-1)||(xx==x+1 && yy==y-1))
        {
            chess[yy][xx]='k';
            chess[y][x]=' ';
            player=1;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
}
void n(int x,int y,int xx,int yy)
{
    if((xx==x+2 && yy==y-1)||(xx==x+1 && yy==y-2)||(xx==x-1 && yy==y-2)||(xx==x-2 && yy==y-1)||(xx==x+2 && yy==y+1)||(xx==x+1 && yy==y+2)||(xx==x-2 && yy==y+1)||(xx==x-1 && yy==y+2))
        {
            chess[yy][xx]='n';
            chess[y][x]=' ';
            player=1;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
}
void p(int x,int y,int xx,int yy)
{
    if(x==1)
    {
        if(yy==y-1||(yy==y-1 && xx==x-1 && chess[x-1][y-1][0]!='\n')||y-2==yy)
        {
            chess[yy][xx]='p';
            chess[y][x]=' ';
            player=1;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
        else
            cout<<"invalid move Enter Again";
    }
    else if(x==8)
    {
        if(yy==y-1||(yy==y-1 && xx==x-1 && chess[xx-1][yy-1][0]!='\n')||y-2==yy)
        {
            chess[yy][xx]='p';
            chess[y][x]=' ';
            player=1;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
        else
            cout<<"invalid move Enter Again";
    }
    else
    {
        if((yy==y-1)||(yy==y-2)||(yy==y-1 && xx==x-1 )|| xx==x+1 || (chess[xx-1][yy-1][0]!='\n'||chess[xx+1][yy-1][0]!='\n'))
        {

            chess[yy][xx]='p';
            chess[y][x]=' ';
            player=1;
            if(chess[yy][xx][0]=='K')
            {
                cout<<"Player 2 Wins"<<endl;
            }
        }
    }
}
//============================check point of Steps================
void check(string mov,string mov2,int p)
{
    int x,y,xx,yy,j=1;
    for(char i='A';i<'i';i++,j++)
        if(mov[0]==i)
            break;
    x=j;j=1;
    for(char i='1';i<'9';i++,j++)
        if(mov[1]==i)
            break;
    y=j;j=1;
    //=============move2==========
    for(char i='A';i<'i';i++,j++)
        if(mov2[0]==i)
            break;
    xx=j;j=1;
    for(char i='1';i<'9';i++,j++)
        if(mov2[1]==i)
            break;
    yy=j;
    //cout<<x<<"   "<<y<<"--voidcheck--"<<xx<<" "<<yy<<endl;
    if(p==1)
        p1(x,y,xx,yy);
   if(p==2)
        p2(x,y,xx,yy);
}
//===========================for(inserting value)============
void insertvalue()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            chess[0][0]="_________ABCDEFGH______________";
            chess[9][0]="_________ABCDEFGH______________";
            if(j==0&& i!=0 && i!=9)
                chess[i][j]="       |";
            if(j==9&& i!=0 && i!=9)
                chess[i][j]="|";
            if(j==9 && i==1)
                chess[i][j]="|     Player-1";
            if(j==9 && i==8)
                chess[i][j]="|     Player-2";
            if(i==2 && j!=0&& j!=9)
                chess[i][j]="P";
            if(i==7 && j!=0&& j!=9)
                chess[i][j]="p";
            if(i==1)
            {
                if(j==1 ||j==8)
                    chess[i][j]="R";
                if(j==2 ||j==7)
                    chess[i][j]="N";
                if(j==3 ||j==6)
                    chess[i][j]="B";
                if(j==4)
                    chess[i][j]="Q";
                if(j==5)
                    chess[i][j]="K";
            }
            if(i==8)
            {
                if(j==1 ||j==8)
                    chess[i][j]="r";
                if(j==2 ||j==7)
                    chess[i][j]="n";
                if(j==3 ||j==6)
                    chess[i][j]="b";
                if(j==4)
                    chess[i][j]="q";
                if(j==5)
                    chess[i][j]="k";
            }
            if(j>0 && j<9 && i>2&&i<7)
                chess[i][j]=" ";
        }
    }
}
//========================for(display)======================
void display()
{
    for(int i=0;i<10;i++)
    {
        if(i>0 && i<9)
            cout<<i;
        for(int j=0;j<10;j++)
            cout<<chess[i][j];
        cout<<endl;
    }
}
/*
x---12345678
        _____ABCDEFGH_____
y   1       |RNBQKBNR|  player 1
y   2       |PPPPPPPP|
y   3       |        |
y   4       |        |
y   5       |        |
y   6       |        |
y   7       |pppppppp|
y   8       |rnbqkbnr|  player-2
       _____ABCDEFGH_____

*/
