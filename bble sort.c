#include<stdio.h>
#include<stdlib.h>
int sort(int num[20],int n)
{
    int i,j,a;
    for(i=0;i<n-1;i++)
    {

        for(j=0;j<n-i-1;j++)
        {
            if(num[j]>num[j+1])
            {
                a=num[j];
                num[j]=num[j+1];
                num[j+1]=a;
            }
        }
    }
    return num[i];
}
int main()
{
    FILE*fp;
    FILE*fp2;
    int num[20];
    int n;
    int i;
    fp=fopen("text2.txt","r");
    fp2=fopen("text.txt","w");
    scanf("%d",&n);
    if(fp==NULL)
    {
        printf("File does not exit\n");
        exit(0);
    }
    else
    {
       for(i=0;i<n;i++)
       {
           fscanf(fp,"%d",&num[i]);
       }
       sort(num,n);
       for(i=0;i<n;i++)
       {
           printf("%d\t",num[i]);
           fprintf(fp2,"%d",num[i]);
       }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}

