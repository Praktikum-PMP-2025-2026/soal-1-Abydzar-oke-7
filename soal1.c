/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 Dynamic Structures
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : Abydzar Dzakyan Akbar (13224106)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menentukan ke validan simbol kurung dengan mengabaikan huruf kecil pada segel mantra 
 * 
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 typedef struct Node {
    char data;
    struct Node* next;
 } Node;

 void push (Node** head, char x){
    Node* baru = (Node*)malloc(sizeof(Node));
    baru->data = x;
    baru->next = *head;
    *head = baru;
 }

 char pop(Node** head) {
    if (*head == NULL){
        return '\0';
    }

    Node* temp = *head;
    char x = temp->data;
    *head = (*head)->next;
    free(temp);
    return x;
 }
  
 int main() {
    Node* data = NULL; //dalam stack
    char input[999];
    int valid;

    scanf("%s", input);
    for(int i=0; i<strlen(input); i++){
        char dat = input[i];

        if(dat == '(' || dat == '[' || dat == '{'){
            push(&data, dat);
        } else if(dat == ')' || dat == ']' || dat == '}'){
            char buka_kurung = pop(&data);
            if ((dat == ')' && buka_kurung != '(') || (dat == ']' && buka_kurung != '[') || (dat == '}' && buka_kurung != '{')){
                valid = 0;
                break;
            }
        }

        if (data != NULL){
            valid = 0;
        }

        if (valid){
            printf("VALID");
        } else{
            printf("INVALID");
        }

        return 0;
    }
    
 }
