#include "Bank Database.h"

int counter;

void new_client(client *head,client **head_adr)
{
    client *temp;
    counter++;
    temp = (client*)malloc(sizeof(client));
    printf("Please enter the name of the client number %i: ",counter);
    fflush(stdin);
    gets(temp->name);
    printf("Please enter the cash of the client number %i: ",counter);
    scanf("%lf",&(temp->cash));
    printf("Please enter the type of the client number %i <Debit or Credit>: ",counter);
    fflush(stdin);
    gets(temp->type);
    printf("Please enter the id of the client number %i: ",counter);
    scanf("%i",&(temp->id));
    printf("\n");
    temp->next = 0;
    if(head == 0)
    {
        *head_adr = temp;
    }
    else
    {
        while(head->next != 0)
        {
            head = head->next;
        }
        head->next = temp;
    }
}
void print_client(client *head,int id)
{
    int i;
    for(i=0;i<counter;i++)
    {
        if(head->id == id)
        {
            break;
        }
        head = head->next;
    }
    if(i == counter)
    {
        printf("\nThis id does not exist\n\n");
    }
    else
    {
        printf("\nThe name of client number %i: %s\n",i+1,head->name);
        printf("The cash of client number %i: %0.2lf\n",i+1,head->cash);
        printf("The type of client number %i: %s\n",i+1,head->type);
        printf("The id   of client number %i: %i\n\n",i+1,head->id);
    }
}
void edit_client(client *head,int id)
{
    int i;
    for(i=0;i<counter;i++)
    {
        if(head->id == id)
        {
            break;
        }
        head = head->next;
    }
    if(i == counter)
    {
        printf("\nThis id does not exist\n\n");
    }
    else
    {
        printf("Please enter the name of the client number %i: ",i+1);
        fflush(stdin);
        gets(head->name);
        printf("Please enter the cash of the client number %i: ",i+1);
        scanf("%lf",&(head->cash));
        printf("Please enter the type of the client number %i <Debit or Credit>: ",i+1);
        fflush(stdin);
        gets(head->type);
        printf("Please enter the id of the client number %i: ",i+1);
        scanf("%i",&(head->id));
    }
}
void delete_client(client *head,client **head_adr,int id)
{
    int i;
    client *temp;
    if(head->id == id)
    {
        temp = head;
        head = head->next;
        *head_adr = head;
        free(temp);
        counter--;
    }
    else
    {
        for(i=0;i<counter-1;i++)
        {
            if(head->next->id == id)
            {
                break;
            }
            head = head->next;
        }
        if(i == counter-1)
        {
            printf("\nThis id does not exist\n\n");
        }
        else
        {
            temp = head->next;
            head->next = head->next->next;
            free(temp);
            counter--;
        }
    }
}
void money_transaction(client *head,int source,int destination,double money)
{
    int i;
    client *head_source,*head_destination;
    head_source = head_destination = head;
    for(i=0;i<counter;i++)
    {
        if(head_source->id == source)
        {
            break;
        }
        head_source = head_source->next;
    }
    if(i == counter)
    {
        printf("\nThe source id does not exist\n\n");
    }
    else
    {
        for(i=0;i<counter;i++)
        {
            if(head_destination->id == destination)
            {
                break;
            }
            head_destination = head_destination->next;
        }
        if(i == counter)
        {
            printf("\nThe destination id does not exist\n\n");
        }
        else
        {
            if(money > head_source->cash)
            {
                while(1)
                {
                    printf("\nThe money transfered is greater than your cash.\n");
                    printf("Enter the cash again and take care: ");
                    scanf("%lf",&money);
                    if(money <= head_source->cash)
                        break;
                }
            }
            head_source->cash-=money;
            head_destination->cash+=money;
            printf("\nMoney transfer is done.\n\n");
        }
    }
}
