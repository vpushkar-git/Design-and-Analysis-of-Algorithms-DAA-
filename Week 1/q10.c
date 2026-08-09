//ATM Transaction System 
//• Create a menu-driven program to check balance, deposit money, withdraw money, and exit. 
//• Prevent a withdrawal when the balance is insufficient. 
//• Maintain and display the last five transactions.
#include <stdio.h>

int main()
{
    int choice, i, count = 0;
    float balance = 10000, amount;
    char transaction[5][20];

    while(1)
    {
        printf("\n1. Check Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Show Transactions");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Balance = %.2f\n", balance);
        }

        else if(choice == 2)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            balance = balance + amount;

            if(count < 5)
            {
                sprintf(transaction[count], "Deposit %.2f", amount);
                count++;
            }

            printf("Deposit successful\n");
        }

        else if(choice == 3)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if(amount > balance)
            {
                printf("Insufficient balance\n");
            }
            else
            {
                balance = balance - amount;

                if(count < 5)
                {
                    sprintf(transaction[count], "Withdraw %.2f", amount);
                    count++;
                }

                printf("Withdrawal successful\n");
            }
        }

        else if(choice == 4)
        {
            printf("\nTransactions:\n");

            for(i = 0; i < count; i++)
            {
                printf("%s\n", transaction[i]);
            }
        }

        else if(choice == 5)
        {
            break;
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}