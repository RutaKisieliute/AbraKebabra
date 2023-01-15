#ifndef HEADER_H
#define HEADER_H
 
 int validateFile(FILE *file, char *fileName);
 int checkFile(char*fileName);
 void editHtml();
 int menu(int optNum, char **options);
 int getInt(char *prompt, int *input);
 void printErr(char *err);
 void printFontFace(FILE *file, char path[], char family[], char weight[]);
 void printScrollbar(FILE *file, char element[], char property[], char value[]);
 void descriptionStart(FILE *file, char element[]);
 void printElement(FILE *file, char property[], char value[]);
 int createCssFile();
 int createHtmlFile();

 #endif