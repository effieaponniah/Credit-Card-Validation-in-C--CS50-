// This program will give determine the type of card a user has input 
// This program is written by Effiea on August 20th (12:57a.m)

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_checksum(long ccn);
int get_length(long ccn);
void get_cardtype(int length, long ccn, int checksum);

// This is the main class to execute the code
int main(void)
{
    long ccn = get_long("Number: ");
    int checksum = get_checksum(ccn);
    int length = get_length(ccn);
    get_cardtype(length, ccn, checksum);

}

// Calculate the check some using Luhn’s Algorithm
int get_checksum(long ccn)
{
    int sum = 0;
    int evendigit;

    for (int len = 0; ccn != 0; len++)
    {
        if (len % 2 == 0)
        {
            sum += ccn % 10;

        }
        else
        {
            evendigit = 2 * (ccn % 10);
            sum += (evendigit / 10) + (evendigit % 10);
        }
        ccn /= 10;
    }
    return sum;
}

// Get the length of the credit card number
int get_length(long ccn)
{
    int ccnlen = 0;
    while (ccn != 0)
    {
        ccn /= 10;
        ccnlen++;
    }
    return ccnlen;
}

// Output the type of credit card the user has input 
void get_cardtype(int length, long ccn, int checksum)
{
    int startdig; 
    int visastartdig; 
    
    // Check whether it is a the last digit of checksum is 0 and whether the length is that of a valid card
    if ((checksum % 10 == 0) && (length == 15 || length == 16 || length == 13))
    {
        startdig = (ccn) / pow(10, length - 2); 
        visastartdig = (ccn) / pow(10, length - 1); 
        
        // Conditions to determine AMEX, MASTERCARD, VISA and INVALID
        if (length == 15 && (startdig == 34 || startdig == 37))
        {
            printf("AMEX\n"); 
        }
        else if (length == 16 && (startdig >= 51 && startdig <= 55))
        {
            printf("MASTERCARD\n");         
        }
        else if (visastartdig == 4 && (length == 16 || length == 13)) 
        {
            printf("VISA\n");               
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
