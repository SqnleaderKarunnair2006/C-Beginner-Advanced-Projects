#include <stdio.h>

struct ATM {
    long long ACN;  // Account Number
    int balance;    // Account Balance
};

// Function to deposit money
void Depositmoney(struct ATM *a) {  // Pass struct ATM as a pointer
    int dm;  // Variable to store deposit amount
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &dm);

    a->balance += dm;  // Update the balance
    printf("Your current account balance is: %d\n", a->balance);
}

// Function to withdraw money
void Withdrawmoney(struct ATM *a) {
    if (a->balance == 0) {  // Check if balance is zero
        printf("Sorry, this account has no money. Please deposit and try again!\n");
    } else {
        int wm;
        printf("Enter the amount you want to withdraw: ");
        scanf("%d", &wm);

        if (wm > a->balance) {
            printf("Insufficient funds!\n");
        } else {
            a->balance -= wm;  // Deduct the withdrawn amount from balance
            printf("You withdrew: %d\n", wm);
            printf("Your account balance is: %d\n", a->balance);
        }
    }
}

int main() {
    printf("\n Welcome to mini ATM system \n");
    struct ATM a;       // Create an instance of ATM
    int x = 100000;     // Example initial balance

    // Input the account number
    printf("Enter your 10-digit Account number: ");
    scanf("%lld", &a.ACN);

    // Check if the account number is zero
    if (a.ACN == 0) {
        printf("Invalid! Please try again. Account number cannot be zero.\n");
        return 1;  // Exit the program with an error
    }

    // Assign the initial balance
    a.balance = x;

    // Display account details
    printf("Your Account Number is: %lld\n", a.ACN);
    printf("Your Current Balance is: %d\n", a.balance);

    // Menu for actions
    int option;
    printf("Select 1 to Deposit money\nSelect 2 to Withdraw money\n");
    scanf("%d", &option);

    if (option == 1) {
        Depositmoney(&a);  // Call the function, pass struct by reference
    } else if (option == 2) {
        Withdrawmoney(&a);  // Call the function for withdrawal
    } else {
        printf("Invalid option selected.\n");
    }

    return 0;
}

