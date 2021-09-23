// Assignment 6 for Computer Organization (CSCI 304)
// By Kirill Usubyan. Due 4/24/21
//main.c file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "utils.h"
#include "contact_list.h"

// func reads arg csv file, finding all contact data and inserting it into the contact list
void process_file(char *filename){
    // opens csv file
    FILE *filepointer;
    filepointer = fopen(filename,"r");
    // temp contact storage
    CONTACT_T tempContact;
    //read and discard first line
    fscanf(filepointer, "%*s ");    
    // reads in each line (while lines are full) and saves data in temp contact values
    while(fscanf(filepointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%s ", tempContact.first_name, tempContact.last_name, tempContact.co_name, tempContact.addr, tempContact.city, tempContact.county, tempContact.state, tempContact.zip, tempContact.phone1, tempContact.phone2, tempContact.email, tempContact.web) == 12){
        // create permanent contact using temp values
        CONTACT_T *finalContact = create_contact(&tempContact);
        // insert final contact into full list
        insert_contact(finalContact);
    }
    // close file
    fclose(filepointer);
}

// func prints menu of options, accepts input, and repeats until recieves proper vals
char print_menu(void){
    char strInput[10];  // input
    char repeat;    //Used as boolean that judges whether input is valid
    do {
        repeat = 0; //initially valid input
        // prints all options
        printf("%s","\nPlease select one of the following: \n\n");
        printf("%s"," c  Change output format\n");
        printf("%s"," i  Search for individual\n");
        printf("%s"," t  Print tab\n");
        printf("%s"," s  Look up by state\n");
         printf("%s", " q  Quit\n");
        printf("%s","\nOption: ");

        // stores input in char array in case of too long input
        scanf(" %s", strInput); 
        printf("%s\n", strInput);
        
        // checks if inputted char is one of the valid ones
        char* pPosition = strchr("citsq", tolower(strInput[0]));
        //repeat if invalid char
        if(pPosition == NULL){
            repeat=1;
            printf("\nInvalid option entered\n\n");  
        //repeat if more than one char passed in
        }if (strInput[1]!='\0'){
            repeat = 1;
            printf("\nInvalid option entered\n\n");  
        }
    } while (repeat == 1);
    // returns lowercase of input (for simplification)
    return tolower(strInput[0]);   
}

// func prints simple menu on formats, accepts input without real error check
char print_format_menu(void){
    char strInput[20];  //stores input
    // prints menu and options
    printf("%s","\nPlease select one of the following: \n\n");
    printf("%s"," c Condensed output information\n");
    printf("%s", " f Full output information\n");
    printf("%s","\nOption: ");

    // stores input in char array in case of too long input
    scanf(" %s", strInput); 
    printf("%s\n", strInput);
    // returns first char, lowercase
    return(tolower(strInput[0]));
}

// func accepts input from user for what person to search for (name)
// calls functions to find them and either print not found, or valid information
void find_individual(char mode){
    // declares temp vars
    NAME_T req_last_name;
    NAME_T req_first_name;
    // ask user for names, stores result
    printf("%s","\nPlease enter last name: ");
    scanf(" %s", req_last_name); 
    printf("%s\n", req_last_name);
    printf("%s", "Please enter first name: ");
    scanf(" %s", req_first_name); 
    printf("%s\n\n", req_first_name);
    //sets them to uppercase, for char comparison
    upper(req_last_name);
    upper(req_first_name);
    // calls method which searches for contact
    CONTACT_T *ret_contact;
    ret_contact = find_contact(req_last_name,req_first_name);
    if(ret_contact == NULL){
        //invalid contact
        printf("Contact not found\n");
    }else{
        //prints valid contact
        print_contact(ret_contact, mode);
    }
}

// func prints all contacts with proper first letter in last name
void print_tab(char mode){
    char LastLet[5];
    // accepts input for requested first letter of last name
    printf("%s","\nPlease enter last name tab letter: ");
    scanf(" %s", LastLet); 
    printf("%s\n\n", LastLet);

    upper(LastLet);
    // finds first contact with letter as first in last name
    CONTACT_T *tempContact = get_next_contact(LastLet[0]);
    // if that contact does not exist
    if (tempContact == NULL){
        // prints no such contacts
        printf("No contacts found\n");
    }else{
        //otherwise, iterates through all contacts in LL and prints all data
        while (tempContact != NULL){
            print_contact(tempContact, mode);
            tempContact = get_next_contact(LastLet[0]);
        }
        
    }
    
}

// func accepts input from user for a state to search for
// then prints all contacts in that state
void process_state_contacts(char mode){
    char state[3];
    // prints and stores a 2 letter state abr.
    printf("%s","\nPlease enter two-letter state abbreviation: ");
    scanf(" %s", state); 
    printf("%s\n\n", state);
    // uppercases state abr.
    upper(state);
    // prints all contacts in that state
    print_state_contacts(state, mode);
}

// main method which drives program
void main(int argc, char *argv []){
    char mode = 'c'; // defaults to simple formatting

    // error handles for too few command line arguments
    if(argc < 2){
        printf("Invalid arguments");
        exit(0);
    }

    // initializes contact list by method
    init_contact_list();

    char *filename;
    //set to inputted filename
    filename = argv[1];
    //processes that file
    process_file(filename);

    //prints resulting contant list
    print_contact_list(mode);

    char option; // option of what user requests
    do{
        //switch for method calls
        option = print_menu(); // gets chosen option from menu
        switch (option) // handles for all types of options
        {
        case 'c':
            mode = print_format_menu();
            break;
        case 'i':
            find_individual(mode);
            break;
        case 't':
            print_tab(mode);
            break;
        case 's':
            process_state_contacts(mode);
            break;
        default:
            break;
        }
    }while(option !='q');      
    // repeats while option is not quit

    //free contact list (deallocates memory)
    free_contact_list();

    //THE END
}