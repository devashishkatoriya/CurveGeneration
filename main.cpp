#include <iostream>
#include <graphics.h>

using namespace std;

void generate_curve(int X[],int Y[],int colour)
{
    int Px,Py;
    double t;
    for(t=0;t<=1;t+=0.0005)
    {
        Px = X[0]*(1-t)*(1-t)*(1-t) + 3*X[1]*t*(1-t)*(1-t) + 3*X[2]*t*t*(1-t) + X[3]*t*t*t;
        Py = Y[0]*(1-t)*(1-t)*(1-t) + 3*Y[1]*t*(1-t)*(1-t) + 3*Y[2]*t*t*(1-t) + Y[3]*t*t*t;
        putpixel(Px,Py,colour);
    }
}

int main()
{
    int i,x[4],y[4];
    char ch;

    int gd,gm;
    gd = DETECT;
    initgraph(&gd,&gm,NULL);

    do
    {
        cout<<"\nEnter the 4 control points :- \n";
        for(i=0;i<4;i++)
        {
            cin>>x[i];
            cin>>y[i];
        }
        generate_curve(x,y,GREEN);
        cout<<"\nDo you want to continue (y/n) ? ";
        cin>>ch;
    }while(ch!='n');

    closegraph();
    cout<<"\nThank you for using this program :)\n\n";
    return 0;
}