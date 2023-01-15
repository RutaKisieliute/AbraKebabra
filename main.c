#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    char *menuOptions[] = {"Create CSS file", "Create HTML file", "Edit HTML", "Exit"};
    int option, optionCount = sizeof(menuOptions)/sizeof(menuOptions[0]);

    do{
        option = menu(optionCount, menuOptions);

        switch (option){
        case 1: ;
            char *op = "create";
            if (checkFile("kebabs.css") == 0) {
                printf("kebabs.css already exists\n\n");

                char *fileOptions[] = {"Replace CSS file","Cancel"};
                int fileOptionCount = sizeof(fileOptions)/sizeof(fileOptions[0]);

                if(menu(fileOptionCount, fileOptions) != 1){
                    printf("\n");
                    break;
                }
                op = "replace";
            } 

            if(createCssFile() != 0){
                printf("Error: failed to %s CSS file\n\n", op);
            }
            else{
                printf("kebabs.css has been %sd\n\n", op);
            }

            break;

        case 2: ;
            op = "create";
            if (checkFile("index.html") == 0) {
                printf("index.html already exists\n\n");

                char *fileOptions[] = {"Replace HTML file","Cancel"};
                int fileOptionCount = sizeof(fileOptions)/sizeof(fileOptions[0]);

                if(menu(fileOptionCount, fileOptions) != 1){
                    printf("\n");
                    break;
                }
            }

            if(createHtmlFile() != 0){
                printf("Error: failed to %s HTML file\n\n", op);
            }
            else{
                printf("index.html has been %sd\n\n", op);
            }
            break;

        case 3:
            if(checkFile("index.html") == 1) {
                printErr("index.html has not been created");
                break;
            }
            if(checkFile("kebabs.css") == 1){
                printf("Warning: kebabs.css has not been created yet\n");
            }
            editHtml();
            break;

        case 4:
            printf("Program closed");
            break;

        default:
            printErr("failed to select menu option");
            break;
        }

    }while(option != 4);

    return 0;
}