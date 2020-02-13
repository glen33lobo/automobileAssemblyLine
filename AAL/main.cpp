#include<GL/glut.h>
#include<stdio.h>

#include<math.h>
#define PI 3.1415926535897932384626433832795
//#define left -30.0
//#define right 30.0
//#define bottom -15.0
//#define top 40.0

int width=12;
int height=12;
//RGBpixmap pix[6];

GLfloat left=-30.0;
GLfloat right=30.0;
GLfloat bottom=-30.0;
GLfloat top=30.0;
GLfloat xmov=0;
GLfloat timer=0;
GLfloat tyrecompressor=2.7;
GLint start=0;
GLfloat outline_red=0;
GLfloat outline_green=0;
GLfloat outline_blue=0;
GLint sign=1;
GLfloat car_color_red=0.5;
GLfloat car_color_green=0.5;
GLfloat car_color_blue=0.5;
GLfloat baking_outline_red=0;

void drawsingleline(float cr,float cg,float cb,float a[2][2])
{
    glColor3f(cr,cg,cb);
    //glColor3f(0.1,0.1,0.1);
    //glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(a[0][0],a[0][1]);
    glVertex2f(a[1][0],a[1][1]);
    glEnd();
}

void drawline(float cr,float cg,float cb,float a[200][2],int n)
{
    glColor3f(cr,cg,cb);
    if(start==3) glLineWidth(outline_red*5);
    //else glLineWidth(1);
    glBegin(GL_LINE_LOOP);

    for(int i=0;i<n-1;i++){
        glPointSize(25);
        glVertex2f(a[i][0],a[i][1]);
        glVertex2f(a[i+1][0],a[i+1][1]);

    }
    glEnd();
}

void drawpolygon(float cr,float cg,float cb,float arr[20][2],int n)
                 {

                     glColor3f(cr,cg,cb);
                     glBegin(GL_POLYGON);
                     for(int i=0;i<n;i++)
                        glVertex2f(arr[i][0],arr[i][1]/*,arr[i][2]*/);
                     glEnd();

                 }

void drawpolygon1(float cr,float cg,float cb,float arr[20][2],int n)
                 {

                     //glColor3f(cr,cg,cb);
                     glBegin(GL_POLYGON);
                     for(int i=0;i<n;i++)
                        glVertex2f(arr[i][0],arr[i][1]/*,arr[i][2]*/);
                     glEnd();

                 }

void drawcircle(float cr,float cg, float cb,int type,float centerx,float centery, float radiusx,float radiusy,float shifter=0)
{
    glColor3f(cr,cg,cb);
    if(type==1){

            float x,y;
    glColor3f(cr,cg,cb);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++)
    {
        x=radiusx*sin(i);
        y=radiusy*cos(i);
        glVertex2f(x+centerx,y+centery);

    }
    glEnd();

    }
    else if(type==0)
    {
            float x,y;
    glColor3f(cr,cg,cb);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<=360;i++)
    {
        x=radiusx*sin(i);
        y=radiusy*cos(i);
        glVertex2f(x+centerx,y+centery);

    }
    glEnd();

        /*
        glBegin(GL_LINE_LOOP);
        for(double i = 0; i < section*PI/2; i += PI / 6000) //<-- Change this Value
            glVertex3f(cx+cos(i) * r, cy+sin(i) * r, 0.0);
        glEnd();*/

    }
    return;
}

void verticalholder(float xshifter,float yshifter=0)
{

    drawcircle(0,0,0,0,8+xshifter,30,1.2,1.2);
    drawcircle(0,0,0,0,-8+xshifter,30,1.2,1.2);

    drawcircle(0.1,0.1,0.1,1,8+xshifter,30,1,1);
    drawcircle(0.1,0.1,0.1,1,-8+xshifter,30,1,1);

    //top 2 holders
    float part5[4][2]={ {-0.7+xshifter,12},{-0.4+xshifter,12},{-0.4+xshifter,30},{-0.7+xshifter,30} };
    drawpolygon(0.1,0.1,0.1,part5,4);
    glLineWidth(1);
    drawline(0,0,0,part5,4);

    float part6[4][2]={ {0.7+xshifter,12},{0.4+xshifter,12},{0.4+xshifter,30},{0.7+xshifter,30} };
    drawpolygon(0.1,0.1,0.1,part6,4);
    glLineWidth(1);
    drawline(0,0,0,part6,4);

    //top bar
    float part3[7][2]={{4+xshifter,29},{0+xshifter,29},{0+xshifter,30},{10+xshifter,30}, {10+xshifter,29},{8+xshifter,28},
    {6+xshifter,28}};
    drawpolygon(0.2,0.2,0.2,part3,7);
    glLineWidth(2);
    float part4[7][2]={{-4+xshifter,29},{0+xshifter,29},{0+xshifter,30},{-10+xshifter,30}, {-10+xshifter,29},{-8+xshifter,28},
    {-6+xshifter,28}};
    drawpolygon(0.2,0.2,0.2,part4,7);
    glLineWidth(2);

    ///outline of top bar
     float part1[10][2]={ {10+xshifter,29},{8+xshifter,28},{6+xshifter,28},{4+xshifter,29},{-4+xshifter,29},{-6+xshifter,28} ,{-8+xshifter,28},{-10+xshifter,29},{-10+xshifter,30},{10+xshifter,30} };
    //drawpolygon(0.2,0.2,0.2,part1,10);
    glLineWidth(2);
    drawline(0,0,0,part1,10);

    //lower box
    float part2[4][2]={ {-0.8+xshifter,12+yshifter},{0.8+xshifter,12+yshifter},{0.8+xshifter,-5+yshifter},{-0.8+xshifter,-5+yshifter} };
    drawpolygon(0.2,0.2,0.2,part2,4);
    glLineWidth(1);
    drawline(0,0,0,part2,4);

    drawcircle(0.1,0.1,0.1,1,0+xshifter,-4.5+yshifter,1,1);



}

void drawBase(float x)
{
    float bef_front_whl[20][2]={ {-18+x,-5},{-16+x,-2},{-17+x,-1},{-19+x,-5} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,
                bef_front_whl,4);
    float front_wheel[][2]={ {-12+x,-2},{-16+x,-2},{-17+x,-1},{-11+x,-1},{-9+x,-5},{-10+x,-5} };//={1,2};
    drawpolygon(car_color_red,car_color_green,car_color_blue,
                front_wheel,6);
    float mid_of_base[20][2]={{-9+x,-5},{9+x,-5},{10+x,-4},{-10+x,-4}};
    drawpolygon(car_color_red,car_color_green,car_color_blue,
                mid_of_base,4);
    float bef_back_whl[20][2]={ {18+x,-5},{16+x,-2},{17+x,-1},{19+x,-5} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,
                bef_back_whl,4);
    float back_wheel[][2]={ {12+x,-2},{16+x,-2},{17+x,-1},{11+x,-1},{9+x,-5},{10+x,-5} };//={1,2};
    drawpolygon(car_color_red,car_color_green,car_color_blue,
                back_wheel,6);

}

void outline_of_car(float cr,float cg, float cb,float xshifter,float yshifter)
{

    float part1[20][2]={ {24+xshifter,-3+yshifter },{19+xshifter,-5+yshifter},{18+xshifter,-5+yshifter},{16+xshifter,-2+yshifter},{12+xshifter,-2+yshifter},{10+xshifter,-5+yshifter},{9+xshifter,-5+yshifter},{-9+xshifter,-5+yshifter},{-10+xshifter,-5+yshifter},{-12+xshifter,-2+yshifter},{-16+xshifter,-2+yshifter},{-18+xshifter,-5+yshifter},{-19+xshifter,-5+yshifter},{-24+xshifter,-2+yshifter},{-24+xshifter,0+yshifter},{-14+xshifter,1+yshifter},{-10+xshifter,4+yshifter},{3+xshifter,5+yshifter},{8+xshifter,1+yshifter},{21+xshifter,0+yshifter}  };
    glLineWidth(2);
    drawline(cr,cg,cb,part1,20);

}

