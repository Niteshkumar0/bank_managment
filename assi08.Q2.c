#include <stdio.h>

int finding(int num){
    if(num < 100 || num > 999){
        printf("plssss enter three digits number only");
        return 0;
    }
    
    int least = num%10;
    int most = num/100;
    
    printf("least significant is = %d",least);
    printf("\nmost significant is = %d",most);
    
    return 0;
}


int main() {
     int num;
    printf("enter three digits number : ");
    scanf("%d",&num);
    
    finding(num);
    return 0;
}
