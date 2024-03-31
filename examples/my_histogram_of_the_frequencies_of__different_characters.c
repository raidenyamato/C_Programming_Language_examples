#include <stdio.h>

#define HISTOHEIGHT 50
#define FULL        "#"
#define EMPTY       "."

int main() {
    
    int c, i, l, maxfreq;
    double scale;
    
    int lenfreq[256] = {0};
    
    while ((c = getchar()) != EOF) {
        ++lenfreq[c];
    }
    
    maxfreq = 0;
    for (i = 0; i < 256; ++i) {
        if (lenfreq[i] > maxfreq)
            maxfreq = lenfreq[i];
    }
    scale = (double) HISTOHEIGHT / (double) maxfreq;
    
    for (i = 0; i < 256; ++i) {
        lenfreq[i] = lenfreq[i] * scale;
    }
    
    
    printf("Character frequency histogram (Only printing characters):\n\n");
    
    printf(" ");
    for (i = 32; i < 127; ++i) {
        printf(EMPTY);
    }
    printf("\n");
    
    for (l = HISTOHEIGHT; l > 0; --l) {
        printf(" ");
        for (i = 32; i < 127; ++i) {
            if (lenfreq[i] >= l) {
                printf(FULL);
            } else {
                printf(EMPTY);
            }
        }
        printf("\n");
    }
    printf(" ");
    for (i = 32; i < 127; ++i) {
        putchar(i);
    }
    printf("\n\n");
        
    
    return 0;
}

