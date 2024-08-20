#include<stdio.h>
#include<string.h>

int PalindromeTest(char str[])
{
    int low = 0;
    int high = strlen(str) - 1;

    while(low < high)
    {
        if(str[low] != str[high])
        {
            printf("The string '%s' is not a palindrome string.\n", str);
            break;
        } 
        else 
        {
            printf("The string '%s' is a palindrome string.\n", str);
            break;
        }
        low ++;
        high --;
    }
    
}

int main()
{
    char str[100];
    char contn;

    do {
        printf("\nEnter the string to test: ");
        scanf("%s", str);

        printf("The string inputted is: %s\n", str);
        PalindromeTest(str);

        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &contn);
    }
    while(contn == 'Y' || contn == 'y');
  
    return 0;
}