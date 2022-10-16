#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("To few arguments");
        return 1;
    }
    
    FILE* src = fopen(argv[1], "r");
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

    unsigned char* dataGrey = (unsigned char*) malloc((w * h) * sizeof(unsigned char));

    printf("%d %d\n", w, h);

    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            dataGrey[x + y * w] = (data[(x*3) + y * (w*3)]*30 + data[(x*3)+1 + y * (w*3)]*59 + data[(x*3)+2 + y * (w*3)]*11) / 100;
            printf("%d %d %d -> grey: ", data[(x*3) + y * (w*3)], data[(x*3)+1 + y * (w*3)], data[(x*3)+2 + y * (w*3)]);
            printf("%d\n", dataGrey[x+y*w]);
        }
        printf("\n");
    }

    // printf("%d %d %d\n", data[(c*3) + r * (w*3)], data[(c*3)+1 + r * (w*3)], data[(c*3)+2 + r * (w*3)]);

    FILE* dest = fopen(argv[2], "w");
    fprintf(dest, "P5\n");
    fprintf(dest, "%d %d\n", w, h);
    fprintf(dest, "255\n", w, h);
    fwrite(dataGrey, sizeof(unsigned char), w * h, dest);

    free(data);
    free(dataGrey);
    free(temp);
    return 0;
}