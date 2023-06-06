#include<stdio.h>

void merge(int a[], int l, int m, int r)
{
     int length_left = m - l + 1;
     int length_right = r - m;

     int L[length_left], R[length_right];

     for(int i=0; i<length_left; i++)
     {
         L[i] = a[l + i];
     }
     for(int j=0; j<length_right; j++)
     {
         R[j] = a[m + 1 + j];
     }

     int i=0, j=0, k=l; // k= first element of merged subarray
     while(i<length_left && j<length_right)
     {
         if(L[i] < R[j])
         {
             a[k] = L[i];
             i++;
         }
         else
         {
             a[k] = R[j];
             j++;
         }
         k++;
     }

    while(i < length_left)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < length_right)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r)/2;
        mergesort(a, l, m);  //sorted left part
        mergesort(a, m+1, r); //sorted right part
        merge(a, l, m, r); //merged
    }
}

int main()
{
    int a[50], n;
    printf("Enter number of elements of array\n");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
     
    mergesort(a, 0, n-1);

    printf("Sorted array elements are: \n");
     for(int i=0; i<n; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}