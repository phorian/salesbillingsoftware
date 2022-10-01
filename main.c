#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>


struct items
{
    /* data */
    char itemName[20];
    float price;
    int qty;
};

struct orders
{
    /* data */
    char customerName[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};


int main() {

    int opt,n;
    struct orders ord;

    printf("===============X-Nova Tech===================");
    printf("\nPlease select your operation");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");
    printf("\n\nPlease Enter Your Choice: ");
    scanf("%d",&opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
        printf("\nPlease Enter name of customer: ");
        fgets(ord.customerName,50,stdin);
        ord.customerName[strlen(ord.customerName)- 1]=0;
        strcpy(ord.date, __DATE__);
        printf("Please enter the number of items:\t");
        scanf("%d",&n);
            
        /*
        This loop lets you iterate and input data over the numbers of item purchased
        */
        for (int i = 0; i < n; i++)
        {
            /* code */
            fgetc(stdin);
            printf("Please enter the item %d",i+1);
            fgets(ord.itm[i].itemName,20,stdin);
            ord.itm[i].itemName[strlen(ord.itm[i].itemName)-1]=0;
            printf("\nPlease enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("\nPlease enter the unit price: \t");
            scanf("%f", &ord.itm[i].price);
        }
        
        break;
    
    default:
        break;
    }


    printf("\n\n");


    return 0;
}
