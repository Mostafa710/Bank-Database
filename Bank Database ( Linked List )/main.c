#include "Bank Database.h"

int main()
{
    client *head=0;
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
        switch(choice)
        {
        case '1':
            new_client(head,&head);
            break;
        case '2':
            printf("Enter the client id: ");
            scanf("%i",&id_check);
            print_client(head,id_check);
            break;
        case '3':
            printf("Enter the client id: ");
            scanf("%i",&id_check);
            edit_client(head,id_check);
            break;
        case '4':
            printf("Enter the client id: ");
            scanf("%i",&id_check);
            delete_client(head,&head,id_check);
            break;
        case '5':
            printf("Enter the client id that money will transfer from his account: ");
            scanf("%i",&id_from);
            printf("Enter the client id that money will transfer to his account: ");
            scanf("%i",&id_to);
            printf("Enter the cash: ");
            scanf("%lf",&money);
            money_transaction(head,id_from,id_to,money);
            break;
        case '6':
            exit(0);
            break;
        default:
            printf("Wrong choice\n\n");
        }
    }
    return 0;
}
