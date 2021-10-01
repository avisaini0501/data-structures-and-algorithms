//fnding pair with sum k (a + b = k)
//condition = no duplicates should be present
#include<stdio.h>
#include<stdlib.h>

//using hash table for unsorted array
void pair_sum();

//for sort array
void sort_pair_sum();

int main()
{
    pair_sum();
    sort_pair_sum();
    return(0);
}

//for unsorted array
void pair_sum()
{
    int arr[10] = {6,3,8,10,16,7,5,2,9,14};
    int h[17] = {0};
    int i , n = 10 , k = 10;

    for(i = 0; i < n; i++)
    {
        if(h[k - arr[i]] != 0)
        {
            printf("%d + %d = %d\n",arr[i],k - arr[i], k);
        }
        
        h[arr[i]]++;

    }
}


//now for sort array
void sort_pair_sum()
{
    int arr[10] = {1,3,4,5,6,8,9,10,12,14};
    int i , j , n  = 10 , k = 10;
    
    i = 0;
    j = n - 1;

    while (i < j)
    {
        if(arr[i] + arr[j] == k)
        {
            printf("%d + %d = %d\n",arr[i],arr[j],k);
            i++;
            j--;
        }

        else if(arr[i] + arr[j] < k)
        i++;

        else
        j--;
    }
    
    

}