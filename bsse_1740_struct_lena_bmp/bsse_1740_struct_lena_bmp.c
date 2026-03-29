/*
Name        : Md. Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;     
    unsigned int bfSize;         
    unsigned short bfReserved1;  
    unsigned short bfReserved2;  
    unsigned int bfOffBits;      
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;         
    int biWidth;                 
    int biHeight;                
    unsigned short biPlanes;     
    unsigned short biBitCount;   
    unsigned int biCompression; 
    unsigned int biSizeImage;    
    int biXPelsPerMeter;         
    int biYPelsPerMeter;         
    unsigned int biClrUsed;      
    unsigned int biClrImportant; 
} BITMAPINFOHEADER;
#pragma pack(pop)

int main() {
    FILE *fp = fopen("lena.bmp", "rb");
    if (!fp) {
        printf("Error: Could not open lena.bmp\n");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    if (fileHeader.bfType != 0x4D42) {
        printf("Error: Not a BMP file!\n");
        fclose(fp);
        return 1;
    }

    if (infoHeader.biBitCount != 24) {
        printf("Error: This program only supports 24-bit BMP files.\n");
        fclose(fp);
        return 1;
    }

    int width = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight); 
    int rowSize = (width * 3 + 3) & (~3);  

    printf("Width: %d pixels\n", width);
    printf("Height: %d pixels\n", height);
    printf("Bits per pixel: %d\n", infoHeader.biBitCount);
    printf("Image size (biSizeImage): %u bytes\n", infoHeader.biSizeImage);
    printf("File size: %u bytes\n", fileHeader.bfSize);

    
    fseek(fp, fileHeader.bfOffBits, SEEK_SET);


    unsigned char *row = (unsigned char *)malloc(rowSize);
    if (!row) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return 1;
    }


    FILE *out = fopen("lena_gray.bmp", "wb");
    if (!out) {
        printf("Error: Could not create lena_gray.bmp\n");
        free(row);
        fclose(fp);
        return 1;
    }


    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, out);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, out);

    
    for (int i = 0; i < height; i++) {
        fread(row, 1, rowSize, fp);
        for (int j = 0; j < width * 3; j += 3) {
            unsigned char blue = row[j];
            unsigned char green = row[j + 1];
            unsigned char red = row[j + 2];

            
            unsigned char gray = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);

            row[j] = row[j + 1] = row[j + 2] = gray;
        }
        fwrite(row, 1, rowSize, out);
    }

    printf("Output file: lena_gray.bmp\n");

    free(row);
    fclose(fp);
    fclose(out);
    return 0;
}