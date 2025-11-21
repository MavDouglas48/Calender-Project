#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct event{
    char name[100];
    char date[20];
    char time[10];
    char description[250];
    int monthNum; //ADDED - Describes which month the event is connected to, a value of 1 is January and 12 is December
    struct event* next;
} Event;

//ADDED - Function Prototypes
Event* createEvent(char* nTitle, char* nDate, char* nTime, char* nDescription, int nMonthNum);
void browseEvents(Event* events);

int main() {
    Event* head = NULL;

    int choice;
    do {
        printf("\nCommunity Calendar Menu:\n");
        printf("1. Create Event\n");
        printf("2. Browse Events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice  );
        getchar();

        switch (choice) {
            case 1:
                Event* temp = NULL;

                char newTitle[100];
                char newDate[20];
                char newTime[20];
                char newDescription[250];
                int newMonthNum;

                //Takes user input and stores it in variables to be used in the function to create the new event
                printf("Enter the name of this event:");
                fgets(newTitle, sizeof(newTitle), stdin);
                newTitle[strcspn(newTitle, "\n")] = '\0';

                printf("Enter the date of this event:");
                fgets(newDate, sizeof(newDate), stdin);
                newDate[strcspn(newDate, "\n")] = '\0';

                printf("Enter the time of this event:");
                fgets(newTime, sizeof(newTime), stdin);
                newTime[strcspn(newTime, "\n")] = '\0';

                printf("Enter the description of this event:");
                fgets(newDescription, sizeof(newDescription), stdin);
                newDescription[strcspn(newDescription, "\n")] = '\0';

                printf("Enter which month this event is in (1 - 12, 1-January & 12-December):");
                scanf("%d", &newMonthNum);
                getchar();
                
                Event* newEvent = createEvent(newTitle, newDate, newTime, newDescription, newMonthNum); //Takes the information from the user and calls a function to actually make the new event

                //Used to place the new event in the Linked List
                if (head == NULL){
                    head = newEvent;
                }
                else{
                    temp = head;
                    while (temp->next != NULL){ //Loops until the end of the linked list is reached
                        temp = temp->next;
                    }
                    temp->next = newEvent; //Adds the new event at the end of the linked list
                }

                printf("Event has been added.\n");
                break;
            case 2:
                /*browseEvents();
                NOTE - Not implemented yet
                */
                break;
            case 3:
                printf("Exiting calendar. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

//ADDED - Function to create and return a new event 
Event* createEvent(char* nTitle, char* nDate, char* nTime, char* nDescription, int nMonthNum) { //n means New
    Event* newEvent = malloc(sizeof(struct event)); //Makes space in the memory for the new event

    strncpy(newEvent->name, nTitle, sizeof(newEvent->name));
    strncpy(newEvent->date, nDate, sizeof(newEvent->date));
    strncpy(newEvent->time, nTime, sizeof(newEvent->time));
    strncpy(newEvent->description, nDescription, sizeof(newEvent->description));
    newEvent->monthNum = nMonthNum;
    newEvent->next = NULL;

    return newEvent; //Returns the new event's address (pointer)
}

//ADDED - Function to browse all the events in a certain month
//NEEDS - logic for checking which month, and function for displaying every event that is in the month
void browseEvents(Event* events) {
    int month;
    
    //ADDED - Displays a list of all the months
    //NEEDS - change the names of each month (1-12), 1 is January and 12 is Decemeber
    printf("Available Months:\n");
    printf("1.January\n");
    printf("2.January\n");
    printf("3.January\n");
    printf("4.January\n");
    printf("5.January\n");
    printf("6.January\n");
    printf("7.January\n");
    printf("8.January\n");
    printf("9.January\n");
    printf("10.January\n");
    printf("11.January\n");
    printf("12.January\n");
    printf("Select a Month:");
    scanf("%d", &month);
}