void drawside(float cr,float cg, float cb,float xshifter,float yshifter){

    //front-down
    float part1[10][2]={ {19+xshifter,-5+yshifter},{18+xshifter,-5+yshifter},{16+xshifter,-2+yshifter},{24+xshifter,-3+yshifter} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,part1 ,4);

    //front-up to last-up
    float part2[10][2]={ {16+xshifter,-2+yshifter},{24+xshifter,-3+yshifter},{21+xshifter,0+yshifter},{8+xshifter,1+yshifter},{-14+xshifter,1+yshifter},{-24+xshifter,0+yshifter},{-24+xshifter,-2+yshifter} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,part2 ,7);

    //last down
    float part3[10][2]={ {-19+xshifter,-5+yshifter},{-18+xshifter,-5+yshifter},{-16+xshifter,-2+yshifter},{-24+xshifter,-2+yshifter} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,part3 ,4);

    //top
    float part4[10][2]={ {8+xshifter,1+yshifter},{-14+xshifter,1+yshifter},{-10+xshifter,4+yshifter},{3+xshifter,5+yshifter} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,part4 ,4);

    //middle down
    float part5[10][2]={ {12+xshifter,-2+yshifter},{10+xshifter,-5+yshifter},{-10+xshifter,-5+yshifter},{-12+xshifter,-2+yshifter} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,part5 ,4);

    //door
    float part6[10][2]={ {2.4+xshifter,4.4+yshifter},{7+xshifter,1+yshifter},{7+xshifter,-2+yshifter},{6+xshifter,-4+yshifter},{-2+xshifter,-4+yshifter},{-4.5+xshifter,4+yshifter} };
    drawpolygon(0.2,0.2,0.2,part6 ,6);

	//back mirror 1
	float part7[4][2]={ { -5+xshifter,3.45+yshifter},{ -4+xshifter,yshifter},{ -9.3+xshifter,1+yshifter},{ -9.3+xshifter,3.2+yshifter} };
    drawpolygon(0.1,0.1,0.6,part7,4);

    //back mirror 2
	float part8[3][2]={ { -10+xshifter,3+yshifter},{ -10+xshifter,1+yshifter},{ -12+xshifter,1+yshifter} };
    drawpolygon(0.1,0.1,0.4,part8,3);

    //outline
    outline_of_car(outline_red,outline_green,outline_blue,xshifter,yshifter);
    //float part7[20][2]={ {-24+xshifter,7+yshifter },{-19+xshifter,5+yshifter},{-18+xshifter,5+yshifter},{-16+xshifter,8+yshifter},{-12+xshifter,8+yshifter},{-10+xshifter,5+yshifter},{-9+xshifter,5+yshifter},{9+xshifter,5+yshifter},{10+xshifter,5+yshifter},{12+xshifter,8+yshifter},{16+xshifter,8+yshifter},{18+xshifter,5+yshifter},{19+xshifter,5+yshifter},{24+xshifter,8+yshifter},{24+xshifter,10+yshifter},{14+xshifter,11+yshifter},{10+xshifter,14+yshifter},{-3+xshifter,15+yshifter},{-8+xshifter,11+yshifter},{-21+xshifter,10+yshifter}  };
    //drawline(outline_red,outline_green,outline_blue,part7,20);
}

void drawtop(float cr,float cg, float cb,float shifter)
{
    float part1[10][2]={{2,4+shifter},{-9,3+shifter},{-10,4+shifter},{3,5+shifter},{8,1+shifter},{7,1+shifter} };
    drawpolygon(car_color_red,car_color_green,car_color_blue,part1,6);
    float part2[5][2]={{-9,3+shifter},{-13,1+shifter}, {-14,1+shifter},{-10,4+shifter}};
    drawpolygon(car_color_red,car_color_green,car_color_blue,part2,4);


}

void drawwheels(int type,float cx,float cy,float rx,float ry);

void backscanner(float xshifter,float yshifter)
{          //     66   &&  118
    if(timer<66){
    glPushMatrix();
    glTranslatef(-1+xshifter,-8,0);        // code is from lab manual itself
    glRotatef(timer*32,0,0,1);
    glTranslatef(1-xshifter,8,0);
    drawwheels(1,-1+xshifter,-8,0.75,0.75);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3+xshifter,-8,0);        // code is from lab manual itself
    glRotatef(timer*32,0,0,1);
    glTranslatef(-3-xshifter,8,0);
    drawwheels(1,3+xshifter,-8,0.75,0.75);
    glPopMatrix();
    }
    else if(timer<118)
    {
        glPushMatrix();
    glTranslatef(-1+xshifter,-8,0);        // code is from lab manual itself
    glRotatef(-timer*32,0,0,1);
    glTranslatef(1-xshifter,8,0);
    drawwheels(1,-1+xshifter,-8,0.75,0.75);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3+xshifter,-8,0);        // code is from lab manual itself
    glRotatef(-timer*32,0,0,1);
    glTranslatef(-3-xshifter,8,0);
    drawwheels(1,3+xshifter,-8,0.75,0.75);
    glPopMatrix();
    }
    else
    {
        drawwheels(1,-1+xshifter,-8,0.75,0.75);
        drawwheels(1,3+xshifter,-8,0.75,0.75);
    }
    //this is the back part of the scanner
    float pt1[8][2]={ { 0+xshifter,18+yshifter},{2+xshifter,18+yshifter},{ 2+xshifter,-7+yshifter},
    { 4+xshifter,-7+yshifter},{ 4+xshifter,-8+yshifter},{ -2+xshifter,-8+yshifter },
    { -2+xshifter,-7+yshifter},{ 0+xshifter,-7 +yshifter}};
    //drawpolygon(0.5,0.5,0.5,p1,8);
    drawline(0,0,0,pt1,8);

    float pt2[4][2]={ { 0+xshifter,18+yshifter},{2+xshifter,18+yshifter},{ 2+xshifter,-7+yshifter},
    { 0+xshifter,-7 +yshifter}};
    drawpolygon(0.5,0.5,0.5,pt2,4);
    float pt3[4][2]={ {4+xshifter,-7+yshifter},{4+xshifter,-8+yshifter},{ -2+xshifter,-8+yshifter},
    { -2+xshifter,-7 +yshifter}};
    drawpolygon(0.5,0.5,0.5,pt3,4);
    float pt4[4][2]={ { 0+xshifter,18+yshifter},{2+xshifter,18+yshifter},{ 3+xshifter,19+yshifter},
    { 1+xshifter,19+yshifter}};
    drawpolygon(0.35,0.35,0.35,pt4,4);
    drawline(0,0,0,pt4,4);
    float pt5[4][2]={ { 2+xshifter,18+yshifter},{3+xshifter,19+yshifter},{ 3+xshifter,-6+yshifter},
    { 2+xshifter,-7+yshifter}};
    drawpolygon(0.2,0.2,0.2,pt5,4);
    drawline(0,0,0,pt5,4);
     float pt6[4][2]={ { 2+xshifter,-7+yshifter},{3+xshifter,-6+yshifter},{ 5+xshifter,-6+yshifter},
    { 4+xshifter,-7+yshifter}};
    drawpolygon(0.35,0.35,0.35,pt6,4);
    drawline(0,0,0,pt6,4);
    float pt7[4][2]={ { 4+xshifter,-7+yshifter},{5+xshifter,-6+yshifter},{ 5+xshifter,-7+yshifter},
    { 4+xshifter,-8+yshifter}};
    drawpolygon(0.2,0.2,0.2,pt7,4);
    drawline(0,0,0,pt7,4);
     float pt8[4][2]={ { 0+xshifter,-6+yshifter},{0+xshifter,-7+yshifter},{ -2+xshifter,-7+yshifter},
    { -2+xshifter,-7+yshifter}};
    drawpolygon(0.35,0.35,0.35,pt8,4);
    drawline(0,0,0,pt8,4);
    //back laser
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.9,0,0,0.3);
    float prr1[3][2]={{-0.3+xshifter,17+yshifter},{1+xshifter,18+yshifter},{-0.3+xshifter,17+yshifter}};
    drawpolygon1(0.1,0.1,0.7,prr1 ,3);
    float prr2[4][2]={{-0.3+xshifter,16+yshifter},{1+xshifter,18+yshifter},{1+xshifter,-8+yshifter},{-0.3+xshifter,-9+yshifter}};
    drawpolygon1(0.1,0.1,0.7,prr2 ,4);
    float px[6][2]={{-0.3+xshifter,17+yshifter},{1+xshifter,18+yshifter}};
    glLineWidth(1.5);
   drawsingleline(0.99,0,0,px);
   float px1[6][2]={{1+xshifter,18+yshifter},{1+xshifter,-8+yshifter}};
    glLineWidth(1.5);
   drawsingleline(0.99,0,0,px1);
   float px2[6][2]={{1+xshifter,-8+yshifter},{-0.3+xshifter,-9+yshifter}};
    glLineWidth(1.5);
   drawsingleline(0.99,0,0,px2);
    glDisable(GL_BLEND);
    //all back prts done
}

