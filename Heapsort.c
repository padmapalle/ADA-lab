/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int a[],int n,int i)
{
    int largest=i,l=2*i,r=2*i+1;
    while(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    while (r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
    
}
void print(int a[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void heapsort(int a[],int n)
{
    int i;
    //create max heap
    for(i=n/2;i>=1;i--)
    {
        heapify(a,n,i);
    }

    //sort using deletion
    for(i=n;i>=1;i--)
    {
        swap(&a[1],&a[i]);
        heapify(a,i,1);
    }
}

void main()
{
    int a[20],n,i,j;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("\nAfter sorting elements are\n");
    print(a,n);

}