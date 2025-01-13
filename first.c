
#include <stdio.h>
#include <string.h>

struct User
{
    char name[20];
    char created[40];
    int balanace;
    long cnic;
};

struct User p1;
struct User newUser;
void mainFeatures();
void AskingAccount();
void AlreadyAccount();
void AccountDetail();
void  Withdraw();
void Deposit();
void AskingDetailForCreateAccount();
//LOGIN PAGE
int login() {

    strcpy(p1.name,"nitesh");
    p1.cnic = 4510114534179;
    strcpy(p1.created,"1-1-25");
    p1.balanace = 10000000;


    printf("\n\n\n");
    printf("                               ====== Bank Mangnment System ==========            ");
    int username = 0;
    printf("\n\n\nEnter your username: ");
    scanf("%d", &username);

    int password = 0;
    printf("Enter your password: ");
    scanf("%d", &password);

    if(username == 123 && password == 123) {
        printf("Login Successful!\n\n");
        return 1;
    }
    else {
        printf("Invalid Username or Password");
        return 0;
    }
}

//ASKING ACCOUN FROM USER
void AskingAccount(){
    printf("                                ============= Optionss =============            ");
    int account =0;
    printf("\n\n\n-> 1) you have account");
    printf("\n-> 2) you want to create \n\n");
    scanf("%d",&account);

    if (account == 1)
    {
        AlreadyAccount();
    }else if (account == 2)
    {
        AskingDetailForCreateAccount();
    }
}


//ALREADY ACCOUNT
void AlreadyAccount(){

    char search[5] = "yes";
    long initialCnic = 4510114534179;
    int alreadyPassword = 4545;
    long cnic = 0;
    int password = 0;
        printf("\n\n\n\n");
        printf("                      ============================  Information ============================  \n\n");
        printf("enter cnic : ");
        scanf("%ld",&cnic);
        printf("enter password : ");
        scanf("%d",&password);


    while (initialCnic != cnic && password != alreadyPassword){

        printf("\n\nincorrect!!");
        printf("\n\ndo you want to continue search account (yes/no): ");
        scanf("%s",&search);

    printf("\n\n");
        if (strchr(search,"yes")==0)
        {
             printf("enter cnic : ");
            scanf("%ld",&cnic);
            printf("enter password : ");
            scanf("%d",&password);
        }

    }
    
    if (initialCnic == cnic && alreadyPassword == password){
        mainFeatures(p1);
    }
    
}

//MAIN FEATURES 
void mainFeatures(struct User p1) {
    int choice;
    printf("\n\nWhich Function do you want to Perform?\n\n");
    printf("-> 1) Deposit Money\n");
    printf("-> 2) Withdraw Money\n");
    printf("-> 3) Account Details\n");
    scanf("%d",&choice);

    if (choice == 3){
        AccountDetail(p1);
    }else if (choice == 2)
    {
        Withdraw(p1);
    }else if (choice == 1)
    {
        Deposit(p1);
    }
    
    
    
}

void AccountDetail(struct User user){
    printf("                      ============================  Account Deatil ============================  \n\n");
    printf("\nAccount Title : %s",user.name);
    printf("\n\nAccount created : %s",user.created);
    printf("\n\ncnic : %ld",user.cnic);
    printf("\n\nbalance : %d",user.balanace);
}

void Withdraw(struct User user){
    printf("\n\n\n");
    printf("                      ============================  withdrawal ============================  \n\n");

    int withdrawMoneyAmount = 0;
    printf("how much many you want to withdraw from this account %s = ",user.name);
    scanf("%d",&withdrawMoneyAmount);
    if (withdrawMoneyAmount > user.balanace){
        printf("Balance is low");
    }else{
        user.balanace = user.balanace - withdrawMoneyAmount;
        printf("\n\n\n\n\n\n");
        printf("                      ============================  Remainning Balance ============================  \n\n");
        printf("Remaining Balance  = %d",user.balanace);
    }    
}

void Deposit(struct User user){
     printf("\n\n\n");
    printf("                      ============================  Deposit ============================  \n\n");

    int depositMoneyAmount = 0;
    printf("how much you want to deposit in this account %s = ",user.name);
    scanf("%d",&depositMoneyAmount);

    user.balanace = user.balanace + depositMoneyAmount;
    printf("\n\n");
    printf("Now you Balance is %d", user.balanace);
}

void AskingDetailForCreateAccount(){
    printf("                      ============================ Account Creation ============================  \n\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
    char cond[5] = "no";
    printf("\nyou cnic : ");
    scanf("%ld",&newUser.cnic);
    if (p1.cnic == newUser.cnic)
    {
       printf('Account already exists');
    }else{
        printf("\nyou name : ");
        scanf("%s",&newUser.name);
        printf("\ntoday date 00-00-0000 : ");
        scanf("%s",&newUser.created);
        printf("\nInitial Deposit : ");
        scanf("%s",&newUser.balanace);
    }
}


int main(){
    int loginResult = login();

    if (loginResult)
    {
        AskingAccount();
    }else{
        printf("soorryyyyy");
    }
    

    

  



    return 0;
}