void frontscanner(float xshifter,float yshifter)
{
    //from hre front parts begin
     //This is the front part of the laser scanner

     if(timer<66){
     glPushMatrix();
    glTranslatef(-5+xshifter,-11,0);        // code is from lab manual itself
    glRotatef(timer*32,0,0,1);
    glTranslatef(5-xshifter,11,0);
     drawwheels(1,-5+xshifter,-11,0.75,0.75);
     glPopMatrix();
     glPushMatrix();
    glTranslatef(-1+xshifter,-11,0);        // code is from lab manual itself
    glRotatef(timer*32,0,0,1);
    glTranslatef(1-xshifter,11,0);
    drawwheels(1,-1+xshifter,-11,0.75,0.75);
    glPopMatrix();
     }
     else if(timer<118)
     {
         glPushMatrix();
    glTranslatef(-5+xshifter,-11,0);        // code is from lab manual itself
    glRotatef(-timer*32,0,0,1);
    glTranslatef(5-xshifter,11,0);
     drawwheels(1,-5+xshifter,-11,0.75,0.75);
     glPopMatrix();
     glPushMatrix();
    glTranslatef(-1+xshifter,-11,0);        // code is from lab manual itself
    glRotatef(-timer*32,0,0,1);
    glTranslatef(1-xshifter,11,0);
    drawwheels(1,-1+xshifter,-11,0.75,0.75);
    glPopMatrix();

     }
     else{
        drawwheels(1,-5+xshifter,-11,0.75,0.75);
        drawwheels(1,-1+xshifter,-11,0.75,0.75);
     }

     float p1[8][2]={ { -4+xshifter,15+yshifter},{-2+xshifter,15+yshifter},{ -2+xshifter,-10+yshifter},
    { 0+xshifter,-10+yshifter},{ 0+xshifter,-11+yshifter},{ -6+xshifter,-11+yshifter },
    { -6+xshifter,-10+yshifter},{ -4+xshifter,-10 +yshifter}};
    //drawpolygon(0.5,0.5,0.5,p1,8);
    drawline(0,0,0,p1,8);
    float p2[4][2]={ { -4+xshifter,15+yshifter},{-2+xshifter,15+yshifter},{ -2+xshifter,-10+yshifter},
    { -4+xshifter,-10 +yshifter}};
    drawpolygon(0.5,0.5,0.5,p2,4);
    float p3[4][2]={ { 0+xshifter,-10+yshifter},{ 0+xshifter,-11+yshifter},{ -6+xshifter,-11+yshifter },
    { -6+xshifter,-10+yshifter}};
    drawpolygon(0.5,0.5,0.5,p3,4);
    float p4[4][2]={ { -2+xshifter,15+yshifter},{-1+xshifter,16+yshifter},{ -3+xshifter,16+yshifter},
    { -4+xshifter,15+yshifter}};
    drawpolygon(0.35,0.35,0.35,p4,4);
    drawline(0,0,0,p4,4);
    float p5[4][2]={ { -2+xshifter,15+yshifter},{-1+xshifter,16+yshifter},{ -1+xshifter,-9+yshifter},
    { -2+xshifter,-10+yshifter}};
    drawpolygon(0.2,0.2,0.2,p5,4);
    drawline(0,0,0,p5,4);
     float p6[4][2]={ { -1+xshifter,-9+yshifter},{1+xshifter,-9+yshifter},{ 0+xshifter,-10+yshifter},
    { -2+xshifter,-10+yshifter}};
    drawpolygon(0.35,0.35,0.35,p6,4);
    drawline(0,0,0,p6,4);
    float p7[4][2]={ { -0+xshifter,-10+yshifter},{1+xshifter,-9+yshifter},{ 1+xshifter,-10+yshifter},
    { 0+xshifter,-11+yshifter}};
    drawpolygon(0.2,0.2,0.2,p7,4);
    drawline(0,0,0,p7,4);
     float p8[4][2]={ { -6+xshifter,-10+yshifter},{-5+xshifter,-9+yshifter},{ -4+xshifter,-9+yshifter},
    { -4+xshifter,-10+yshifter}};
    drawpolygon(0.35,0.35,0.35,p8,4);
    drawline(0,0,0,p8,4);

    //front back
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.9,0,0,0.3);
    float pr1[4][2]={{-2+xshifter,16+yshifter},{-0.3+xshifter,17+yshifter},{-0.3+xshifter,16+yshifter}};
    drawpolygon1(0.1,0.1,0.7,pr1 ,3);
    float pr2[4][2]={{-1+xshifter,16+yshifter},{-0.3+xshifter,16+yshifter},{-0.3+xshifter,-9+yshifter},{-1+xshifter,-9+yshifter}};
    drawpolygon1(0.1,0.1,0.7,pr2 ,4);
    float p[6][2]={{-2+xshifter,16+yshifter},{-0.3+xshifter,17+yshifter}};
    glLineWidth(1.5);
    drawsingleline(0.99,0,0,p);
    glDisable(GL_BLEND);
}

void drawengine(float xshifter,float yshifter)
{
    float part1[6][2]={ { 14.6+xshifter,-0.3+yshifter},{ 15+xshifter,-0.8+yshifter},{ 15+xshifter,-1.5+yshifter},{ 13+xshifter,-1.5+yshifter},{ 13+xshifter,-0.8+yshifter},{ 13.4+xshifter,-0.3+yshifter }};
    drawpolygon(0.4,0.4,0.4,part1,6);
    drawline(0,0,0,part1,6);

    float part2[4][2]={ { 15.6+xshifter,-1.5+yshifter},{ 16.5+xshifter,-0.5+yshifter},{ 18+xshifter,-1.5+yshifter},{ 16.8+xshifter,-2.5+yshifter}};//,{ 13+xshifter,-0.8+yshifter},{ 13.4+xshifter,-0.3+yshifter }};
    drawpolygon(0.3,0.3,0.3,part2,4);
    drawline(0,0,0,part2,4);

    float part3[4][2]={ { 12.4+xshifter,-1.5+yshifter},{ 11.5+xshifter,-0.5+yshifter},{ 10+xshifter,-1.5+yshifter},{ 11.2+xshifter,-2.5+yshifter}};//,{ 13+xshifter,-0.8+yshifter},{ 13.4+xshifter,-0.3+yshifter }};
    drawpolygon(0.3,0.3,0.3,part3,4);
    drawline(0,0,0,part3,4);

    float part4[6][2]={ { 15.6+xshifter,-1.5+yshifter},{ 12.4+xshifter,-1.5+yshifter},{ 11.2+xshifter,-2.5+yshifter},{ 11.2+xshifter,-5+yshifter},{ 16.8+xshifter,-5+yshifter},{ 16.8+xshifter,-2.5+yshifter }};
    drawpolygon(0.5,0.5,0.5,part4,6);
    drawline(0,0,0,part4,6);

    glLineWidth(1);
    drawcircle(0,0,0,1,14+xshifter,-5+yshifter,1.1,1.1);
    drawcircle(0.3,0.3,0.4,1,14+xshifter,-5+yshifter,1,1);



    //sensor
}

void drawwheels(int type,float cx,float cy,float rx,float ry)
{
    //draw wheels

    drawcircle(0,0,0,type,cx,cy,rx,ry);
    drawcircle(0.9,0.92,0.92,type,cx,cy,rx-(0.4*rx),ry-(0.4*ry));

    float part1[4][2]={ {cx,cy},{cx+rx-(0.4*rx),cy+(ry/2)},{cx+rx,cy}};
    drawpolygon(0,0,0,part1,3);

    float part2[4][2]={ {cx,cy},{cx-(rx/2),cy+ry-(0.4*ry)},{cx,cy+ry}};
    drawpolygon(0,0,0,part2,3);

    float part3[4][2]={ {cx,cy},{cx-rx+(0.4*rx),cy-(ry/2)},{cx-rx,cy}};
    drawpolygon(0,0,0,part3,3);

    float part4[4][2]={ {cx,cy},{cx+(rx/2),cy-ry+(0.4*ry)},{cx,cy-ry}};
    drawpolygon(0,0,0,part4,3);

}



void drawseat(float xshifter,float yshifter)
{
    //seats
    float part1[5][2]={ { -4+xshifter,3.5+yshifter},{ -3.5+xshifter,3.6+yshifter},{ -2.5+xshifter,2.5+yshifter},{ -2.8+xshifter,1.5+yshifter} ,{ -3.2+xshifter,1.5+yshifter} };
    drawpolygon(0.8,0.4,0,part1,5);
    drawline(0.5,0.2,0,part1,5);

    float part2[9][2]={ { xshifter,-2+yshifter},{ xshifter,-1+yshifter},{ -1.4+xshifter,1.5+yshifter},{ -2.8+xshifter,1.5+yshifter} ,{ -3.2+xshifter,1.5+yshifter} ,{ -1+xshifter,-4+yshifter},{ 4+xshifter,-4+yshifter},{ 5+xshifter,-3+yshifter},{ 4+xshifter,-1.6+yshifter}  };
    drawpolygon(0.8,0.4,0,part2,9);
    drawline(0.5,0.2,0,part2,9);


}

