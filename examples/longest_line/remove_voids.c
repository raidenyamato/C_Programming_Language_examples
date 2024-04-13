#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int left);
int copy(char filteredLines[], char line[], int used, int left);

int main() {
    int notEmpty = 0;
    int left = MAXLINE;
    int lastUsed = 0;
    char line[MAXLINE];
    char filteredLines[MAXLINE+1];
    
    while ((lastUsed = getLine(line, left)) > 0 ) {
        left = copy(filteredLines, line, lastUsed, left);
    }
    
    printf("%s", filteredLines);
    
    return 0;
}

int getLine(char line[], int left) {
    int blank = 0;
    int c, i;
    i = 0;
    while (i <= left && (c=getchar()) != EOF && c!='\n') {
        if (c == ' ' || c == '\t') {
            if (blank == 0) {
                line[i] = c;
                blank = 1;
            }
        } else {
            if (blank == 1) {
                blank = 0;
                line[++i] = c;
                ++i;
            } else {
                line[i] = c;
                ++i;
            }
        }
    }
    if (c == ' ' || c == '\t' || c == '\n') {
        line[i] = '\n';
        ++i;
    }
    
    return i;
}

int copy(char filteredLines[], char line[], int lastUsed, int left) {
    int currentIndex = MAXLINE - left;
    int i = 0;
    
    while (line[i] == '\n') {
        ++i;
    }
    
    while ( i <= lastUsed ) {
        filteredLines[currentIndex] = line[i];
        ++currentIndex;
        ++i;
    }
    filteredLines[currentIndex] = '\0';
    
    return left - lastUsed;
}
