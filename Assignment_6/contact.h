#ifndef CONTACT_H
#define CONTACT_H
// defines name type (string of 15 chars)
typedef char NAME_T [15];
// creates contact structure used throughout program
typedef struct CONTACT
{
    NAME_T first_name;
    NAME_T last_name;
    char co_name[35];
    char addr[35];
    char city[20];
    char county[25];
    char state[3];
    char zip[6];
    char phone1[15];
    char phone2[15];
    char email[35];
    char web[45];
    struct CONTACT *next; 
} CONTACT_T;
//func prototypes for funcs in contact.c
CONTACT_T *create_contact (CONTACT_T *contact);

void print_contact (CONTACT_T *contact, char mode);

#endif