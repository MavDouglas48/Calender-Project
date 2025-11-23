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

//Function Prototypes
Event* createEvent(char* nTitle, char* nDate, char* nTime, char* nDescription, int nMonthNum);
void browseEvents(Event* events);
Event* removeEvent(Event* head, const char* targetName);

void displayEvent(Event* event);

int main() {
    Event* head = NULL;

    int choice;
    do {
        printf("\nCommunity Calendar Menu:\n");
        printf("1. Create Event\n");
        printf("2. Browse Events\n");
        printf("3. Remove Event\n");
        printf("4. Exit\n");
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
                /*
                If there are no events print that there are none,
                otherwise call browseEvents() to display the events.
                */
                if (head == NULL){
                    printf("\nThere are no events to browse.\n");
                }
                else{
                    browseEvents(head);
                }
                break;
            case 3:
                char target[100];
                printf("Enter the name for the event: ");
                fgets(target, sizeof(target), stdin);
                target[strcspn(target, "\n")] = '\0';

                head = removeEvent(head, target);
                break;
            case 4:
                printf("Exiting calendar. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

//Function to create and return a new event 
Event* createEvent(char* nTitle, char* nDate, char* nTime, char* nDescription, int nMonthNum) { //n means New
    Event* newEvent = malloc(sizeof(Event)); //Makes space in the memory for the new event

    strncpy(newEvent->name, nTitle, sizeof(newEvent->name));
    strncpy(newEvent->date, nDate, sizeof(newEvent->date));
    strncpy(newEvent->time, nTime, sizeof(newEvent->time));
    strncpy(newEvent->description, nDescription, sizeof(newEvent->description));
    newEvent->monthNum = nMonthNum;
    newEvent->next = NULL;

    return newEvent; //Returns the new event's address (pointer)
}

//Function to browse all the events in a certain month
void browseEvents(Event* head) {
    Event* temp = head;
    int month;
    
    //Displays a list of all the months
    printf("\nSelect a month:\n");
    printf("1.January\n");
    printf("2.February\n");
    printf("3.March\n");
    printf("4.April\n");
    printf("5.May\n");
    printf("6.June\n");
    printf("7.July\n");
    printf("8.August\n");
    printf("9.September\n");
    printf("10.October\n");
    printf("11.November\n");
    printf("12.December\n");
    printf("Enter your choice:");
    //Input validation for selecting the month
    if(scanf("%d", &month) != 1) {
        printf("Invalid input.\n");
        return;
    }
    getchar();

    //Prints which month's events are going to be displayed
    printf("\n");
    if (month == 1){
        printf("Events for January:\n\n");
    } else if (month == 2){
        printf("Events for February:\n\n");
    } else if (month == 3){
        printf("Events for March:\n\n");
    } else if (month == 4){
        printf("Events for April:\n\n");
    } else if (month == 5){
        printf("Events for May:\n\n");
    } else if (month == 6){
        printf("Events for June:\n\n");
    } else if (month == 7){
        printf("Events for July:\n\n");
    } else if (month == 8){
        printf("Events for August:\n\n");
    } else if (month == 9){
        printf("Events for September:\n\n");
    } else if (month == 10){
        printf("Events for October:\n\n");
    } else if (month == 11){
        printf("Events for November:\n\n");
    } else if (month == 12){
        printf("Events for December:\n\n");
    }

    /*
    Loops through the linked list, displaying events with a monthNum that 
    matches the selected month.
    */
    int flag = 0;
    do{
        if (temp->monthNum == month){
            displayEvent(temp);
            flag = 1;
        }
        temp = temp->next;
    } while (temp != NULL);

    /*
    If no events in the Linked List match the month no events will be displayed, 
    otherwise print that the events have been displayed.
    */
    if (!flag){
        printf("There are no events for this month.\n");
    }else{
        printf("All events for this month have been displayed.\n");
    }
}

//Function used to display events in the Linked List
void displayEvent(Event* event){
    printf("Event Name:%s\n", event->name);
    printf("Event Date:%s\n", event->date);
    printf("Event Time:%s\n", event->time);
    printf("Event Description:%s\n\n", event->description);
}

Event* removeEvent(Event* head, const char* targetName) {
    // If list is empty
    if (head == NULL) {
        printf("There are no events to remove.\n");
        return head;
    }

    Event* temp = head;
    Event* prev = NULL;

    // Check if the head is the one to delete
    if (strcmp(head->name, targetName) == 0) {
        head = head->next;      
        free(temp);             
        printf("Event removed successfully.\n");
        return head;
    }

    // Search the list for the event
    while (temp != NULL && strcmp(temp->name, targetName) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf("Event not found.\n");
        return head;
    }

    // Remove the event
    prev->next = temp->next;
    free(temp);

    printf("Event removed successfully.\n");
    return head;
}
