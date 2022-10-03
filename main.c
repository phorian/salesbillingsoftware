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
void generateBillHeader;
void generateBillBody;
void generateBillFooter;



void generateBillHeader(char name[50], char date[30]){
    printf("\n\n");
    printf("\t     X-Nova Tech");
    printf("\n\t   --------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n-----------------------------");
    printf("\n\n");
}

void generateBillBody(char itemName[20], int qty, float price){
    printf("%s\t\t", itemName);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal = total-dis;
    float cgst = 0.09*netTotal,grandTotal = netTotal + 2;
    printf("-------------------------------------------\t");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%"dis);
    printf("\n\t\t\t\t--------");
    printf("Net Total\t\t\t\t%.2f", netTotal);
    printf("CGST @9%S\t\t\t\t%.2f", cgst);
    printf("SGST @9%s\t\t\t\t%.2f", cgst);
    printf("\n---------------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------------");

}

int main() {

    int opt,n;
    struct orders ord;
    float total;

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
        printf("\nPlease Enter name of customer:\t");
        fgets(ord.customerName,50,stdin);
        ord.customerName[strlen(ord.customerName)- 1]=0;
        strcpy(ord.date, __DATE__);
        printf("Please enter the number of items:\t");
        scanf("%d",&n);
<<<<<<< HEAD
        ord.numOfItems = n;

        //to iterate over the number of items purchased
=======
            
        /*
        This loop lets you iterate and input data over the numbers of item purchased
        */
>>>>>>> refs/remotes/origin/master
        for (int i = 0; i < n; i++)
        {
            /* code */
            fgetc(stdin);
            printf("Please enter the item %d: \t",i+1);
            fgets(ord.itm[i].itemName,20,stdin);
            ord.itm[i].itemName[strlen(ord.itm[i].itemName)-1]=0;
            printf("\nPlease enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("\nPlease enter the unit price:\t");
            scanf("%f", &ord.itm[i].price);
            total += ord.tm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.customerName, ord.date);
        for(int i = 0; i < ord.numOfItems;i++){
            generateBillBody(ord.itm[i].itemName,ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);
        
        break;
    
    default:
        break;
    }


    printf("\n\n");


    return 0;
}
