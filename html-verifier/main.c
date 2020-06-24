// Include global
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Include Projeto
#include "pilha.h"

#define LINE_BUFFER_SIZE 200
enum CODIGOS {
    ARQUIVO_VALIDO = 0x00,
    ARQUIVO_INVALIDO = 0x01,
    ARQUIVO_NOT_FOUND = 0x03,
    MEM_ERROR = 0x02
};

void trim(char* str) {
    int i;
    int begin = 0;
    int end = strlen(str) - 1;

    while (isspace((unsigned char)str[begin]))
        begin++;

    while ((end >= begin) && isspace((unsigned char)str[end]))
        end--;

    // Shift all characters back to the start of the string array.
    for (i = begin; i <= end; i++)
        str[i - begin] = str[i];

    str[i - begin] = '\0';  // Null terminate string.
}

unsigned short verify_file(const char* filename, descritor* pilha) {
    FILE* fp;
    char* line_buffer;
    line_buffer = (char*)malloc(sizeof(char) * (LINE_BUFFER_SIZE + 1));
    if (line_buffer == NULL) {
        return MEM_ERROR;
    }
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return ARQUIVO_NOT_FOUND;
    }
    fgets(line_buffer, LINE_BUFFER_SIZE, fp);
    trim(line_buffer);
    if (strcmp(line_buffer, "<!DOCTYPE html>") != 0) {
        free(line_buffer);
        fclose(fp);
        return ARQUIVO_INVALIDO;
    }
    while (!feof(fp)) {
        fgets(line_buffer, LINE_BUFFER_SIZE, fp);
        trim(line_buffer);
        if (strcmp(line_buffer, "") || strlen(line_buffer) > 0) {
            if (line_buffer[0] == '<') {
                // It's a tag
                    print_pilha(pilha);
                if (line_buffer[1] == '/') {
                    // it's a closing tag
                    if (strcmp(line_buffer + 2, pilha->topo->tag + 1) == 0) {
                        // It's valid
                        remove_topo(pilha);
                    } else {
                        // it's invalid
                        // clear every thing and exit
                        reinicia_pilha(pilha);
                        free(line_buffer);
                        fclose(fp);
                        return ARQUIVO_INVALIDO;
                    }
                } else {
                    // it's a opening tag
                    adiciona_topo(pilha, line_buffer);
                }
            } else {
                // It's content
            }
        }
    }
    // Clear everything
    // Return valid
    reinicia_pilha(pilha);
    free(line_buffer);
    fclose(fp);
    return ARQUIVO_VALIDO;
}

int main() {
    // Criar Pilha
    descritor* pilha;
    unsigned short verify_exit_code;
    cria_pilha(&pilha);
    // Ler arquivos
    const char* arquivos[] = {
        "./arquivos/arquivo_correto.html",
        "./arquivos/arquivo_incorreto.html",
        "./arquivos/arquivo_sem_doctype.html"};
    for (int i = 0; i < 3; i++) {
        verify_exit_code = verify_file(arquivos[i], pilha);
        if (verify_exit_code == ARQUIVO_VALIDO) {
            printf("O arquivo é válido 🥰\n");
        } else if (verify_exit_code == ARQUIVO_INVALIDO) {
            printf("O arquivo é inválido 🥺\n");
        } else {
            printf("Erro desconhecido 🤬\n");
        }
    }
    return 0;
}
