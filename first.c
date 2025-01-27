#include <stdio.h>
#include <string.h>

struct User {
    char name[20];
    char created[40];
    int balanace;
    long cnic;
    int password;
};

struct User p1;
struct User newUser;
struct User *currentUser = NULL; 

void mainFeatures();
void AskingAccount();
void AlreadyAccount();
void AccountDetail();
void Withdraw();
void Deposit();
void AskingDetailForCreateAccount();
void moneyTransfer();

// LOGIN PAGE
int login() {

    strcpy(p1.name, "nitesh");
    p1.cnic = 4510114534179;
    strcpy(p1.created, "1-1-25");
    p1.balanace = 10000000;
    p1.password = 4545;

    printf("\n\n\n");
    printf("                               ====== Bank Management System ==========            ");
    int username = 0;
    printf("\n\n\nEnter your username(123): ");
    scanf("%d", &username);

    int password = 0;
    printf("Enter your password(123): ");
    scanf("%d", &password);

    if (username == 123 && password == 123) {
        printf("Login Successful!\n\n");
        currentUser = &p1; 
        return 1;
    } else {
        printf("Invalid Username or Password");
        return 0;
    }
}

// ASKING ACCOUNT FROM USER
void AskingAccount() {
    printf("                                ============= Options =============            ");
    int account = 0;
    printf("\n\n\n-> 1) You have an account");
    printf("\n-> 2) You want to create one \n\n");
    scanf("%d", &account);

    if (account == 1) {
        AlreadyAccount();
    } else if (account == 2) {
        AskingDetailForCreateAccount();
    }
}

// ALREADY ACCOUNT
void AlreadyAccount() {
    char search[5] = "yes";
    long cnic = 0;
    int password = 0;

    printf("\n\n\n\n");
    printf("                      ============================  Information ============================  \n\n");
    printf("Enter CNIC: ");
    scanf("%ld", &cnic);
    printf("Enter password: ");
    scanf("%d", &password);

    while (p1.cnic != cnic || password != p1.password) {
        printf("\n\nIncorrect!");
        printf("\n\nDo you want to continue searching for an account (yes/no): ");
        scanf("%s", search);

        if (strcmp(search, "yes") == 0) {
            printf("Enter CNIC: ");
            scanf("%ld", &cnic);
            printf("Enter password: ");
            scanf("%d", &password);
        } else {
            return;
        }
    }

    if (p1.cnic == cnic && p1.password == password) {
        currentUser = &p1; 
        mainFeatures();
    }
}

// MAIN FEATURES
void mainFeatures() {
    int choice;
    printf("\n\nWhich function do you want to perform?\n\n");
    printf("-> 1) Deposit Money\n");
    printf("-> 2) Withdraw Money\n");
    printf("-> 3) Account Details\n");
    printf("-> 4) money transfer\n");
    printf("-> 5) Exit\n");
    scanf("%d", &choice);

    if (choice == 3) {
        AccountDetail();
    } else if (choice == 2) {
        Withdraw();
    } else if (choice == 1) {
        Deposit();
    }else if(choice == 5){
        printf("thank you for using our bank! ");
    }else if(choice == 4 ){        
        moneyTransfer();

    }else{
        printf("enter valid key");
        mainFeatures();
    }
}

// ACCOUNT DETAIL
void AccountDetail() {
    char choice[5];
    printf("                      ============================  Account Detail ============================  \n\n");
    printf("\nAccount Title : %s", currentUser->name);
    printf("\n\nAccount Created : %s", currentUser->created);
    printf("\n\nCNIC : %ld", currentUser->cnic);
    printf("\n\nBalance : %d", currentUser->balanace);

    printf("\n\nDo you want to continue.......(yes/no) : ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        mainFeatures();
    } else {
        // Feedback();
        printf("Thank you!!❤️");
    }
}

// WITHDRAW
void Withdraw() {
    char choice[5];
    printf("\n\n\n");
    printf("                      ============================  Withdrawal ============================  \n\n");

    int withdrawMoneyAmount = 0;
    printf("How much money you want to withdraw from this account %s = ", currentUser->name);
    scanf("%d", &withdrawMoneyAmount);

    if (withdrawMoneyAmount > currentUser->balanace) {
        printf("Balance is low");
    } else {
        currentUser->balanace -= withdrawMoneyAmount;
        printf("\n\nRemaining Balance = %d", currentUser->balanace);
    }

    printf("\n\nDo you want to continue.......(yes/no) : ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        mainFeatures();
    } else {
        printf("Thank you!!❤️");
    }
}

// DEPOSIT
void Deposit() {
    char choice[5];
    printf("\n\n\n");
    printf("                      ============================  Deposit ============================  \n\n");

    int depositMoneyAmount = 0;
    printf("How much you want to deposit in this account %s = ", currentUser->name);
    scanf("%d", &depositMoneyAmount);

    currentUser->balanace += depositMoneyAmount;
    printf("\n\nNow your Balance is %d\n\n", currentUser->balanace);

    printf("Do you want to continue.......(yes/no) : ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        mainFeatures();
    } else {
        printf("Thank you!!❤️");
    }
}

void moneyTransfer(){
    long cnic;
    int money;
    char choice[5];
    printf("tell account cnic in which you want to transfer : ");
    scanf("%ld",&cnic);

    if (currentUser->cnic == p1.cnic){
        printf("try again!");
        mainFeatures();
    }else if(currentUser->cnic == cnic){
        printf("try again!");
        mainFeatures();
    }else
    {
        if (cnic == p1.cnic)
        {
            printf("how much do you wish to transfer : ");
            scanf("%d",&money);
            p1.balanace += money;
            currentUser->balanace-=money;
            printf("now your balance is %d",currentUser->balanace);

            printf("\n\ndo you wish to continue...(yes/no)");
            scanf("%s",choice);

            if (strcmp(choice,"yes")==0)
            {
                mainFeatures();
            }else{
                printf("thannk you!! ❤️");
            }
        }
    }
}

// CREATE NEW ACCOUNT
void AskingDetailForCreateAccount() {
    printf("                      ============================ Account Creation ============================  \n\n");
    char choice[5];
    char mainChoice[5];
    printf("\nYour CNIC: ");
    scanf("%ld", &newUser.cnic);

    if (p1.cnic == newUser.cnic) {
        printf("Account already exists");
        printf("\n\nDo you want to continue.......(yes/no) : ");
        scanf("%s", choice);

        if (strcmp(choice, "yes") == 0) {
            AskingAccount();
        } else {
            printf("Thank you!!❤️");
        }
    } else {
        printf("\nYour Name: ");
        scanf("%s", newUser.name);
        printf("\nToday's Date (00-00-0000): ");
        scanf("%s", newUser.created);
        printf("\nInitial Deposit: ");
        scanf("%d", &newUser.balanace);

        currentUser = &newUser; 
        printf("do you want to continue (yes/no) : ");
        scanf("%s",mainChoice);
        if (strcmp(mainChoice, "yes") == 0)
        {
            mainFeatures();
        }else{
            printf("thank you!😊");
        }
    }
}


int main() {
    int loginResult = login();

    if (loginResult) {
        AskingAccount();
    } else {
        printf("Sorry!");
    }

    return 0;
}
