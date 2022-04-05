#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
 int main(){
 	srand(time(NULL));
 	int  a,b,c;
 	a=rand()%9+1;
 	b=rand()%9+1;
 	c=rand()%9+1;
 	printf("%d, %d, %d\n", a,b,c);
 }