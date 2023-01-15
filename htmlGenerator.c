#include <stdio.h>
#include <string.h>

int createHtmlFile()
{
    FILE *htmlFile = fopen("index.html", "w");
    
    if(htmlFile == NULL){
        return -1;
    }

    fprintf(htmlFile, "<!DOCTYPE html>\n");
    fprintf(htmlFile, "<html>\n\t");
        fprintf(htmlFile, "<head>\n\t\t");
            fprintf(htmlFile, "<link rel=\"stylesheet\" type=\"text/css\" href=\"kebabs.css\" />\n\t");
        fprintf(htmlFile, "</head>\n\n\t");

        fprintf(htmlFile, "<body style=\"background-color: #EFF5F5;\">\n\t\t");
            fprintf(htmlFile, "<div class=\"top-banner\">\n\t\t\t");
                fprintf(htmlFile, "<div class=\"container\">\n\t\t\t\t");
                    fprintf(htmlFile, "<h2 class=\"site-title\">Abra Kebabra kebab shop reviews</h2>\n\t\t\t");
                fprintf(htmlFile, "</div>\n\t\t");
            fprintf(htmlFile, "</div>\n\n\t\t");

            fprintf(htmlFile, "<div class=\"container\">\n\t\t\t");
            fprintf(htmlFile, "</div>\n\t");
        fprintf(htmlFile, "</body>\n");
    fprintf(htmlFile, "</html>");

    fclose(htmlFile);
    return 0;
}