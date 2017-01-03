#include<stdio.h>
#include<math.h>
int upp(int a);
int rith;
 main(){
	int tek;
	printf("Hello turbo c++\n");
	printf("input value of integer");
	scanf("%d",&tek);
       rith=upp(tek);
       printf("value of rith is =%d\n",rith);
	return(0);
}
int upp(int a)
{
	int b;
	b=a+1;
	return(b);
}