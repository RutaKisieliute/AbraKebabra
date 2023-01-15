#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

#define NAME_SIZE 100
#define BUFFER_SIZE 128
#define INSER_CONST 311
#define BACK_CONST 322

int validateFile(FILE *file, char *fileName)
{
    if(file == NULL){
        printf("Error: %s cannot be opened\n", fileName);
        return -1;
    }
}

int checkFile(char*fileName)
{
    if(access(fileName, F_OK) == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void editHtml()
{
    FILE *file = fopen("index.html", "r");
    if(validateFile(file, "index.html") == -1) return;

    FILE *front = fopen("fileStart.txt", "w");
    if(validateFile(front, "fileStart.txt") == -1) return;

    char *buf = malloc(INSER_CONST); 
    if(buf == NULL){
        printErr("failed to allocate memory");
        return;
    }
    fread(buf, 1, INSER_CONST, file);
    fwrite(buf, 1, INSER_CONST, front);
    fclose(front);


    char name[NAME_SIZE], date[10], textName[NAME_SIZE];
    int year, month, day;
    int dayNumber[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0; 
    int nameCount = 0;
    char c;
    printf("Enter place name:\n");
    for(int i = 0; i < NAME_SIZE && scanf("%c", &name[i]) && name[i] != '\n'; ++i)
    {
        ++nameCount;
    }
    printf("Enter date:    (in yyyy-mm-dd format)\n");
    while(scanf("%d-%d-%d", &year, &month, &day) != 3 || year < 1900 || month > 12 || month < 0 || day < 0 || day > dayNumber[month-1] || getchar() != '\n')
    {
        printf("wrong date, please enter date in format: yyyy-mm-dd\n");
        while(getchar() != '\n');
    }
    printf("Enter name of text file with review:   (one word in .txt format)\n");
    while(scanf("%s", &textName) != 1 || (textName[strlen(textName)-4] != '.') || (textName[strlen(textName)-3] != 't') || (textName[strlen(textName)-2] != 'x') || (textName[strlen(textName)-1] != 't') || getchar() != '\n')
    {
        printf("wrong file name, please enter file name in format: .txt\n");
        while(getchar() != '\n');
    }
    printf("\n");

    FILE *review = fopen(textName, "r");
    if(validateFile(review, textName) == -1) return;

    FILE *newIndex = fopen("fileStart.txt", "a");
    if(validateFile(newIndex, "fileStart.txt") == -1) return;

    fprintf(newIndex, "\t\t<div class=\"review-box\">\n\t\t\t\t");
        fprintf(newIndex, "<div class=\"row\">\n\t\t\t\t\t");
            fprintf(newIndex, "<div class=\"col-9\">\n\t\t\t\t\t\t");
                fprintf(newIndex, "<h4 class=\"kebab-header\">");
                for(int i = 0; i < nameCount; ++i)
                {
                    fprintf(newIndex, "%c", name[i]);
                }
                fprintf(newIndex,"</h4>\n\t\t\t\t\t");
            fprintf(newIndex, "</div>\n\t\t\t\t\t");

            fprintf(newIndex, "<div class=\"col-3 kebab-date\">");
            fprintf(newIndex, "%d-%.2d-%.2d", year, month, day);
            fprintf(newIndex, "</div>\n\t\t\t\t");

        fprintf(newIndex, "</div>\n\n\t\t\t\t");
        fprintf(newIndex, "<p class=\"kebab-paragraph\">");

            for (c = getc(review); c != EOF; c = getc(review)){
                if (c == '\n'){
                    ++count;
                }
            }     

            fseek(review, 0, SEEK_END);
            int len = ftell(review) - count;
            buf = malloc(len);
            rewind(review);

            fread(buf, 1, len, review);
            fwrite(buf, 1, len, newIndex);
            fclose(review);

        fprintf(newIndex, "</p>\n\t\t\t");
    fprintf(newIndex, "</div>\n\t\t");

    fseek(file, 0, SEEK_END);
    int backLen = ftell(file);
    buf = malloc(backLen);
    fseek(file, BACK_CONST, SEEK_SET);
    int printfNum = fread(buf, 1, backLen, file);
    fwrite(buf, 1, printfNum, newIndex);

    fclose(file);
    fclose(newIndex);

    remove("index.html");
    rename("fileStart.txt", "index.html");
}

int menu(int optNum, char **options) {
    int optionIsValid = 0;
    int option = 0;

    while(!optionIsValid) {
        printf("MENU\n");
        for(int i = 0; i < optNum; ++i)
            printf("%d. %s\n", i+1, options[i]);

        if(!getInt("Enter menu option number", &option))
            continue; 

        if(option < 1 || option > optNum) {
            printErr("there is no such option");
            continue;
        }

        optionIsValid = 1;
    }

    return option;
}

int getInt(char *prompt, int *input) {
    if(printf("%s: ", prompt), scanf("%d", input) != 1 || getchar() != '\n') {
        printErr("input should be integer");
        while(getchar() != '\n');
        return 0;
    }

    return 1;
}

void printErr(char *err) {
    printf("Error: %s.\n\n", err);
}

void printFontFace(FILE *file, char path[], char family[], char weight[])
{
    fprintf(file, "@font-face{\n\tsrc: url(%s);\n\tfont-family: %s;\n\tfont-weight: %s;\n}\n", path, family, weight);
}

void printScrollbar(FILE *file, char element[], char property[], char value[])
{
    fprintf(file, "::-webkit-scrollbar%s{\n\t%s: %s;\n}\n", element, property, value);
}

void descriptionStart(FILE *file, char element[])
{
    fprintf(file, "\n%s{\n", element);
}

void printElement(FILE *file, char property[], char value[])
{
    fprintf(file, "\t%s: %s;\n", property, value);
}