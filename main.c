#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include <string.h>

struct items
{
    /* data */
    char itemName[50];
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

void generateBillHeader(char name[50], char date[30]){
    printf("\n\n");
    printf("\t     X-Nova Tech");
    printf("\n\t   --------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------");
    printf("\nItems\t\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n-----------------------------");
    printf("\n\n");
}

void generateBillBody(char itemName[20], int qty, float price){
    printf("%s\t\t\t", itemName);
    printf("%d\t\t\t", qty);
    printf("%.2f\t\t\t", qty * price);
    printf("\n");
}

void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1f*total;
    float netTotal = total-dis;
    float cgst = 0.09f*netTotal,grandTotal = netTotal + 2;
    printf("-------------------------------------------\t");
    printf("\nSub Total\t\t\t\t%.2f",total);
    printf("\nDiscount @10%\t\t\t%.2f",dis);
    printf("\n\t\t\t\t\t-----");
    printf("\nNet Total\t\t\t\t%.2f", netTotal);
    printf("\nCGST @9%\t\t\t\t\t%.2f", cgst);
    printf("\nSGST @9%\t\t\t\t\t%.2f", cgst); //
    printf("\n---------------------------------------------");
    printf("\nGrand Total\t\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------------");

}

int main() {

    int opt,n;
    struct orders ord;
    struct orders order;
    float total;
    char name[50];
    char saveBill = 'y',contFlag = 'y';
    FILE *fp;


    // initialize arrays to zero
    memset(ord.customerName, 0, sizeof ord.customerName);
    memset(ord.date, 0, sizeof ord.date);
    memset(name, 0, sizeof name);
    memset(order.customerName, 0, sizeof order.customerName);

    while(contFlag == 'y') {
    system("cls");
    float total= 0;
    int invoiceFound = 0;
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
        system("cls");
        printf("\nPlease Enter name of customer:\t");
        fgets(ord.customerName,50,stdin);
        ord.customerName[strlen(ord.customerName)- 1]=0;
        strcpy(ord.date, __DATE__);
        printf("Please enter the number of items:\t");
        scanf("%d",&n);
        ord.numOfItems = n;

        //to iterate over the number of items purchased
        for (int i = 0; i < n; i++)
        {
            /* code */
            fgetc(stdin);
            printf("Please enter the item %d: \t",i+1);

            // initilialize arrays in items to zero
            memset(ord.itm[i].itemName, 0, sizeof ord.itm[i].itemName);


            fgets(ord.itm[i].itemName,50,stdin);
            ord.itm[i].itemName[strlen(ord.itm[i].itemName)-1]=0;
            printf("\nPlease enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("\nPlease enter the unit price:\t");
            scanf("%f", &ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        generateBillHeader(ord.customerName, ord.date);
        for(int i = 0; i < ord.numOfItems;i++){
            generateBillBody(ord.itm[i].itemName,ord.itm[i].qty, ord.itm[i].price);
        }
        generateBillFooter(total);

        printf("\nDo you want to save this invoice [y/n]:\t");
        scanf("%s", &saveBill);

        if(saveBill == 'y' || saveBill == 'Y'){
            fp = fopen("NovaBil.txt","w+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(!fwrite == 0){
                printf("\nInvoice Saved");
            }
            else{
                printf("\nCouldn't save file");
            }
            fclose(fp);
        }

        break;

    case 2:
        system("cls");
        fp = fopen("NovaBil.txt","r+");
        if (fp == NULL){
            printf("No records!");
        }
        printf("\n  *********Your Previous Invoices*********\n");
        while(fread(&order, sizeof(struct orders),1,fp)){
            float tot = 0;
            generateBillHeader(ord.customerName,order.date);
            for(int i=0;i<order.numOfItems;i++){
                generateBillBody(order.itm[i].itemName,order.itm[i].qty,order.itm[i].price);
                tot += order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(tot);
        }
        fclose(fp);
        break;

    case 3:
        printf("\n Enter the name of the customer:\t");
        memset(name, 0, sizeof name);

        fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)- 1] = 0;
        system("cls");
        fp = fopen("NovaBil.txt","r");
        printf("\n  *********Invoice of %s*********\n", name);
        while(fread(&order, sizeof(struct orders),1,fp)){
            float tot = 0;
           if(!strcmp(order.customerName,name)){
            generateBillHeader(ord.customerName,order.date);
            for(int i=0;i<order.numOfItems;i++){
                generateBillBody(order.itm[i].itemName,order.itm[i].qty,order.itm[i].price);
                tot += order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(tot);
            invoiceFound = 1;
              }
             if (!invoiceFound)
                    {
            printf("Sorry the invoice for %s does not exist", name);
            }
            fclose(fp);
            break;

    case 4:
        printf("\n\t\t Bye, See you again");
        exit(0);
        break;

    default:
        printf("Sorry Invalid option");
        break;
    }
    printf("\nDo you want to perform another operation?[y/n]:");
    scanf("%s",&contFlag);
    }
    }

    printf("\n\t\t Bye, See you again");

    printf("\n\n");


    return 0;
}
