#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of the array\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for ( int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++){
            if(a[j]>a[j+1]){
                int t  = a[j];
                a[j]  = a[j+1];
                a[j+1] = t;
            }
        }
    }
    printf("\nAfter sorting the array\n");
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    

    return 0;
}
