#include <stdio.h>

int calculateTotal(int *arr, int size);
int deposit(int balance, int amount);
int withdraw(int balance, int amount);
int processTransaction(int balance, int amount, int (*operation)(int, int));
int main(void)
{
 
 printf("TASK 1: Basic Pointers");
 int balance[5] = {15000, 25000, 18000, 32000, 12000};
 int *ptr = balance; 
 int selected = 2; 
 ptr = &balance[selected]; 
 printf("Customer %d balance : %d\n", selected + 1, *ptr);
 printf("Memory address : %p\n", (void *)ptr);
 *ptr = *ptr + 2000; 
 printf("Updated balance : %d\n", balance[selected]);
 printf("\nAll customers (pointer arithmetic):\n");
 ptr = balance;
 for (int i = 0; i < 5; i++)
 printf("Customer %d -> %d (address: %p)\n", i + 1, *(ptr + i), (void *)(ptr + i));
 
 //TASK 2: Pointer to a 2D Array

 printf("TASK 2: Pointer to 2D Array ");
 int transactions[2][3] = {{120000, 150000, 180000},
 {200000, 170000, 220000}};
 int (*rowPtr)[3] = transactions; 
 for (int i = 0; i < 2; i++)
 {
 int rowTotal = 0;
 printf("Branch %d (row address: %p)\n", i + 1, (void *)(rowPtr + i));
 for (int j = 0; j < 3; j++)
 {
 printf(" Month %d: %d\n", j + 1, *(*(rowPtr + i) + j));
 rowTotal += *(*(rowPtr + i) + j);
 }
 printf(" Total transactions: %d\n", rowTotal);
 }
 
 //TASK 3: Array of Pointers
 
 printf("TASK 3: Array of Pointers");
 int branch1[3] = {15000, 23000, 32000};
 int branch2[4] = {12000, 21000, 27000, 35000};
 int *branches[2] = {branch1, branch2}; 
 int sizes[2] = {3, 4};
 for (int i = 0; i < 2; i++)
 {
 int total = 0;
 printf("Branch %d:\n", i + 1);
 for (int j = 0; j < sizes[i]; j++)
 {
 printf(" Customer %d: %d (address: %p)\n",
 j + 1, *(branches[i] + j), (void *)(branches[i] + j));
 total += *(branches[i] + j);
 }
 printf(" Total balance: %d\n", total);
 }
 
 //TASK 4: Passing an Array to a Function
 
 printf("TASK 4: calculateTotal()");
 printf("Branch 1 total balance: %d\n", calculateTotal(branch1, 3));
 printf("Branch 2 total balance: %d\n", calculateTotal(branch2, 4));
 
 TASK 5: Function Pointers
 
 printf("TASK 5: Function Pointers");
 int (*op)(int, int); 
 int current = 15000;
 op = deposit;
 printf("Deposit 5000 -> new balance: %d\n", op(current, 5000));
 op = withdraw;
 printf("Withdraw 3000 -> new balance: %d\n", op(current, 3000));
 
 //TASK 6: Passing Function Pointers as Arguments
 
 printf("TASK 6: processTransaction()");
 printf("processTransaction (deposit 4000) : %d\n",
 processTransaction(current, 4000, deposit));
 printf("processTransaction (withdraw 2500) : %d\n",
 processTransaction(current, 2500, withdraw));
 return 0;
}

//Task 4: receives an array through a pointer and its size 
int calculateTotal(int *arr, int size)
{
 int total = 0;
 for (int i = 0; i < size; i++)
 total += *(arr + i); 
 return total;
}

//Task 5: 

int deposit(int balance, int amount)
{
 return balance + amount;
}
int withdraw(int balance, int amount)
 if (amount > balance)
 {
 printf(" [Insufficient balance]\n");
 return balance;
 }
 return balance - amount;
}

//Task 6:

int processTransaction(int balance, int amount, int (*operation)(int, int))
{
 return operation(balance, amount);
}
