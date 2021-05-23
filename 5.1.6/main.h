typedef struct service
{
    int serviceTime;
    int number;
    struct service* next;
    struct service* prev;
} Service;

void BSrt(Service* serv);

void AddService(Service* serv, int number);

int Result(Service* serv, int maxSum);