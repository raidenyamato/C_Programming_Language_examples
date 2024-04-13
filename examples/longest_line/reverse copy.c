#include <stdio.h>
#define MAX_LINE 1024
    
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    
    s[i] = '\0';
    
    return i;
}

int reverse(char s[], int count)
{
    char ch;
    int i, j;
    --count;
    
    for (i = 0; i < count; i++)
    {
        ch = s[i];
        s[i] = s[count];
        s[count] = ch;
        --count;
    }
    return 0;
}

int main(void)
{
    char line[MAX_LINE];
    int count;
    
    while((count = getLine(line, sizeof line)) && count > 0)
    {
        reverse(line, count);
        printf("%s\n\n", line);
    }
    return 0;
}
