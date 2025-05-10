#include <stdio.h>

// Declare a global float variable for the bank balance
float balance = 1000.0; // Represents user's bank account balance

// Function declarations
int authenticate(int pin);
float requestAmount();
void deposit();
void withdraw(float amount);
void transfer();

// Function to authenticate user PIN
int authenticate(int pin) {
    const int correct_pin = 1234;
    return pin == correct_pin;
}

// Function to request amount for transaction
float requestAmount() {
    float amount;
    printf("Enter the amount: ");
    scanf("%f", &amount);
    return amount;
}

// Function to deposit money into account
void deposit() {
    float amount = requestAmount();
    balance += amount;
    printf("Deposit successful. New balance: %.2f\n", balance);
}

// Function to withdraw money from account
void withdraw(float amount) {
    if (amount > balance) {
        printf("Insufficient funds!\n");
    } else {
        balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", balance);
    }
}

// Function to transfer money to another account
void transfer() {
    int recipient;
    printf("Enter recipient's account number: ");
    scanf("%d", &recipient);
    float amount = requestAmount();
    if (amount > balance) {
        printf("Insufficient funds for transfer!\n");
    } else {
        balance -= amount;
        printf("Transfer successful to account %d. New balance: %.2f\n", recipient, balance);
    }
}

int main() {
    start:
    printf("WELCOME TO JD BANK\nEnter your four-digit PIN\n");
    int tries = 0;
    int pin = 0;
    scanf("%d", &pin);

    menu:
    if (authenticate(pin) && tries < 4) {
        int menu_item;
        printf("Select an option\n1. Check Balance\n2. Withdrawal\n3. Deposit\n4. Transfer\n");
        scanf("%d", &menu_item);

        switch (menu_item) {
            case 1:
                printf("Current balance: %g\n", balance);
                break;
            case 2:
                withdraw(requestAmount());
                break;
            case 3:
                deposit();
                break;
            case 4:
                transfer();
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } else {
        ++tries;
        printf("Invalid PIN after %d tries\n", tries);
        goto start;
    }

    // Ask user if they want another transaction
    int response;
    printf("Would you like to perform another transaction?\n1. Yes\n2. No\n");
    scanf("%d", &response);
    if (response == 1) {
        goto menu;
    }

    printf("Thank you for banking with us\n");
    return 0;
}
