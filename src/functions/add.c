#include<stdio.h>
int add(int a, int b){
return a+b;
}
int main(){
int num1=4, num2=3;
printf("%d+%d = %d\n", num1, num2, add(num1, num2));
return 0;
}
