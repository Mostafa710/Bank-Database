#ifndef bank_D
#define bank_D
typedef struct
{
    char name[50];
    char type[7];
    int id;
    double cash;
}client_t;
void new_client(void);
void edit_client(int id);
void print_client(int id);
void delete_client(int id);
void money_transaction(int source_id,int destination_id,double money);
#endif
