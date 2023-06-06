#include<stdio.h>
int partition(int*, int, int);
void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(a, low, high);
        quicksort(a, low, pivot-1);
        quicksort(a, pivot+1, high);
    }
}
int partition(int a[], int low, int high)
{
    int i,j,pivot,temp;
    i = low-1;
    pivot = a[high];
    for(j = low; j<high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i++;
    temp = a[i];
    a[i] = a[high];
    a[high] = temp;
    return i;
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
    quicksort(a, 0, n-1);
    printf("Sorted array elements are: \n");
     for(int i=0; i<n; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}