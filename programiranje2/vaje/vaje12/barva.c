#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc < 4) {
        printf("To few arguments");
        return 1;
    }
    
    FILE* src = fopen(argv[1], "r");
    int r, c;
    sscanf(argv[2], "%d", &r);
    sscanf(argv[3], "%d", &c);

    printf("%d %d\n", r, c);

    char* temp = (char*) malloc(100 * sizeof(char));
    //P6
    fgets(temp, 100, src);
    int w, h;
    //width, height
    fscanf(src, "%d%d", &w, &h);
    //\n
    fgetc(src);
    //255
    fgets(temp, 100, src);
    // data
    unsigned char* data = (unsigned char*) malloc((w * h * 3) * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), w*h*3, src);

    printf("%d %d\n", w, h);

    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            printf("%d %d %d\n", data[(x*3) + y * (w*3)], data[(x*3)+1 + y * (w*3)], data[(x*3)+2 + y * (w*3)]);
        }
        printf("\n");
    }

    printf("%d %d %d\n", data[(c*3) + r * (w*3)], data[(c*3)+1 + r * (w*3)], data[(c*3)+2 + r * (w*3)]);

    return 0;
}