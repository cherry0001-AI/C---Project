#include <stdio.h>
#include <stdlib.h>

void encryptDecrypt(char *input_file, char *output_file, char key) {
    FILE *fin, *fout;
    char ch;
    
    // Open input file 
    fin = fopen(input_file, "rb");
    if(fin == NULL) {
        printf("Error: Cannot open input file!\n");
        exit(1);
    }
    
    // Open the file and write in binary
    fout = fopen(output_file, "wb");
    if(fout == NULL) {
        printf("Error: Cannot create output file!\n");
        fclose(fin);
        exit(1);
    }
    
    // Read each character, encrypt/decrypt with XOR 
    while(1) {
        ch = fgetc(fin);  // Reads every character
        if(feof(fin)) break;  // Stop if end of file
        
        ch = ch ^ key;  
        fputc(ch, fout);  // Write encrypted/decrypted character
    }
    
    // Close the file
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
    
    // Same function process for both encryption and decryption
    encryptDecrypt(input_file, output_file, key);
    
    return 0;
}