void drawrobotarm(float xshifter,float yshifter)
{
    float part4[15][2]={{6+xshifter,6+yshifter}, {0+xshifter,1+yshifter},{1+xshifter,0+yshifter},
    {8+xshifter,4+yshifter}};
    drawpolygon(0.5,0.5,0.5,part4,4);
    glLineWidth(1.5);
    drawline(0,0,0,part4,4);
    float part5[15][2]={{10+xshifter,6+yshifter}, {8+xshifter,4+yshifter},{11.5+xshifter,-4+yshifter},
    {16.5+xshifter,-4+yshifter}};
    drawpolygon(0.5,0.5,0.5,part5,4);
    glLineWidth(1.5);
    drawline(0,0,0,part5,4);
    float part6[15][2]={{17+xshifter,-4+yshifter}, {11+xshifter,-4+yshifter},{10+xshifter,-5+yshifter},
    {10+xshifter,-8+yshifter},{18+xshifter,-8+yshifter},{18+xshifter,-5+yshifter}};
    drawpolygon(0.45,0.45,0.45,part6,6);
    glLineWidth(1.5);
    drawline(0,0,0,part6,6);
    drawcircle(0,0,0,1,8+xshifter,-10+yshifter,1,1);
    drawcircle(0.5,0.5,0.5,1,8+xshifter,-10+yshifter,0.5,0.5);
    drawcircle(0,0,0,1,20+xshifter,-10+yshifter,1,1);
    drawcircle(0.5,0.5,0.5,1,20+xshifter,-10+yshifter,0.5,0.5);
    float part7[15][2]={{22+xshifter,-8+yshifter}, {6+xshifter,-8+yshifter},{6+xshifter,-10+yshifter},
    {22+xshifter,-10+yshifter}};
    drawpolygon(0.35,0.35,0.35,part7,4);
    glLineWidth(1.5);
    drawline(0,0,0,part7,4);
    drawcircle(0.5,0.5,0.5,1,0+xshifter,0+yshifter,1,1);
    drawcircle(0.4,0.4,0.4,0.0,0+xshifter,0+yshifter,0.9,0.9);
    drawcircle(0.3,0.3,0.3,1,0+xshifter,0+yshifter,0.7,0.7);
    drawcircle(0.35,0.35,0.35,1,8+xshifter,6+yshifter,2,2);
    drawcircle(0.25,0.25,0.25,1,8+xshifter,6+yshifter,1,1);





}

void drawdoor(float xshifter,float yshifter)
{

    float part1[15][2]={{7+xshifter,0+yshifter}, {7+xshifter,-2+yshifter},{6+xshifter,-4.2+yshifter},{-2+xshifter,-4.2+yshifter},{-3.5+xshifter,0+yshifter},{-3.4+xshifter,0+yshifter}};
    drawpolygon(0.1,0.1,0.7,part1 ,6);
    glLineWidth(1.5);
    drawline(0.1,0.1,0.5,part1,6);
    float part2[15][2]={{7+xshifter,1+yshifter},{7+xshifter,0+yshifter},{6+xshifter,0+yshifter},{6+xshifter,1+yshifter},{2+xshifter,4.4+yshifter}, {2.4+xshifter,4.4+yshifter} };
    drawpolygon(0.1,0.1,0.7,part2 ,6);
    glLineWidth(1.5);
    drawline(0.1,0.1,0.5,part2,6);



    //sideglass

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0,0.5,0.8,0.3);
    float part3[15][2]={{2+xshifter,4.4+yshifter},{-4.5+xshifter,4+yshifter},{-3.5+xshifter,0+yshifter},{6+xshifter,0+yshifter},
    {6+xshifter,1+yshifter} };
    drawpolygon1(0.1,0.1,0.7,part3 ,5);
    glLineWidth(1.5);
    drawline(0.1,0.1,0.5,part3,5);
    glDisable(GL_BLEND);
}

void drawliquid(float liquid_color_red,float liquid_color_green,float liquid_color_blue,float xshifter)
{
        //water
        float filler1[20][2]={ {30+xshifter,-8},{80+xshifter,-8},{80+xshifter,6},{30+xshifter,6} };
        drawpolygon(liquid_color_red,liquid_color_green,liquid_color_blue,filler1,4);

        float outline1[20][2]={ {30+xshifter,-8},{80+xshifter,-8},{80+xshifter,8},{30+xshifter,8} };
        glLineWidth(2);
        drawline(0,0,0,outline1,4);

        //coating
        float filler2[20][2]={ {120+xshifter,-20},{170+xshifter,-20},{170+xshifter,5},{120+xshifter,5} };
        drawpolygon(0.9,0.9,0,filler2,4);

        float outline2[20][2]={ {120+xshifter,-20},{170+xshifter,-20},{170+xshifter,8},{120+xshifter,8} };
        glLineWidth(2);
        drawline(0,0,0,outline2,4);

        //painting
        float filler3[20][2]={ {208+xshifter,-10},{262+xshifter,-10},{262+xshifter,10},{208+xshifter,10} };
        drawpolygon(0,0,0,filler3,4);

        float filler4[20][2]={ {209+xshifter,-9},{261+xshifter,-9},{261+xshifter,9},{209+xshifter,9} };
        drawpolygon(0.5,0.5,1,filler4,4);

}
void baking_section(int frontorback,float cr,float cg,float cb,float xshifter)
{

      float filler5[20][2];
        if(frontorback==1){
                float filler6[20][2]={ {264+xshifter,-13},{264+xshifter,12.5},{324+xshifter,12.5},{324+xshifter,-13} };
        glLineWidth(2);
        drawline(0,0,0.0,filler6,4);
        for(int i=0;i<7;i++)
        {
            filler5[0][0]=264+xshifter;
            filler5[0][1]=-13+i*4;
            filler5[1][0]=264+xshifter;
            filler5[1][1]=-11.5+i*4;
            filler5[2][0]=324+xshifter;
            filler5[2][1]=-11.5+i*4;
            filler5[3][0]=324+xshifter;
            filler5[3][1]=-13+i*4;
            drawpolygon(0.7,0.7,0.7,filler5,4);
            glLineWidth(2);
            drawline(baking_outline_red,0,0,filler5,4);

        }

        //={ {270+xshifter,} }
        //heating
        }
        else if(frontorback==2)    //backside of baking station
        {
            for(int i=0;i<7;i++)
        {
            filler5[0][0]=270+xshifter;
            filler5[0][1]=-10+i*3;
            filler5[1][0]=270+xshifter;
            filler5[1][1]=-9+i*3;
            filler5[2][0]=318+xshifter;
            filler5[2][1]=-9+i*3;
            filler5[3][0]=318+xshifter;
            filler5[3][1]=-10+i*3;
            drawpolygon(0.7,0.7,0.7,filler5,4);
            glLineWidth(2);
            drawline(baking_outline_red,0,0,filler5,4);

        }


        float filler7[20][2]={ {264+xshifter,-13},{264+xshifter,12.5},{270+xshifter,9},{270+xshifter,-10} };
        glLineWidth(2);
        drawpolygon(0.25,0.25,0.25,filler7,4);

        float filler8[20][2]={ {324+xshifter,-13},{324+xshifter,12.5},{318+xshifter,9},{318+xshifter,-10} };
        glLineWidth(2);
        drawpolygon(0.3,0.3,0.3,filler8,4);

        float filler9[20][2]={ {264+xshifter,-13},{324+xshifter,-13},{318+xshifter,-10},{270+xshifter,-10} };
        glLineWidth(2);
        drawpolygon(0.25,0.25,0.25,filler9,4);

        float filler10[20][2]={ {264+xshifter,12.5},{324+xshifter,12.5},{318+xshifter,9},{270+xshifter,9} };
        glLineWidth(2);
        drawpolygon(0.3,0.3,0.3,filler10,4);

        float filler6[20][2]={ {270+xshifter,-10},{270+xshifter,9},{318+xshifter,9},{318+xshifter,-10} };
        glLineWidth(2);
        drawline(0,0,0.0,filler6,4);

        float filler11[20][2]={ {264+xshifter,-13},{264+xshifter,12.5},{270+xshifter,9},{270+xshifter,-10} };
        glLineWidth(2);
        drawline(0,0,0,filler11,4);

        float filler12[20][2]={ {324+xshifter,-13},{324+xshifter,12.5},{318+xshifter,9},{318+xshifter,-10} };
        glLineWidth(2);
        drawline(0,0,0,filler12,4);
        }



}


void drawpainter(int item,float xshifter)
{
        glLineWidth(2);
    if(item==1){
    drawcircle(0.7,0,0,1,212.5+xshifter,0,2,2);

    float painter_rect[4][2]={ {212+xshifter,-7},{213+xshifter,-7},{213+xshifter,0},{212+xshifter,0} };
    drawpolygon(0,0,0,painter_rect,4);

    drawcircle(0,0,1,1,212.5+xshifter,0,1,1);
    }else{
    drawcircle(0,0,1,1,257.5+xshifter,0,1,1);

    float painter_rect[4][2]={ {257+xshifter,-7},{258+xshifter,-7},{258+xshifter,0},{257+xshifter,0} };
    drawpolygon(0,0,0,painter_rect,4);

    drawcircle(0.7,0,0,1,257.5+xshifter,0,2,2);
    }
}

void myReshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        gluPerspective(45,h/w,1,100);
    else
        gluPerspective(45,w/h,1,100);
    glMatrixMode(GL_MODELVIEW);

}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left,right,bottom,top);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void drawbackground()
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-60,70);
    glColor3f(0,1,1);
    glVertex2f(-60,20);
    glColor3f(0,0,1);
    glVertex2f(-60,-50);
    glColor3f(0,1,0);
    glVertex2f(120,-50);
    glColor3f(1,1,1);
    glVertex2f(300,-50);
    glColor3f(1,0,1);
    glVertex2f(300,20);
    glColor3f(1,0,0);
    glVertex2f(300,70);
    glColor3f(1,1,0);
    glVertex2f(120,70);
    glEnd();

        glLineWidth(1);

    float a[2][2];
    for(int i=-25;i<=25;i++)
    {
        a[0][0]=i;  a[0][1]=25;  a[1][0]=i;  a[1][1]=-25;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=i;  a[0][1]=25;  a[1][0]=4*i;  a[1][1]=100;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=i;  a[0][1]=-25;  a[1][0]=4*i;  a[1][1]=-100;
        drawsingleline(0.1,0.1,0.1,a);
    }
    for(int i=-25;i<=25;i++)
    {
        a[0][0]=-25; a[0][1]=i;  a[1][0]=25;  a[1][1]=i;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=-25;  a[0][1]=i; a[1][0]=-100;  a[1][1]=4*i;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=25; a[0][1]=i; a[1][0]=100; a[1][1]=4*i;
        drawsingleline(0.1,0.1,0.1,a);
    }
    for(int i=-25;i>=-100;i--)
    {
        a[0][0]=i;
        a[0][1]=-i;
        a[1][0]=i;
        a[1][1]=i;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=-i;
        a[0][1]=-i;
        a[1][0]=-i;
        a[1][1]=i;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=i;
        a[0][1]=-i;
        a[1][0]=-i;
        a[1][1]=-i;
        drawsingleline(0.1,0.1,0.1,a);

        a[0][0]=i;
        a[0][1]=i;
        a[1][0]=-i;
        a[1][1]=i;
        drawsingleline(0.1,0.1,0.1,a);
    }

    a[0][0]=-25; a[0][1]=25; a[1][0]=-25; a[1][1]=-25;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);
    a[0][0]=25; a[0][1]=-25; a[1][0]=-25; a[1][1]=-25;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);
    a[0][0]=25; a[0][1]=-25; a[1][0]=25; a[1][1]=25;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);
    a[0][0]=25; a[0][1]=25; a[1][0]=-25; a[1][1]=25;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);

    a[0][0]=-25; a[0][1]=25; a[1][0]=-100; a[1][1]=100;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);
    a[0][0]=-25; a[0][1]=-25; a[1][0]=-100; a[1][1]=-100;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);
    a[0][0]=25; a[0][1]=-25; a[1][0]=100; a[1][1]=-100;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);
    a[0][0]=25; a[0][1]=25; a[1][0]=100; a[1][1]=100;
    glLineWidth(2);
    drawsingleline(0.1,0.1,0.1,a);




}

void drawcar()
{
      drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);
            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawseat(0,0);
            drawdoor(0,0) ;
}

void drawcarwithouttyres()
{
      drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);
            drawseat(0,0);
            drawdoor(0,0) ;
}

void display_string(int x, int y, char *string, int font)
{
    int len,i;
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
	        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
    }

}

