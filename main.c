#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GenArrayList.h"

/*
 * This is a complex test of the Generic Array List
 * We will have a simple CRUD in memory to see if it
 * will work.
 *
 * In this test we will create a structure to hold ID,
 * Name, Address and Phone #.
 *
 * Then a menu to Add, Find, Remove, Sort and List the
 * data
 */

// MENU CONSTANTS
enum menuEnum {
    OP_UNSELECTED = 0,
    OP_ADD,
    OP_FIND,
    OP_REMOVE,
    OP_SORT,
    OP_LIST,
    OP_QUIT
};

// THE STRUCTURE

struct data{
    int id;
    char name[101];
    char address[251];
    char phone[101];
};

// PROTOTYPES
/*
 * This function is used to sort the data by name
 */
BOOLEAN sortOrder(void *a, void*b);

/*
 * This function is used to find data
 */
BOOLEAN findElement(void *where, void*what);

/*
 * This function shows and let the user choose it's
 * option
 */
int menu();

/*
 * This function creates a new structure
 */
struct data *newData(int id, char *name, char *address, char *phone);

int main() {

    galInitialize(5, 5);

    int option = OP_UNSELECTED;
    struct data *workingData;
    int id = 0;
    char name[101] = "";
    char address[251] = "";
    char phone[101] = "";
    ERROR error;

    while(option != OP_QUIT)
    {
        option = menu();

        switch (option) {
            case OP_ADD:
                printf("Type the id: ");
                scanf("%d", &id);

                scanf("%*c");

                printf("Type the name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Type the address: ");
                fgets(address, 250, stdin);
                address[strcspn(address, "\n")] = 0;

                printf("Type the phone #: ");
                fgets(phone, 100, stdin);
                phone[strcspn(phone, "\n")] = 0;

                workingData = newData(id, name, address, phone);

                galAdd(workingData);

                break;
            case OP_FIND:
                printf("Type the name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;

                workingData = galFind(findElement, name);
                if(workingData == NULL)
                {
                    printf("Register not found!\n");
                }
                else
                {
                    printf("\nFound:\n");
                    printf("  Name....: %s\n", workingData->name);
                    printf("  Address.: %s\n", workingData->address);
                    printf("  Phone...: %s\n\n", workingData->phone);
                }
                break;
            case OP_REMOVE:
                printf("Type the name: ");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;

                workingData = galFind(findElement, name);
                if(workingData == NULL)
                {
                    printf("Register not found!\n");
                }
                else
                {
                    galRemoveE(workingData);
                }
                break;
            case OP_SORT:
                galSort(sortOrder);
                break;
            case OP_LIST:
                for(size_t i = 0; i < galSize(); i++)
                {
                    workingData = galGet(i, &error); // we will ignore error this time*
                    printf("---------------------------------------\n");
                    printf("ID......: %d\n", workingData->id);
                    printf("Name....: %s\n", workingData->name);
                    printf("Address.: %s\n", workingData->address);
                    printf("Phone...: %s\n", workingData->phone);
                }
                break;
            case OP_QUIT:
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    galDestroy();

    return 0;
}

BOOLEAN sortOrder(void *a, void*b)
{
    struct data *a1;
    struct data *b1;

    a1 = a;
    b1 = b;

    if(strcmp(a1->name, b1->name) > 0)
    {
        return TRUE;
    }
    return FALSE;
}

BOOLEAN findElement(void *where, void*what)
{
    struct data *a;
    char *name;

    a = where;
    name = what;

    return !strcmp(a->name, name);
}

int menu()
{
    int op = OP_UNSELECTED;

    printf("MENU\n");
    printf("%d - Add\n", OP_ADD);
    printf("%d - Find\n", OP_FIND);
    printf("%d - Remove\n", OP_REMOVE);
    printf("%d - Sort\n", OP_SORT);
    printf("%d - List\n", OP_LIST);
    printf("%d - Quit\n", OP_QUIT);
    printf("Choose your option: ");
    scanf("%d", &op);
    scanf("%*c");

    return op;
}

struct data *newData(int id, char *name, char *address, char *phone)
{
    struct data *new = malloc(sizeof(struct data));
    if(!new)
    {
        printf("No memory!\n");
        exit(-1);
    }

    new->id = id;
    strcpy(new->name, name);
    strcpy(new->address, address);
    strcpy(new->phone, phone);

    return new;
}
