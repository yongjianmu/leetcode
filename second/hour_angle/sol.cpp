#include<math.h>
#include<stdio.h>

int main() 
{
    float hour_angle; //时钟当前的真实位置 
    float minute_angle; //分钟当前的真实位置 
    float angle;
    int hour,minute;  
    scanf("%d%d",&hour,&minute);

    if(hour==12)
        hour_angle=((float)minute/60)*30;  
    else
        hour_angle=(hour+(float)minute/60)*30; 

    minute_angle=minute*6;
    angle=fabs(minute_angle-hour_angle); //指针的夹角

    printf("At %d:%02d the angle is %.1f degrees.\n",hour,minute,angle);  
    return 0;
}
