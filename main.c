#include <stdio.h>
//#include <stdlib.h>


typedef struct customer{

int accountNo;

char name[100];

int balance;

} Customer;

void accept(Customer list[100], int s){

int i;

for(i=0;i<s;i++){

    printf("\n Enter data for Record #%d: ", i+1);

    printf("\n Enter account number: ");

    scanf("%d", &list[i].accountNo);

    fflush(stdin);//clears the buffer to add the next string

    printf(" Enter name: ");

    gets(list[i].name);

    list[i].balance = 0;

    }
}

void display(Customer list[100], int s){

int i;

printf("\n\nA/c No\tName\tBalance\n");

for(i=0;i<s;i++){

    printf("%d\t%s\t%d\n",list[i].accountNo, list[i].name, list[i].balance);
    }

}

int search(Customer list[100], int s, int number){

int i;

for(i=0;i<s;i++){

    if(list[i].accountNo == number){

        return i;
        }
    }
        return -1;
}

void deposit(Customer list[], int s, int number, int amount){

int i = search(list , s, number);

if(i == -1){

    printf("Record not found.\n ");

}
else{

    list[i].balance += amount;
    }
}

void withdraw(Customer list[], int s, int number, int amount){

int i = search(list, s, number);

if(i == -1){

    printf("Record not found. \n");
    }

else if(list[i].balance < amount){

    printf("Insufficient balance \n");
    }

else{
    list[i].balance -= amount;
    }
}



int main(){

   Customer data[20];

   int n, choice, accountNo, amount, index;

   printf("\t\tBanking System: \n\n");

   printf("Number of customer records you want to enter: ");

   scanf("%d",&n);

   accept(data, n);

   do{
        printf("\nBanking System Menu :\n");

        printf("Press 1 to display all records.\n");

        printf("Press 2 to search a record.\n");

        printf("Press 3 to deposit a certain amount.\n");

        printf("Press 4 to enter the amount you wish to withdraw.\n");

        printf("Press 0 to exit\n");

        printf("\nEnter choice(0-4) : ");

        scanf("%d", &choice);

        switch(choice){

    case 1:

        display(data,n);

        break;

    case 2:

        printf("Enter account number to search: ");

        scanf("%d", &accountNo);

        index = search(data, n, accountNo);

        if(index == -1){

            printf("Record not found. ");
        }

        else{

            printf("A/c Number: %d\tName: %s\tBalance: %d\n",data[index].accountNo, data[index].name, data[index].balance);
        }

            break;
    case 3:

        printf("Enter account number: ");

        scanf("%d", &accountNo);

        printf("Enter amount to deposit: ");

        scanf("%d", &amount);

        deposit(data, n, accountNo, amount);

        break;

    case 4:

        printf("Enter account number : ");

        scanf("%d", &accountNo);

        printf("Enter amount to withdraw : ");

        scanf("%d", &amount);

        withdraw(data, n, accountNo, amount);

        }
   }while(choice != 0);

return 0;
}
