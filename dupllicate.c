#include<stdio.h>

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 4, 5};
    int val = 10;
    int count = 0;
    
    for(int j = 0; j < n; j++)
    {
        val = a[j];
        for(int i = 0; i < n; i++)
        {
            if(val == a[i])
            {
                count ++;
            }
            printf("Value %d Count %d", val, count);
            count = 0;
        }
    }