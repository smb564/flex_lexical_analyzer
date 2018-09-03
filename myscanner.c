#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "db_type", "db_name", "db_table_prefix", "db_port"};

int main(void){
    // name token (key), value token
    int ntoken, vtoken;

    // yylex returns the next token, returns 0 in the end
    ntoken = yylex();

    while(ntoken){
        printf("%d\n", ntoken);

        // Should have the format key : value. otherwise syntax error
        if (yylex() != COLON){
            printf("Syntax error in line number %d, expected a : but found %s\n", yylineno, yytext);
            return 1;
        }

        vtoken = yylex();
        switch(ntoken){
            case TYPE:
            case NAME:
            case TABLE_PREFIX:
                if (vtoken != IDENTIFIER){
                    printf("Syntax error in line number %d, expected an identifier but found %s\n", yylineno, yytext);
                    return 1;
                } else {
                    printf("Value %s set to %s\n", yytext, names[ntoken]);
                    break;
                }
            case PORT:
                if (vtoken != INTEGER) {
                    printf("Syntax error in line number %d, expected a number but found %s\n", yylineno, yytext);
                    return 1;
                } else {
                    printf("%s set to %s\n", names[ntoken], yytext);
                    break;
                }
        }
        ntoken = yylex();
    }

    return 0;

}