#include <stdio.h>
#include <stdlib.h>
#include "bank database.h"

int counter;
client_t client[3];

int main()
{
    char choice;
    int id_check;
    int id_from;
    int id_to;
    double money;
    while(1)
    {
        printf("Please select one of the following options:\n\n");
        printf("1-Create a new client                    -> press 1\n");
        printf("2-Print client data                      -> press 2\n");
        printf("3-Edit client                            -> press 3\n");
        printf("4-Delete client                          -> press 4\n");
        printf("5-Cash transfer from a client to another -> press 5\n");
        printf("6-Exit                                   -> press 6\n\n");
        printf("Please enter your choice: ");
        fflush(stdin);
        scanf("%c",&choice);
        printf("\n");
        if(choice=='1')
        {
            new_client();
        }
        else if(choice=='2')
        {
            printf("Enter the client id: ");
            scanf("%i",&id_check);
            print_client(id_check);
        }
        else if(choice=='3')
        {
            printf("Enter the client id: ");
            scanf("%i",&id_check);
            edit_client(id_check);
        }
        else if(choice=='4')
        {
            printf("Enter the client id: ");
            scanf("%i",&id_check);
            delete_client(id_check);
        }
        else if(choice=='5')
        {
            printf("Enter the client id that money will transfer from his account: ");
            scanf("%i",&id_from);
            printf("Enter the client id that money will transfer to his account: ");
            scanf("%i",&id_to);
            printf("Enter the cash: ");
            scanf("%lf",&money);
            money_transaction(id_from,id_to,money);
        }
        else if(choice=='6')
        {
            break;
        }
        else
        {
            printf("Wrong choice\n\n");
        }
    }
    return 0;
}
