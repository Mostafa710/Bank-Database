#ifndef Bank_Database
#define Bank_Database
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client_t
{
    char name[50];
    char type[7];
    int id;
    double cash;
    struct client_t *next;
}client;

void new_client(client *head,client **head_adr);
void print_client(client *head,int id);
void edit_client(client *head,int id);
void delete_client(client *head,client **head_adr,int id);
void money_transaction(client *head,int source,int destination,double money);

#endif // Bank_Database
