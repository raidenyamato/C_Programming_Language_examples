#include <stdio.h>
#define MAXCHAR 8

// functions
int get_line(char line[], int lim);
void copy(char to[], char from[]);

int main() {
    
    int len, max, prevmax, getmore;
    char line[MAXCHAR];
    char longest[MAXCHAR];
    char temp[MAXCHAR];
    max = prevmax = getmore = 0;
    
    while ((len = get_line(line, MAXCHAR)) > 0) {

        if (line[len - 1] != '\n') {
            if (getmore == 0)
                copy(temp, line);
            prevmax += len;
            if (max < prevmax)
                max = prevmax;
            getmore = 1;
            
        } else {
            if (getmore == 1) {
                if (max < prevmax + len) 
                {
                    max = prevmax + len;
                    copy(longest, temp);
                    longest[MAXCHAR - 1] = '\n';
                }
                getmore = 0;
            } else if (max < len)
            {
                max = len;
                copy(longest, line);
            }
            prevmax = 0;
        }
    }
    if (max > 0) {
        printf("%s", longest);
        printf("len = %d\n", max);
    }
    return 0;
    
}


int get_line(char line[], int lim) {
    int i, c;
    for (i=0; (i < lim-1) && ((c=getchar()) != EOF && c != '\n') ; ++i) {
        line[i] = c;
    }
    
    
    if (c == '\n') {
        line[i] = c;
        ++i;
    } else if(c == EOF && i > 0)
    {
        line[i] = '\n';
        ++i;
    }
    
    
    line[i] = '\0';
    return i;
    
    
}



void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
