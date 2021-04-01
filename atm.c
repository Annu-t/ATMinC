#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main(){
    
    int pin=2345, option, enteredPin,count=0,amount=1;
    float balance = 5000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t        %s",ctime(&now));
    printf("\n\t\t\t---------------------Welcome to SBD Bank!------------------");

    while(pin != enteredPin){
        printf("\n\t\t\t\t\t\t Please enter your pin\n");
        scanf("%d", &enteredPin);
        if(enteredPin != pin){
            Beep(610,500);
            printf("Invalid pin!\n Try Again!");
        }
        count++;
        if(count ==3 && pin != enteredPin) {
            exit(0);
        }
        
    }
    while(continueTransaction != 0){
        printf("\n\t\t\t<----------Available Transactions-------------->");
        printf("\n\n\t\t\t\t\t1.Withdrawl");
        printf("\n\n\t\t\t\t\t 2.Deposit");
        printf("\n\n\t\t\t\t\t 3.Check Balance");
        printf("\n\n\t\t\t\t\t Please select an option");
        scanf("%d", &option);
        switch(option){
            case 1: printf("Withdraw your amount\n");
                 while(amount % 500 !=0){
                     printf("Enter the amount\n");
                     scanf("%d",&amount);
                     if(amount %500 !=0)
                     printf("\n the amount should be multiple of 500\n");

                 }
                 if(balance < amount){
                     printf("\n Insufficient balance\n");
                     amount =1;
                     break;
                 }
                 else {
                     balance -= amount;
                     printf("\n\t\tYou have withdrawn  Rs.%d. Your new balance is %.2f", amount, balance);
                      printf("\n\t\t\t\tThank you for banking with us\n");
                     amount =1;
                     break;
                 }
            case 2: printf("Deposit your money");
                    printf("\n\t\t Please enter the amount");
                    scanf("%d",&amount);
                    balance +=amount;
                    
                    printf("\n\t\t You have deposited Rs.%d. Your new balance is %.2f ",amount, balance);
                    printf("\n\t\t\t\tThank you for banking with us");
                    amount=1;

                    break;
            case 3: printf("Check your balance");
                   printf("Your balance is Rs. %.2f ",balance);
                   break;
            default : 
            Beep(610,500);
                printf("Invalid Option");



        }
        printf("\n\t\t Do you wish to perform another transaction ?Press 1[Yes], 0[N0]");
        scanf("%d",&continueTransaction);
    }

        
    






  return 0;
}