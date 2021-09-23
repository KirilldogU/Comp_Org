// Assignment 6 for Computer Organization (CSCI 304)
// By Kirill Usubyan. Due 4/24/21
//contact.c file
#include "contact.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// method allocates memory and creates a permanent Contact object for argument contact
CONTACT_T *create_contact (CONTACT_T *contact){
    // creates permanent contact pointer and properly allocates memory for it
    CONTACT_T *contact_pointer;
    contact_pointer = (CONTACT_T *) malloc(sizeof(CONTACT_T));
    //copies all data in argument contact   
    strcpy(contact_pointer->first_name, contact->first_name);
    strcpy(contact_pointer->last_name, contact->last_name);
    strcpy(contact_pointer->co_name, contact->co_name);
    strcpy(contact_pointer->addr, contact->addr);
    strcpy(contact_pointer->city, contact->city);
    strcpy(contact_pointer->county, contact->county);
    strcpy(contact_pointer->state, contact->state);
    strcpy(contact_pointer->zip, contact->zip);
    strcpy(contact_pointer->phone1, contact->phone1);
    strcpy(contact_pointer->phone2, contact->phone2);
    strcpy(contact_pointer->email, contact->email);
    strcpy(contact_pointer->web, contact->web);
    // sets next to null (assumed last node)
    contact_pointer->next = NULL;
    //returns permanent contact
    return contact_pointer;
}

// method prints contact according to mode
void print_contact (CONTACT_T *contact, char mode){
    if(mode=='c'){ //shortened mode
        //prints basic data with string padding
        printf("%-18s%-18s%-15s%s\n", contact->last_name, contact->first_name, contact->phone1, contact->email);
    }else{
        //full mode
        // prints full contact data with proper spacing
        printf("Name:    %s %s\n", contact->first_name, contact->last_name);
        printf("Address: %s, %s, %s %s  (%s County)\n", contact->addr, contact->city, contact->state, contact->zip, contact->county);
        printf("Phone:   %s (primary)  %s\n", contact->phone1, contact->phone2);
        printf("email:   %s\n", contact->email);
        printf("web:     %s\n\n", contact->web);
    }
}
