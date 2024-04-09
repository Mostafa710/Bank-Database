#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank database.h"
extern int counter;
extern client_t client[3];

void new_client(void)
{
    if(counter==(sizeof(client)/sizeof(client_t)))
        printf("The database is full. You can not create any clients!\n");
    else
    {
        printf("Please enter the name of the client number %i: ",counter+1);
        fflush(stdin);
        gets(client[counter].name);
        printf("Please enter the cash of the client number %i: ",counter+1);
        scanf("%lf",&client[counter].cash);
        printf("Please enter the type of the client number %i <Debit or Credit>: ",counter+1);
        fflush(stdin);
        gets(client[counter].type);
        printf("Please enter the id of the client number %i: ",counter+1);
        scanf("%i",&client[counter].id);
        counter++;
        printf("\n");
    }
}

void print_client(int id)
{
    int i;
    for(i=0;i<counter;i++)
    {
        if(client[i].id==id)
            break;
    }
    if(i==counter)
    {
        printf("\nThis id does not exist\n\n");
    }
    else
    {
        printf("\nThe name of client number %i: %s\n",i+1,client[i].name);
        printf("The cash of client number %i: %0.2lf\n",i+1,client[i].cash);
        printf("The type of client number %i: %s\n",i+1,client[i].type);
        printf("The id   of client number %i: %i\n\n",i+1,client[i].id);
    }
}

void edit_client(int id)
{
    int i;
    for(i=0;i<counter;i++)
    {
        if(client[i].id==id)
            break;
    }
    if(i==counter)
    {
        printf("\nThis id does not exist\n\n");
    }
    else
    {
        printf("Please enter the name of the client number %i: ",i+1);
        fflush(stdin);
        gets(client[i].name);
        printf("Please enter the cash of the client number %i: ",i+1);
        scanf("%lf",&client[i].cash);
        printf("Please enter the type of the client number %i <Debit or Credit>: ",i+1);
        fflush(stdin);
        gets(client[i].type);
        printf("Please enter the id of the client number %i: ",i+1);
        scanf("%i",&client[i].id);
        printf("\n");
    }
}

void delete_client(int id)
{
    int i;
    for(i=0;i<counter;i++)
    {
        if(client[i].id==id)
            break;
    }
    if(i==counter)
    {
        printf("\nThis id does not exist\n\n");
    }
    else
    {
        while(i<counter-1)
        {
           client[i] = client[i+1];
           i++;
        }
        counter--;
        printf("\n");
    }
}

void money_transaction(int source_id,int destination_id,double money)
{
    int i,source,destination;
    for(i=0;i<counter;i++)
    {
        if(client[i].id==source_id)
            break;
    }
    if(i==counter)
    {
        printf("\nThe source id does not exist\n\n");
    }
    else
    {
        source=i;
        for(i=0;i<counter;i++)
        {
            if(client[i].id==destination_id)
                break;
        }
        if(i==counter)
        {
            printf("\nThe destination id does not exist\n\n");
        }
        else
        {
            destination=i;
            if(money>(client[source].cash))
            {
                while(1)
                    {
                        printf("\nThe money transfered is greater than your cash.\n");
                        printf("Enter the cash again and take care: ");
                        scanf("%lf",&money);
                        if(money<=(client[source].cash))
                            break;
                    }
            }
            client[destination].cash+=money;
            client[source].cash-=money;
            printf("\nMoney transfer is done.\n\n");
        }
    }
}
