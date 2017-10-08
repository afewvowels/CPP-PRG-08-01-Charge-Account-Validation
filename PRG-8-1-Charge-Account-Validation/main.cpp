//
//  main.cpp
//  PRG-8-1-Charge-Account-Validation
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that lets the user enter a charge account number. The program should
//  determine if the number is valid by checking for it in the following list:
//
//  5658845     4520125     7895122     8777541     8451277     1302850
//  8080152     4562555     5552012     5050552     7825877     1250255
//  1005231     6545231     3852085     7576651     7881200     4581002
//
//  The list of numbers above should be initialized in a single-dimensional array. A simple
//  linear search should be used to locate the number entered by the user. If the user enters
//  a number that is in the array, the program should display a message saying the number
//  is valid. If the user enters a number that is not in the array, the program should display
//  a message indicating that the number is invalid.

#include <iostream>

using namespace std;

const int INT_ARRAY_SIZE = 18;

int getAccountNumber();
int linearSearch(const int[], int, int);

int main()
{
    int int_Result;
    int int_Customer_Account_Number;
    int int_Account_Number_Array[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                                      8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                                      1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    
    
    int_Customer_Account_Number = getAccountNumber();
    
    int_Result = linearSearch(int_Account_Number_Array, INT_ARRAY_SIZE, int_Customer_Account_Number);
    
    if(int_Result == int_Customer_Account_Number)
    {
        cout << "You have entered a correct number.\n";
    }
    else if(int_Result != int_Customer_Account_Number)
    {
        cout << "That number was not found.\n";
    }
    else
    {
        cout << "ERROR CHECKING ACCOUNT NUMBER" << endl;
    }
    
    return 0;
}

int getAccountNumber()
{
    int intCustomerAN;
    
    cout << "Please enter your 7-digit account number: ";
    cin >> intCustomerAN;
    while(!intCustomerAN || intCustomerAN < 1000000 || intCustomerAN > 9999999)
    {
        cout << "Please enter a valid 7-digit number: ";
        cin.clear();
        cin.ignore();
        cin >> intCustomerAN;
    }
    
    return intCustomerAN;
}

int linearSearch(const int intArray[], int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        if(intArray[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return intArray[position];
}

