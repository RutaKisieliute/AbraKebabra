#include <stdio.h>
#include <string.h>
#include "lib.h"

int createCssFile()
{
    FILE *cssFile = fopen("kebabs.css", "w");
    
    if(cssFile == NULL){
        return -1;
    }

    printFontFace(cssFile, "fonts/Lobster-Regular.ttf", "lobster", "normal");
    printFontFace(cssFile, "fonts/Domine-Bold.ttf", "Domine", "bold");
    printFontFace(cssFile, "fonts/Domine-Regular.ttf", "Domine", "normal");

    printScrollbar(cssFile, "", "width", "10px");
    printScrollbar(cssFile, "-track", "background", "#f1f1f1");
    printScrollbar(cssFile, "-thumb", "background", "#888");
    printScrollbar(cssFile, "-thumb:hover", "background", "#555");

    descriptionStart(cssFile, "*,\n*::before,\n*::after");
    printElement(cssFile, "box-sizing", "border-box");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, "body");
    printElement(cssFile, "margin", "0");
    fprintf(cssFile, "}\n");


    descriptionStart(cssFile, "h2, h4");
    printElement(cssFile, "margin-top", "0");
    printElement(cssFile, "margin-bottom", "0.5rem");
    fprintf(cssFile, "}\n");


    descriptionStart(cssFile, "h2");
    printElement(cssFile, "font-weight", "500");
    printElement(cssFile, "font-size", "2rem");
    fprintf(cssFile, "}\n");


    descriptionStart(cssFile, "h4");
    printElement(cssFile, "font-size", "1.5rem");
    fprintf(cssFile, "}\n");


    descriptionStart(cssFile, "p");
    printElement(cssFile, "margin-top", "0");
    printElement(cssFile, "margin-bottom", "1rem");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".container");
    printElement(cssFile, "width", "100%");
    printElement(cssFile, "padding-right", "15px");
    printElement(cssFile, "padding-left", "15px");
    printElement(cssFile, "margin-right", "auto");
    printElement(cssFile, "margin-left", "auto");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, "@media (min-width: 1200px){\n\t.container");
    printElement(cssFile, "max-width", "1140px");
    fprintf(cssFile, "\t}\n}\n");

    descriptionStart(cssFile, ".row");
    printElement(cssFile, "display", "-webkit-box");
    printElement(cssFile, "display", "-ms-flexbox");
    printElement(cssFile, "display", "flex");
    printElement(cssFile, "-ms-flex-wrap", "wrap");
    printElement(cssFile, "flex-wrap", "wrap");
    printElement(cssFile, "margin-right", "-15px");
    printElement(cssFile, "margin-left", "-15px");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".col-3, .col-9");
    printElement(cssFile, "position", "relative");
    printElement(cssFile, "width", "100%");
    printElement(cssFile, "min-height", "1px");
    printElement(cssFile, "padding-right", "15px");
    printElement(cssFile, "padding-left", "15px");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".col-3");
    printElement(cssFile, "-webkit-box-flex", "0");
    printElement(cssFile, "-ms-flex", "0 0 25%");
    printElement(cssFile, "flex", "0 0 25%");
    printElement(cssFile, "max-width", "25%");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".col-9");
    printElement(cssFile, "-webkit-box-flex", "0");
    printElement(cssFile, "-ms-flex", "0 0 75%");
    printElement(cssFile, "flex", "0 0 75%");
    printElement(cssFile, "max-width", "75%");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".top-banner");
    printElement(cssFile, "background-color", "#497174");
    printElement(cssFile, "position", "sticky");
    printElement(cssFile, "top", "0");
    printElement(cssFile, "z-index", "1");
    printElement(cssFile, "box-shadow", "0px 0px 20px #000000");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".site-title");
    printElement(cssFile, "color", "#EFF5F5");
    printElement(cssFile, "font-family", "lobster");
    printElement(cssFile, "padding-bottom", "35px");
    printElement(cssFile, "padding-top", "30px");
    printElement(cssFile, "margin-bottom", "2px");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".review-box");
    printElement(cssFile, "background-color", "#FFFFFF");
    printElement(cssFile, "text-align", "justify");
    printElement(cssFile, "margin-bottom", "2px");
    printElement(cssFile, "padding-bottom", "20px");
    printElement(cssFile, "padding-top", "20px");
    printElement(cssFile, "padding-left", "30px");
    printElement(cssFile, "padding-right", "30px");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".kebab-paragraph");
    printElement(cssFile, "color", "#497174");
    printElement(cssFile, "font-family", "Domine");
    printElement(cssFile, "font-size", "15px");
    printElement(cssFile, "line-height", "20.25px");
    printElement(cssFile, "padding-top", "10px");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".kebab-header");
    printElement(cssFile, "display", "inline");
    printElement(cssFile, "color", "#497174");
    printElement(cssFile, "font-weight", "bold");
    printElement(cssFile, "font-family", "Domine");
    printElement(cssFile, "font-size", "22px");
    printElement(cssFile, "text-decoration", "underline");
    printElement(cssFile, "text-decoration-thickness", "1.5px");
    printElement(cssFile, "text-underline-offset", "3px");
    fprintf(cssFile, "}\n");

    descriptionStart(cssFile, ".kebab-date");
    printElement(cssFile, "text-align", "right");
    printElement(cssFile, "color", "#497174");
    printElement(cssFile, "font-weight", "bold");
    printElement(cssFile, "font-family", "Domine");
    fprintf(cssFile, "}\n");

    fclose(cssFile);

    return 0;
}