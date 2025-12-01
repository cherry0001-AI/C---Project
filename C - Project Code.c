#include <stdio.h>
#include <stdlib.h>

void encryptDecrypt(char *input_file, char *output_file, char key) {
    FILE *fin, *fout;
    char ch;
    
    
    fin = fopen(input_file, "rb");
    if(fin == NULL) {
        printf("Error: Cannot open input file!\n");
        exit(1);
    }
    
    
    fout = fopen(output_file, "wb");
    if(fout == NULL) {
        printf("Error: Cannot create output file!\n");
        fclose(fin);
        exit(1);
    }
    
     
    while(1) {
        ch = fgetc(fin);  
        if(feof(fin)) break;  
        
        ch = ch ^ key;  
        fputc(ch, fout);  
    }
    
    
    fclose(fin);
    fclose(fout);
    
    printf("Operation completed successfully!\n");
}

int main() {
    char input_file[100], output_file[100];
    char key;
    int choice;
    
    printf("File Encryption/Decryption Tool\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    printf("Enter input filename: ");
    scanf("%s", input_file);
    printf("Enter output filename: ");
    scanf("%s", output_file);
    printf("Enter encryption key (single character): ");
    scanf(" %c", &key);  
    
    
    encryptDecrypt(input_file, output_file, key);
    
    return 0;
}


