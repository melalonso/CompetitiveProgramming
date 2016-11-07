#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int h, m;
    double angle;
    //freopen("input","r",stdin);
    while(scanf("%d:%d",&h,&m),h|m){
        angle = fabs(0.5 * (60*h - 11*m));
        if(angle>180) angle = 360 - angle;
        printf("%.3lf\n",angle);
    }
    return 0;
}
