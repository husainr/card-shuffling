#include "stdio.h"
#include "graphics.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
 
#define BREADTH 30          //Breadth of card
#define HEIGHT 40                       //Height of card
 
int xco[4]={0,50,200,350},r=75,x,pos,SPEED=14;
 
void swap(int a,int b,int c,int t)  //Function to rotate cards
{
    int y1,y2;
    cleardevice();
    if(pos==a)                      //Change answer position
        pos=b;
    else if(pos==b)
        pos=a;
    for(x=xco[a];x<=xco[b];x++)     //Rotate on circumference
    {
        cleardevice();
        y1=200+sqrt((r*r)-((x-xco[a]-r)*(x-xco[a]-r)));
        y2=200-sqrt((r*r)-((x-xco[a]-r)*(x-xco[a]-r)));
        rectangle(xco[c],200,xco[c]+BREADTH,200+HEIGHT);
        if(t==1)        //Anti-clockwise rotation
        {
            rectangle(x,y1,x+BREADTH,y1+HEIGHT);
            rectangle(xco[b]+xco[a]-x,y2,xco[b]+xco[a]-x+BREADTH,y2+HEIGHT);
        }
        else                    //Clockwise rotation
        {
            rectangle(x,y2,x+BREADTH,y2+HEIGHT);
            rectangle(xco[b]+xco[a]-x,y1,xco[b]+xco[a]-x+BREADTH,y1+HEIGHT);
        }
        delay(SPEED);           //Delay depending on SPEED
    }
}
 
void start()                //For starting animation
{
    int i;
    char str[2];
    cleardevice();
    for(i=1;i<=3;i++)               //Draw three cards & number them 1, 2 & 3
    {
        rectangle(xco[i],200,xco[i]+BREADTH,200+HEIGHT);
        sprintf(str,"%c",i+48);
        outtextxy(xco[i]+BREADTH/2,200+HEIGHT+20,str);
    }
    for(i=0;i<10;i++)               //Indicate start card
    {
        setfillstyle(SOLID_FILL,3+i);
        floodfill(xco[pos]+15,200+15,15);
        delay(250);
    }
}
int main()
{
    int gd,gm,a,b,c,t,i;
    randomize();
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    cleardevice();
    setcolor(15);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    pos=rand()%3+1;                 //Initialize start card positoon randomly
    start();
    for(i=0;i<30;i++) 
        { 
                a=rand()%2+1;           //Choose random pair of cards for swap 
                b=(a==1)?2:3;           //either (1,2) or (2,3) 
                c=(a==1)?3:1; 
                t=rand()%2;             //Randomize t:Indicates anticlockwise/clockwise rotation 
                swap(a,b,c,t); 
                if(SPEED>3) 
                      SPEED--;        //Increase speed i.e. decrease delay time 
        }
    printf("\n\n\t\tPosition of the Card ? (1, 2 or 3)\n\t\t");
    scanf("%d",&t);
    if(t==pos)          //Check if right/wrong
        printf("\n\n\t\tCorrect!!!");
    else
        printf("\n\n\t\tWrong!!!");
    getch();
    return 1;
}