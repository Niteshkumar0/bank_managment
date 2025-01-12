
#include <stdio.h>
#include <string.h>

void mainFeatures();
void AskingAccount();
void AlreadyAccount();
void AccountDetail();

struct User
{
    char name[20];
    char created[40];
    int balanace;
    long cnic;
};

struct User p1;

//LOGIN PAGE
int login() {

    strcpy(p1.name,"nitesh");
    p1.cnic = 4510114534179;
    strcpy(p1.created,"1-1-25");
    p1.balanace =10000000;


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
    int account =0;
    printf("\n\n\n-> 1) you have account");
    printf("\n-> 2) you want to create \n\n");
    scanf("%d",&account);

    if (account == 1)
    {
        AlreadyAccount();
    }
}


//ALREADY ACCOUNT
void AlreadyAccount(){

    char search[5] = "yes";
    long initialCnic = 4510114534179;
    int alreadyPassword = 4545;
    long cnic = 0;
    int password = 0;

        printf("                      ============================ Search Account ============================  \n\n");
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
        mainFeatures();
    }
    
}

//MAIN FEATURES 
void mainFeatures() {
    int choice;
    printf("\n\nWhich Function do you want to Perform?\n\n");
    printf("-> 1) Deposit Money\n");
    printf("-> 2) Withdraw Money\n");
    printf("-> 3) Account Details\n");
    scanf("%d",&choice);

    if (choice == 3){
        AccountDetail();
    }
}

void AccountDetail(){
    printf("                      ============================  Account Deatil ============================  \n\n");
    printf("\nAccount Title : %s",p1.name);
    printf("\n\nAccount created : %s",p1.created);
    printf("\n\ncnic : %ld",p1.cnic);
    printf("\n\nbalance : %d",p1.balanace);
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