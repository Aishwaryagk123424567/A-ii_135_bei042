#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int a[],int n,FILE *fp1);
int main()
{
    float duration;
    FILE *fp1;
    fp1=fopen("num1.txt","r");
    clock_t start,end;
    int lo,up,n,i,num[100];
    srand(time(0));
    printf("enter no\n");
    fscanf(fp1,"%d",&n);
     printf("enter lo\n");
    fscanf(fp1,"%d",&lo);
     printf("enter up\n");
    fscanf(fp1,"%d",&up);
    for(i=0;i<n;i++)

    {
       num[i]=(rand()%(up-lo+1))+lo;
        printf("%d ",num[i]);
    }
    printf("\n");
    start=clock();
    selectionsort(num,n,fp1);
       end=clock();
    duration=(float)(end-start)/ CLOCKS_PER_SEC;
     printf("after selection sort\n");
      for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("Time taken: %f seconds\n", duration);
    return 0;
}
void selectionsort(int a[],int n,FILE *fp1)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
       {
           if(a[j]<a[min])
           {
               min=j;
           }

       }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}
