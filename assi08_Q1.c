#include <stdio.h>

void deliveryCharges(int amount){
    if(amount <= 1000){
        printf("your final amount after delivery charges is %d",amount+150);
    }else if(amount > 1000){
        printf("your final amount is %d enjoy free shipping!", amount);
    }
}

int main() {
    int amount;
    printf("enter your purchase amount : ");
    scanf("%d",&amount);
    
    deliveryCharges(amount);

    return 0;
}