void display()
{
        glColor3f(1,1,1);

    if(start>=0)
        timer+=0.05;
    glClearColor(0.4,0.9,0.7,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        drawbackground();

    if(start>0 && start < 9)
    {
        float partxx[4][2]={ {-600,30},{600,30},{600,29},{-600,29}  };
        drawpolygon(0,0,0,partxx,4);
    }

    switch(start)
    {
    case 0:{
         glClearColor(0.1 ,0 ,0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    display_string(-18,20,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
	display_string(-14,18,"ST JOSEPH ENGINEERING COLLEGE, MANGALURU - 575028",2);
	display_string(-13,13,"COMPUTER GRAPHICS AND VISUALIZATION MINI PROJECT ON",2);
	display_string(-8,11,"AUTOMOBILE ASSEMBLY LINE",1);
	display_string(-3,5,"SUBMITTED BY",3);
	display_string(-13,2,"GLEN IGNATIUS LOBO",3);
	display_string(5,2,"4SO16CS035",3);
	display_string(-13,0,"GURU SOURABH B",3);
	display_string(5,0,"4SO16CS037",3);

    float part1[4][2]={ {-19,-6},{-19,-20},{19,-20},{19,-6} };
    drawpolygon(0,0,0,part1,4);
    drawline(1,1,1,part1,4);
    glColor3f(1,1,1);
	display_string(-17,-8,"HELP:",3);
	display_string(-15,-11,"-> SPACE BAR FOR NEXT STAGE",3);
	display_string(-15,-14,"-> P FOR PREVIOUS STAGE",3);
	display_string(-8,-18,"PRESS SPACE BAR TO ENTER",2);
        break;
    }

        case 1:
            if(timer<=2*right)   //here the base comes into the display from outside
                {
                    drawBase(-right-right+timer);     //from -60 x value , it comes to center of the screen
                    verticalholder(-right-right+timer);
                }
                else{
                    drawBase(0);
                    verticalholder(0,0);                       // once it reached the center ,it should be there only, at position 0
                }
                glColor3f(1,1,1);
                display_string(-24,23,"ASSEMBLING THE BASE:",1);
                break;
        case 2:if ( timer <= top )      //timer again starts from 0, and the top and side parts will be outside the display since we have used shifting value for y
                {
                    drawBase(0);        //base should be present there itself
                    verticalholder(0,0);
                    drawtop(car_color_red,car_color_green,car_color_blue,2*top-2*timer); //top will come from outside , till its required place .  it will come there because we have used timer variable which will changing as display function calls again and again
                    if(timer+2<top)            //this is for drawing the backside(opposite side) of the car
                        drawside(car_color_red,car_color_green,car_color_blue,0,-top+timer+2);
                    else                //once it reaches its required position it should not move, so this else part
                        drawside(car_color_red,car_color_green,car_color_blue,0,0);
                    drawside(car_color_red,car_color_green,car_color_blue,0,-top+timer);  //this is for front side of the car
                    printf("%f  %f\n",-top,timer);   // i just wanted to see the top and timer values , so i just printed them
                }
                else if (timer > top)  // once the timer equals the top value, only displaying the side is enough, because the top and base part will be inside the side part
                {
                    drawside(car_color_red,car_color_green,car_color_blue,0,0);   // these timer and top values should be equal right, that i got from trial and error method ;)
                    printf("crossed");
                    verticalholder(0,0);
                }
                glColor3f(1,1,1);
                display_string(-24,23,"ASSEMBLING THE SIDE AND THE TOP:",1);
                break;
        case 3:
            left=-30;   // if i go to next phase, then the background size will be enlarged,
            right=30;   // so when i come back to this page, the size should be fixed as it was
            bottom=-30.0;  // before, so i initialized these values again
            top=30.0;       // i have initialized these values at the beginning also, u can check it
            init();      // once values are initialized, init() function should be called, otherwise it will not update the size
            if(outline_red>=1.00)  // outline_red is the red color value for the outline of car
                {
                    sign=-1;   //once it reaches 1, the it should be decreased, so i used sign variable
                }else if(outline_red<=0)
                {
                    sign=1;  //once it reaches 0, the it should be increased
                }
                outline_red+=(sign*0.005);  // here values gets updated. if sign=-1, then decreases , if sign=1
                printf("%f\n\n",outline_red);  //then increases then value of outline_red
                //outline_green+=(sign*0.1);
                //outline_blue+=(sign*0.1);
                drawside(car_color_red,car_color_green,car_color_blue,0,0);  //now draw the side. that red color variable is used in drawside function. there only it changes the outline red color
                glColor3f(1,1,1);
                display_string(-24,23,"FIXTURE OF ALL THE BASIC PARTS:",1);

                verticalholder(0,0);
                break;
        case 4: outline_red=0; //if we change to next phase, then that red color should not be there. so equate it to 0

                if(timer<33){   //the values like 33, 50, 83 etc for timer value are just trail and error values
                    drawliquid(0,0.8,0.8,-timer);  // liquid(water) will be outside display, so it should come inside ryt?...so i moved it using x shift value
                    drawside(car_color_red,car_color_green,car_color_blue,-timer,0); // even the side of car should go little  left side, so i used "timer" to move it
                    verticalholder(-timer,0);
                }
                else if(timer<50){
                    //timer-=0.01;
                    drawliquid(0,0.8,0.8,-33);  // once water comes into display, it should be there only
                    drawside(car_color_red,car_color_green,car_color_blue,-33,timer-33); // now the car side part will move up (change in y value)
                    verticalholder(-33,timer-33);
                }else if(timer<83){
                    if((timer-50+33)<55)  drawliquid(0,0.8,0.8,-(timer-50+33)); // now the liquid comes to the center of display
                    else drawliquid(0,0.8,0.8,-55);  // once it reaches center, it should be there only

                    //drawliquid(0,0.8,0.8,-(timer-50+33));

                    drawside(car_color_red,car_color_green,car_color_blue,-33+timer-50,17);  // car side also comes to the center
                    verticalholder(-33+timer-50,17);
                }
                else if(timer < 100)
                {
                    drawliquid(0,0.8,0.8,-55); //water is at the center only
                    drawside(car_color_red,car_color_green,car_color_blue,0,17-timer+83); //now car side goes into the water
                    verticalholder(0,17-timer+83);
                }
                else{   // once this movement is done, everything should stay at the center itself
                    drawliquid(0,0.8,0.8,-55);  //water at the center
                    drawside(car_color_red,car_color_green,car_color_blue,0,0); //car side in the water
                    verticalholder(0,0);
                }
                if(left>-60) left-=0.03; //this is for resizing the display
                if(right<60) right+=0.03;  //the changes done here will be updated in the init() function
                if(top<50) top+=0.03;    // that is, ortho 2d function gets updated
                if(bottom>-50) bottom-=0.03;
                init();
                glColor3f(1,1,1);
                display_string(-24,35,"WASH STATION:",1);
                break;
        case 5: left=-60;   //when the display is enlarging, if u go to next phase , it will not
                right=60;   // be enlarged completely , so u should specify the size explicitly
                top=50;
                bottom=-50;
                init();         //timer is started again from 0
                if(timer > 294) { car_color_red=0.9;car_color_green=0.9;car_color_blue=0;}  // <-  car side should be yellow once it is dipped in coating liquid
                else {car_color_red=0.5;car_color_green=0.5;car_color_blue=0.5;}  //  <- before that it should be grey
                if(timer<17)
                {
                    drawliquid(0,0.8,0.8,-55);  //  liquid(water) at the center itself
                    drawside(car_color_red,car_color_green,car_color_blue,0,timer); // car side moves up
                    verticalholder(0,timer);
                    glColor3f(1,1,1);
                display_string(-24,35,"WASH STATION:",1);
                }
                else if(timer<107)
                {
                    drawliquid(0,0.8,0.8,-55-timer+17);  // liquid moves to the left and coating liquid comes into display
                    drawside(car_color_red,car_color_green,car_color_blue,0,17);  // car side should be at the top itself
                    verticalholder(0,17);
                    glColor3f(1,1,1);
                    if(timer<65)
                        display_string(-24,35,"WASH STATION:",1);
                    else
                        display_string(-24,35,"PRIMER COATING STATION:",1);
                }
                else if(timer<114)
                {
                    drawside(car_color_red,car_color_green,car_color_blue,0,17-timer+107);  // now the car side comes and stays over the liquid
                    drawliquid(0,0.8,0.8,-145); //coating liquid is at the center itself

                    outline_of_car(outline_red,outline_green,outline_blue,0,17-timer+107); // draw outline of the car, because u may need it for rotation
                    glColor3f(1,1,1);
                    display_string(-24,35,"PRIMER COATING STATION:",1);
                    verticalholder(0,17-timer+107);
                    //float part7[20][2]={ {-24,7+17-timer+107 },{-19,5+17-timer+107},{-18,5+17-timer+107},{-16,8+17-timer+107},{-12,8+17-timer+107},{-10,5+17-timer+107},{-9,5+17-timer+107},{9,5+17-timer+107},{10,5+17-timer+107},{12,8+17-timer+107},{16,8+17-timer+107},{18,5+17-timer+107},{19,5+17-timer+107},{24,8+17-timer+107},{24,10+17-timer+107},{14,11+17-timer+107},{10,14+17-timer+107},{-3,15+17-timer+107},{-8,11+17-timer+107},{-21,10+17-timer+107}  };
                    //drawline(outline_red,outline_green,outline_blue,part7,20);

                    //drawline(0,0,0,)

                }
                else if(timer<476)
                {
                    if(timer<114) timer=114.01;  // i dont know y i wrote this. i had got some error , so i had added this line

                    printf("%f\n",timer);

                    glPushMatrix();  // this is for rotating the car side
                    glTranslatef(0,5,0);        // code is from lab manual itself
                    glRotatef(timer-114,0,0,1);
                    glTranslatef(0,-5,0);
                    drawside(car_color_red,car_color_green,car_color_blue,0,10);
                    glPopMatrix();

                    drawliquid(0,0.8,0.8,-145);  // draw the liquid

                    glPushMatrix();  // this is for rotating the car outline, so that we can see if car is rotating
                    glTranslatef(0,5,0);
                    glRotatef(timer-114,0,0,1);
                    glTranslatef(0,-5,0);
                    outline_of_car(outline_red,outline_green,outline_blue,0,10);
                    glPopMatrix();
                    glColor3f(1,1,1);
                    display_string(-24,35,"PRIMER COATING STATION:",1);
                    verticalholder(0,10);
                }
                else if(timer<483)
                    {
                    drawside(car_color_red,car_color_green,car_color_blue,0,10+timer-476);  //now move the car side up
                    drawliquid(0,0.8,0.8,-145);  //liquid will be present there only
                    //outline_of_car(outline_red,outline_green,outline_blue,0,10);
                    glColor3f(1,1,1);
                    display_string(-24,35,"PRIMER COATING STATION:",1);
                    verticalholder(0,10+timer-476);
                }
                else{
                     drawside(car_color_red,car_color_green,car_color_blue,0,17); // car side is present at the top
                    drawliquid(0,0.8,0.8,-145);  //liquid is present at the center
                    glColor3f(1,1,1);
                    display_string(-24,35,"PRIMER COATING STATION:",1);
                    verticalholder(0,17);
                }
                break;
        case 6: left=-60;   //when the display is enlarging, if u go to next phase , it will not
                right=60;   // be enlarged completely , so u should specify the size explicitly
                top=50;
                bottom=-50;
                init();         //timer is started again from 0


        baking_outline_red=0;
            timer+=0.05;   //i increased the speed of timer variable because it was very slow
                if(timer<30)  // the next function is going to painting section
                {
                    baking_section(2,0.5,0.4,0.9,-145-timer);  //baking_section is a function which displays the baking section of car. here this is actually the backside of baking section, since value passed is 2
                    car_color_red=0.9;    //initial red color value
                    car_color_green=0.9;      // similarly green and blue values
                    car_color_blue=0;
                    drawliquid(0,0,0,-145-timer);  //here liquid is nothing but the container for painting
                    drawpainter(2,-145-timer);     // this is the back painter of painting section , since the value passed is 2
                    drawside(car_color_red,car_color_green,car_color_blue,0-timer,17);  // moves the car to left side, since x shift value is passed
                    verticalholder(0-timer,17);
                    float filler4[20][2]={ {208.5-145-timer,-9.5},{261.5-145-timer,-9.5},{261.5-145-timer,9.5},{208.5-145-timer,9.5} };
                    glLineWidth(2);
                    drawline(0,0,0,filler4,4); // this is the outline for the painting section
                    drawpainter(1,-145-timer);  // this is the front painter , since value passed is 1
                    baking_section(1,0.5,0.4,0.9,-145-timer);  // this is the front of baking section. since value passed is 1
                    glColor3f(1,1,1);
                    display_string(-24,35,"PRIMER COATING STATION:",1);

                }
                else if(timer<120)  // here the car stops moving but the containers should move
                {
                    baking_section(2,0.5,0.4,0.9,-145-timer); // backside of baking section
                    car_color_red=0.9;   // not required actually
                    car_color_green=0.9;
                    car_color_blue=0;

                    drawliquid(0,0,0,-145-timer);  //draws the container
                    drawpainter(2,-145-timer);     // backside painter
                    drawside(car_color_red,car_color_green,car_color_blue,0-30,17);  //car stays there itself
                    verticalholder(-30,17);

                    float filler4[20][2]={ {208.5-145-timer,-9.5},{261.5-145-timer,-9.5},{261.5-145-timer,9.5},{208.5-145-timer,9.5} };
                    glLineWidth(3);
                    drawline(0,0,0,filler4,4); //outine of painting section

                    drawpainter(1,-145-timer);  //front painter
                    baking_section(1,0.5,0.4,0.9,-145-timer);  //front of baking section

                    //glColor3f(1,1,1);
                    //display_string(-20,27,"PAINTING SECTION:",1);
                }
                else if(timer<137)
                {
                    baking_section(2,0.5,0.4,0.9,-265); // backside of baking section
                    drawliquid(0,0,0,-265);  //draws the container
                    drawpainter(2,-265);  // backside painter
                    drawside(car_color_red,car_color_green,car_color_blue,0-30,17-timer+120);   //moves the car down
                    verticalholder(-30,17-timer+120);
                    float filler4[20][2]={ {208.5-265,-9.5},{261.5-265,-9.5},{261.5-265,9.5},{208.5-265,9.5} };
                    glLineWidth(5);
                    drawline(0,0,0,filler4,4);  // outline of painting section
                    drawpainter(1,-265);  //front painter
                    baking_section(1,0.5,0.4,0.9,-265);  //front of baking section

                    glColor3f(1,1,1);
                    display_string(-40,35,"PAINTING SECTION:",1);

                    glColor3f(1,1,1);
                    display_string(20,35,"BAKING SECTION:",1);

                }
                else if(timer<230)
                {
                    baking_section(2,0.5,0.4,0.9,-265);  //back baking section
                    drawliquid(0,0,0,-265);   //painting container

                    //back-side painter
                    if(timer<182)
                    {
                        drawpainter(2,-265-timer+137);  // as timer increments, back painter moves to left
                    }
                    else if(timer<227) {
                            drawpainter(2,-265+timer-227); // as timer increments, back painter moves to right
                    }
                    else {
                            drawpainter(2,-265);   //at the end stay there itself
                    //printf("%f   %f   %f\n",car_color_red,car_color_green,car_color_blue);
                    }

                    //side - car
                    drawside(car_color_red,car_color_green,car_color_blue,-30,0);
                    verticalholder(-30,0);
                    // outline of liquid container
                    float filler4[20][2]={ {208.5-265,-9.5},{261.5-265,-9.5},{261.5-265,9.5},{208.5-265,9.5} };
                    glLineWidth(3);
                    drawline(0,0,0,filler4,4);

                    //draw the front painter
                    if(timer<182)
                    {
                        drawpainter(1,-265+timer-137);  // as timer increments, back painter moves to right
                        car_color_red-=0.0008;          // decrement red color value
                        car_color_green-=0.0008;        // decrement green color value
                        car_color_blue+=0.001;          // increment blue color value
                    }
                    else if(timer<227) {
                            drawpainter(1,-265-timer+227);   // as timer increments, back painter moves to left
                            car_color_red-=0.0008;          // decrement red color value
                        car_color_green-=0.0008;            // decrement green color value
                        car_color_blue+=0.001;              // increment blue color value
                    }
                    else {
                            drawpainter(1,-265);     //at the end stay there itself
                    printf("%f   %f   %f\n",car_color_red,car_color_green,car_color_blue);
                    }
                    baking_section(1,0.5,0.4,0.9,-265);  //front baking section
                    glColor3f(1,1,1);
                    display_string(-40,35,"PAINTING SECTION:",1);

                    glColor3f(1,1,1);
                    display_string(20,35,"BAKING SECTION:",1);

                }
                else if(timer<289)
                {
                    car_color_blue=1;
                    car_color_green=0;
                    car_color_red=0;
                    baking_section(2,0.5,0.4,0.9,-265);  //back baking section
                    drawliquid(0,0,0,-265);         //draw painting container
                    drawpainter(2,-265);            //back painter
                    drawside(car_color_red,car_color_green,car_color_blue,-30+timer-230,0);  // move the car to baking section
                    verticalholder(-30+timer-230,0);
                     float filler3[20][2]={ {208.5-265,-10},{261.5-265,-10},{261.5-265,10},{208.5-265,10} };
                    glLineWidth(10);
                    drawline(0,0,0,filler3,4);  //outline for painting section
                    drawpainter(1,-265);   //front painter
                    baking_section(1,0.5,0.4,0.9,-265);  //front baking section
                    glColor3f(1,1,1);
                    glColor3f(1,1,1);
                    display_string(-40,35,"PAINTING SECTION:",1);

                    glColor3f(1,1,1);
                    display_string(20,35,"BAKING SECTION:",1);
                }else
                {
                    baking_section(2,0.5,0.4,0.9,-265);  //back baking section
                    drawliquid(0,0,0,-265);  //painting section
                    drawpainter(2,-265);   //back painter
                    drawside(car_color_red,car_color_green,car_color_blue,29,0);  //draw car inside baking section
                    verticalholder(29,0);
                    float filler4[20][2]={ {208.5-265,-9.5},{261.5-265,-9.5},{261.5-265,9.5},{208.5-265,9.5} };
                    glLineWidth(5);
                    drawline(0,0,0,filler4,4);  //outline - painting section

                    drawpainter(1,-265);  //front painter
                    baking_section(1,0.5,0.4,0.9,-265);  //front of baking section
                    glColor3f(1,1,1);
                    display_string(-40,35,"PAINTING SECTION:",1);

                    glColor3f(1,1,1);
                    display_string(20,35,"BAKING SECTION:",1);
                }
            break;
        case 7:{

			left=-60;   //when the display is enlarging, if u go to next phase , it will not
                right=60;   // be enlarged completely , so u should specify the size explicitly
                top=50;
                bottom=-50;
                init();         //timer is started again from 0

            if(timer<2)
            {
                baking_outline_red=0;
            }
            car_color_blue=1;
                    car_color_green=0;
                    car_color_red=0;
            if(baking_outline_red>=1.00)   //this is similar to case 3
                {
                    sign=-1;
                }else if(baking_outline_red<=0)
                {
                    sign=1;
                }
                baking_outline_red+=(sign*0.01);
                printf("%f\n\n",outline_red);
                baking_section(2,0.5,0.4,0.9,-265); //back baking section


                drawliquid(0,0,0,-265);  //painting section
                    drawpainter(2,-265); //back painter
                    drawside(car_color_red,car_color_green,car_color_blue,29,0); //draw side
                    verticalholder(29,0);

                    float filler10[20][2]={ {208.5-265,-9.5},{261.5-265,-9.5},{261.5-265,9.5},{208.5-265,9.5} };
                    glLineWidth(5);
                    drawline(0,0,0,filler10,4);  //outline painting section

                    drawpainter(1,-265); //front painter
                    baking_section(1,0.5,0.4,0.9,-265);   //front baking section

                    glColor3f(1,1,1);
                    display_string(-40,35,"PAINTING SECTION:",1);

                    glColor3f(1,1,1);
                    display_string(20,35,"BAKING SECTION:",1);
                    break;

        }

        case 8:
                    left=-30.0;
                    right=30.0;
                    top=30.0;
                    bottom=-30.0;
					init();
                glColor3f(1,1,1);
                    display_string(-24,22,"FIXTURE OF OTHER PARTS:",1);


            if(timer<50){           //engine comes from side
           //         timer-=0.023;
            drawengine(50-timer,-3);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);
            verticalholder(0,0);
            drawrobotarm(50-timer+14,-6);


        }
        else if(timer<60)          //engine gets fixed into car
        {
         //    timer-=0.023;
            drawengine(0,-3+timer-50);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);
            verticalholder(0,0);
            drawrobotarm(+14,-6+timer-50);
            if(timer>53)
                timer=60;
        }
        else if(timer<110) {           //wheels come from bottom

           //     timer+=0.05;
                drawengine(0,0);

            drawside(car_color_red,car_color_green,car_color_blue,0,0);
            verticalholder(0,0);
            drawrobotarm(-60+timer+14,-3);
            drawwheels(1,14-timer+110,-5,2.7,2.7);

            drawwheels(1,-14-timer+110,-5,2.7,2.7);

            drawrobotarm(14-timer+110,-5);
            drawrobotarm(-14-timer+110,-5);

        }
        else if (timer<160)           //wheels are held into the car
        {
         //   timer+=0.05;
            drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);
            verticalholder(0,0);

            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawrobotarm(14+timer-110,-5);
            drawrobotarm(-14+timer-110,-5);
        }
        else if(timer<190)
        {
       //     timer+=0.05;
            drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);

            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawseat(-timer+190,0);
            drawrobotarm(-timer+190,-2);
           verticalholder(0,0);

        }
        else if(timer<220)
        {
            //timer+=0.05;
            drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);

            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawseat(0,0);
            drawrobotarm(timer-190,-2);
            verticalholder(0,0);

        }
         else if(timer<250)
        {
           // timer+=0.05;
            drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);

            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawseat(0,0);
            drawdoor(-timer+250,0);
            drawrobotarm(-timer+250,0);
            verticalholder(0,0);

        }
         else if(timer<280)
        {
            //timer+=0.05;
            drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);

            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawseat(0,0);
            drawdoor(0,0);
            drawrobotarm(timer-250,0);
            verticalholder(0,0);

        }
        else
        {
         //   timer+=0.05;
            drawengine(0,0);
            drawside(car_color_red,car_color_green,car_color_blue,0,0);

            drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
            drawseat(0,0);
            drawdoor(0,0) ;
            verticalholder(0,0);


        }
       //nnn drawseat(0,0);
        break;
        case 9: { drawcarwithouttyres();
                    glLineWidth(1);
                    drawcircle(0,0,0,0,16,-9,2.1,2.1);
                    drawcircle(0,0,0,0,12,-9,2.1,2.1);//outline for sensor of wheel for checking speeds

                    drawcircle(0.3,0.3,0.3,1,16,-9,2,2);
                    drawcircle(0,0,0,1,16,-9,0.5,0.5);//sensor wheel front 1

                    drawcircle(0.3,0.3,0.3,1,12,-9,2,2);
                    drawcircle(0,0,0,1,12,-9,0.5,0.5);//sensor wheel front 2

                    drawcircle(0,0,0,0,-16,-9,2.1,2.1);
                    drawcircle(0,0,0,0,-12,-9,2.1,2.1);//outline for sensor of wheel for checking speeds

                    drawcircle(0.3,0.3,0.3,1,-16,-9,2,2);
                    drawcircle(0,0,0,1,-16,-9,0.5,0.5);//sensor wheel front 1

                    drawcircle(0.3,0.3,0.3,1,-12,-9,2,2);
                    drawcircle(0,0,0,1,-12,-9,0.5,0.5);//sensor wheel front 2


                    float partx[4][2]={ {-24,-14},{-24,-9},{24,-9},{24,-14}  };
                    drawpolygon(0.5,0.5,0.5,partx,4);
                    glLineWidth(3);
                    drawline(0,0,0,partx,4);


                    if(timer<35){
                glPushMatrix();  // this is for rotating the car side
                    glTranslatef(14,-5,0);        // code is from lab manual itself
                    glRotatef(-timer*8*timer,0,0,1);
                    glTranslatef(-14,5,0);
                    drawwheels(1,14,-5,2.7,2.7);
                    glPopMatrix();

                    glPushMatrix();  // this is for rotating the car side
                    glTranslatef(-14,-5,0);        // code is from lab manual itself
                    glRotatef(-timer*8*timer,0,0,1);
                    glTranslatef(14,5,0);
                    drawwheels(1,-14,-5,2.7,2.7);
                    glPopMatrix();
                    }
                    else if(timer<65){
                glPushMatrix();  // this is for rotating the car side
                    glTranslatef(14,-5,0);        // code is from lab manual itself
                    glRotatef(-(66-timer)*8*(timer-66),0,0,1);
                    glTranslatef(-14,5,0);
                    drawwheels(1,14,-5,2.7,2.7);
                    glPopMatrix();

                    glPushMatrix();  // this is for rotating the car side
                    glTranslatef(-14,-5,0);        // code is from lab manual itself
                    glRotatef(-(66-timer)*8*(timer-66),0,0,1);
                    glTranslatef(14,5,0);
                    drawwheels(1,-14,-5,2.7,2.7);
                    glPopMatrix();
                    }
                    else
                    {
                        drawwheels(1,14,-5,2.7,2.7);
            drawwheels(1,-14,-5,2.7,2.7);
                    }


                    float part1[4][2]={ {-8,10 },{-8,28},{8,28},{8,10} };
                    drawpolygon(0.5,0.5,0.5,part1,4);

                    float part2[4][2]={ {-7,11 },{-7,27},{7,27},{7,11} };
                    drawpolygon(0,0,0,part2,4);


                    glColor3f(1,0,0);
                    display_string(0,19,"miles/hr",1);

                    glColor3f(1,1,1);

                    if(timer<35)
                        display_string(-6.5,24,"ACCELERATION TEST",1);
                    else if (timer<70)
                        display_string(-4.5,24,"BRAKING TEST",1);
                    if(timer<5)
                        display_string(-3,19,"0",1);
                    else if(timer<10)
                        display_string(-3,19,"15",1);
                    else if(timer<15)
                        display_string(-3,19,"35",1);
                    else if(timer<20)
                        display_string(-3,19,"70",1);
                    else if(timer<25)
                        display_string(-3,19,"100",1);
                    else if(timer<30)
                        display_string(-3,19,"150",1);
                    else if(timer<35)
                        display_string(-3,19,"200",1);

                    else if(timer<40)
                        display_string(-3,19,"150",1);
                    else if(timer<45)
                        display_string(-3,19,"100",1);
                    else if(timer<50)
                        display_string(-3,19,"70",1);
                    else if(timer<55)
                        display_string(-3,19,"35",1);
                    else if(timer<60)
                        display_string(-3,19,"15",1);
                    else
                        display_string(-3,19,"0",1);
                    if(timer>65){
                            glColor3f(0,1,0);
                        display_string(-2,14,"PASSED",1);
                    }
                    break;
        }
        case 10: { drawcarwithouttyres();

        float partx[4][2]={ {-24,-14},{-24,-8.5},{24,-8.5},{24,-14}  };
                    drawpolygon(0.5,0.5,0.5,partx,4);
                    glLineWidth(3);
                    drawline(0,0,0,partx,4);

                    float partxx[4][2]={ {17,-8.5},{11,-8.5},{11,-7.7},{17,-7.7}  };
                    drawpolygon(1,1,0,partxx,4);
                    glLineWidth(2);
                    drawline(0,0,0,partxx,4);
                    float partxy[4][2]={ {-17,-8.5},{-11,-8.5},{-11,-7.7},{-17,-7.7}  };
                    drawpolygon(1,1,0,partxy,4);
                    glLineWidth(2);
                    drawline(0,0,0,partxy,4);

                float part1[4][2]={ {-8,10 },{-8,28},{8,28},{8,10} };
                    drawpolygon(0.5,0.5,0.5,part1,4);

                    float part2[4][2]={ {-7,11 },{-7,27},{7,27},{7,11} };
                    drawpolygon(0,0,0,part2,4);

                    glColor3f(0.9,0.9,0.9);
                    display_string(-3,22,"STEER TEST",1);
                    printf("%f\n",timer);
                    if(timer>60){
                            glColor3f(0,1,0);
                        display_string(-2,17,"PASSED!!",1);
                    }
                    if(timer<60){
                if(tyrecompressor>=2.7)   //this is similar to case 3
                {
                    sign=-1;
                }else if(tyrecompressor<2.2)
                {
                    sign=+1;
                }
                tyrecompressor+=(sign*0.001);
                 drawwheels(1,14,-5,tyrecompressor,2.7);
                    }
                    else
                        drawwheels(1,14,-5,2.7,2.7);
                drawwheels(1,-14,-5,2.7,2.7);

                break;
        }
        case 11: { //test of internal parts

             float part1[4][2]={ {-8,10 },{-8,28},{8,28},{8,10} };
                    drawpolygon(0.5,0.5,0.5,part1,4);

                    float part2[4][2]={ {-7,11 },{-7,27},{7,27},{7,11} };
                    drawpolygon(0,0,0,part2,4);

                    glColor3f(0.9,0.9,0.9);
                    display_string(-5,22,"INTERNAL PARTS ",1);
                    display_string(-3,20,"TESTING",1);
                    printf("%f\n",timer);
                    if(timer>120){
                            glColor3f(0,1,0);
                        display_string(-3,15,"PASSED!!",1);
                    }

            if(timer<66){
            backscanner(40-timer,0);
            drawcarwithouttyres();
            drawwheels(1,-14,-5,2.7,2.7);
            drawwheels(1,14,-5,2.7,2.7);
             float partx[4][2]={ {-24,-10},{-24,-7.7},{24,-7.7},{24,-10}  };
                    drawpolygon(0.5,0.5,0.5,partx,4);
                    glLineWidth(3);
                    drawline(0,0,0,partx,4);
            frontscanner(40-timer,0);
            printf("%f\n",timer);
            }
            else if(timer<118)
            {
                backscanner(-26-66+timer,0);
            drawcarwithouttyres();
            drawwheels(1,-14,-5,2.7,2.7);
            drawwheels(1,14,-5,2.7,2.7);
             float partx[4][2]={ {-24,-10},{-24,-7.7},{24,-7.7},{24,-10}  };
                    drawpolygon(0.5,0.5,0.5,partx,4);
                    glLineWidth(3);
                    drawline(0,0,0,partx,4);
            frontscanner(-26-66+timer,0);
            printf("%f\n",timer);
            }
            else
            {
                backscanner(26,0);
                drawcarwithouttyres();
                drawwheels(1,-14,-5,2.7,2.7);
                drawwheels(1,14,-5,2.7,2.7);
                float partx[4][2]={ {-24,-10},{-24,-7.7},{24,-7.7},{24,-10}  };
                    drawpolygon(0.5,0.5,0.5,partx,4);
                    glLineWidth(3);
                    drawline(0,0,0,partx,4);
                frontscanner(26,0);
            }
            break;
        }
        case 12:
            {
                 glClearColor(0.1 ,0 ,0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    display_string(-18,20,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
	display_string(-14,18,"ST JOSEPH ENGINEERING COLLEGE, MANGALURU - 575028",2);
	display_string(-13,13,"COMPUTER GRAPHICS AND VISUALIZATION MINI PROJECT ON",2);
	display_string(-8,11,"AUTOMOBILE ASSEMBLY LINE",1);
	display_string(-3,5,"SUBMITTED BY",3);
	display_string(-13,2,"GLEN IGNATIUS LOBO",3);
	display_string(5,2,"4SO16CS035",3);
	display_string(-13,0,"GURU SOURABH B",3);
	display_string(5,0,"4SO16CS037",3);

    float part1[4][2]={ {-19,-6},{-19,-20},{19,-20},{19,-6} };
    drawpolygon(0,0,0,part1,4);
    drawline(1,1,1,part1,4);
    glColor3f(1,1,1);
	display_string(-17,-8,"HELP:",3);
	display_string(-15,-11,"-> SPACE BAR FOR NEXT STAGE",3);
	display_string(-15,-14,"-> P FOR PREVIOUS STAGE",3);
	display_string(-8,-18,"PRESS SPACE BAR TO ENTER",2);
        break;
    }


    }

    //draw wheels
    //drawcircle(0.26,0.56,0.94,1,-14,4,3,4);

    glutPostRedisplay();
    glFlush();
}

void keyPress(unsigned char key,int x,int y)
{
    switch(key)
    {

        case ' ':
            if(start>=12)
                start=12;
            else
                start=start+ 1;    //go to next phase
                timer=0;
                if(start==4)        // i dnt knw y
                {
                    left=-30.0;
                    right=30.0;
                    top=30.0;
                    bottom=-30.0;
                     break;
                }

                if(start>=9)        // i dnt knw y
                {
                    left=-30.0;
                    right=30.0;
                    top=30.0;
                    bottom=-30.0;
                    init();
                }
                if(start==10)
                    tyrecompressor=2.7;
                break;
        case 'p':
                if(start<=0)
                    start=0;
                else
                    start=start-1;  //got to previous phase
                timer=0;
        default: break;
    }
    glutPostRedisplay();


}



int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(1200,1000);
    glutCreateWindow("ASSEMBLY LINE");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(keyPress);
    //glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}
