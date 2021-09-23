#include "contact.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//initializes static global variables
static CONTACT_T *bucketList[26];
static CONTACT_T *curContact = NULL;

// method intializes list of contacts used throughout program
void init_contact_list (void){
    // sets each index of CONTACT pointers to initially NULL 
    short index;
    //iterates through indices
    for(index =0; index < 26; ++index){
        bucketList[index] = NULL;
    }
}

// method inserts argument contact into bucketList data structure
void insert_contact (CONTACT_T *contact){
    // finds which index's Linked List to add to
    short indexInBucket = (contact->last_name)[0] - 'A';
    // temporary variables for iteration
    CONTACT_T *current = bucketList[indexInBucket];
    CONTACT_T *previous = NULL;
    if(current == NULL){
        // if Linked List is empty initialize with one node
        bucketList[indexInBucket] = contact;
    }else{
        // otherwise iterate through LL until finds proper location
        while ((current!=NULL) && ((strcmp(contact->last_name, current->last_name)) > 0)){
            previous = current;
            current = current->next;
        }
        // handling for inserting into front of Linked list
        if(previous==NULL){
            bucketList[indexInBucket] = contact;
            contact->next = current;
        }//otherwise inserting into middle or back of LL
        else{
            previous->next = contact;
            contact->next = current;            
        }
    }
}

// method prints the contact list
void print_contact_list (char mode){

    short index;
    //var tracks whether contact list is empty
    short empty_c = 1;
    CONTACT_T *current;
    // iterates through list and checks whether LL are empty
    for(index =0; index < 26; ++index){
        if (bucketList[index] != NULL){
            empty_c = 0;
        }
    }// if contact list is empty then print so
    if(empty_c == 1){
        printf("\nNo contacts found\n");
    } //otherwise iterates each LinkedList
    // setting current to each of the contacts and printing them
    else{
        for(index =0; index < 26; ++index){
            current = bucketList[index];
            while (current != NULL){
                print_contact(current, mode);
                current = current->next;
            }            
        }
    }
}

// Finds and returns a contact matching the last name and first name, if one exits
CONTACT_T *find_contact (NAME_T last_name, NAME_T first_name){
    // finds which linked list to access (index in bucket list)
    short indexInBucket = last_name[0] - 'A';
    // creates temp variables for iteration
    CONTACT_T *current = bucketList[indexInBucket];
    NAME_T temp_last_name;
    NAME_T temp_first_name;
    // iterates through LinkedList, getting the uppercase of the names
    // and comparing them to parameter arguments
    while (current!=NULL){
        strcpy(temp_last_name, current->last_name);
        strcpy(temp_first_name, current->first_name);
        upper(temp_last_name);
        upper(temp_first_name);
        if(strcmp(last_name, temp_last_name) == 0 && strcmp(first_name, temp_first_name) == 0){
            return current;
            //returns contact in case of match
        }
        current = current->next;
    }
    // returns NULL if contact does not exist
    return NULL;
}

// method that iterates through a single LinkedList and returns next contact
// uses global static var curContact
CONTACT_T *get_next_contact (char letter){
    // if begging iteration then find proper LL
    if(curContact == NULL){
        short indexInBucket = letter - 'A';
        curContact = bucketList[indexInBucket];
    }   //otherwise just iterate
    else{
        curContact = curContact->next;
    }
    //return contact
    return curContact;  

}

// method prints the contacts in BucketList from the correct state
void print_state_contacts (char state [], char mode){
    // temporary variables
    short index;
    CONTACT_T *current;
    char curState[3];
    // var tracks whether any matches have been found
    short foundMatch = 0;
    // iterates through all the linked lists (bucketList[index])s
    // and all the contacts in each LL
    // prints matches if cur.state = argument state
    for(index = 0; index < 26; ++index){
        current = bucketList[index];
        while (current != NULL){
            strcpy(curState, current->state);
            if (strcmp(curState, state)==0){
                print_contact(current, mode);
                foundMatch = 1;
            }
            current = current->next;
        }
    }
    // if no matches were found, prints accordingly
    if(foundMatch == 0){
        printf("No contacts found\n");
    }
}

// method deallocates memory used by bucketList
void free_contact_list (void){
    // temp vars
    short index;
    CONTACT_T *current;
    // iterates through all the linked lists (bucketList[index])s
    // and all the contacts in each LL
    // deallocates memory for each node/contact
    for(index = 0; index < 26; ++index){
        current = bucketList[index];
        while (current != NULL){
            free(current);
            current = current->next;
        }
    }
}
