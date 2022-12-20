#include <stdio.h>
#include <stdlib.h>

char *hexidecimal(int sample[8]) {
    char *field = malloc(sizeof(char)*11*8);
    for (int i = 0; i < 8; i++) {
        sprintf((field + 11*i), "0x%8x", sample[i]);
    }
    // ��� �������
    for (int i = 0; i < 11*8; i++) {
        if (*(field+i) == ' ') *(field+i) = '0';
        if ((*(field+i) > 'a'-1)&&(*(field+i) < 'g')) *(field + i) += 'A'-'a';
    }
    return field;
}

char *adj_b(char *tile) {
    if (tile == NULL) return 0;
    if ((*tile + 1) == 'B') return (tile + 1); 
    if ((*tile + 11)== 'B') return (tile +11); 
    if ((*tile - 1) == 'B') return (tile - 1); 
    if ((*tile - 11)== 'B') return (tile -11);
    return 0;
}
char *adj_a(char *tile) {
    if (tile == NULL) return 0;
    if (*tile != 'B') return 0;
    if ((*tile + 1) == 'A') return tile+1;
    if ((*tile + 11)== 'A') return tile+11;
    if ((*tile - 1) == 'A') return tile-1;
    if ((*tile - 11)== 'A') return tile-11;
    return 0;
}

int abba(int sample[8]) {
    char *field = hexidecimal(sample);
    int k = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 2; j < 11; j++) { // ���� ��� �� ��������
            if ((*(field + j + 11 * i) == 'A')&& // ���� ���� �
            (*(adj_b(field + j + 11 * i)) == 'B')&& // � ����� � ��� �
            (*(adj_b(adj_b(field + j + 11 * i))) == 'B')&& // � ����� � ��� �
            (*(adj_a(adj_b(adj_b(field + j + 11 * i)))) == 'A')) k++; // � ����� � ��� �  �� �++
        }
    }
    free(field);
    return k/2;
}

int main () {

    /* TODO 
    
    �� �������� ����������� �������.
    
    � ��������� �������� ������� � ��������
    
    */
    
    int sample1[8] = {-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    
    int sample2[8] = {-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};

    printf("%d\n", abba(sample1));
    printf("%d\n", abba(sample2));



    /* ������� ��������� ������� � base16

    int sample1[8] ={-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    // ���� ������� ����� � ���������� �������
    for (int i = 0; i < 8; i++) {
        printf("%x\n",sample1[i]);
    } // ��� ��� ��� ������ ��������� � hex, ������ �� ������� ���������� ����. ��������� � ���� �����.
    puts("");
    // ������ ���� 11�8 � ������� ���� hex. ���� �������� ����� ������.
    char *field = malloc(sizeof(char)*11*8);
    for (int i = 0; i < 8; i++) {
        sprintf((field + (11*i)), "0x%8x", sample1[i]); // � ����� ������������� ����������� \0, ���� �� � ��������
        // "0x%8x\0" �������, �� 12� ����� ���������� �� ��� ���� \0 ������� �� ����� ��������������� ������� ��������� ������
    }
    // �������� �����. ���������� ���� ���������� �� �������. 
    for (int i = 0; i < 8; i++) {
        puts(field + 11*i);
    }
    puts("");
    // ����� ����������� � ������� � ���������� ����, ������ ���� ���� ���������� ������ � � �. ������ ����� ������� �������.
    for (int i = 0; i < 11*8; i++) {
        if (*(field+i) == ' ') *(field+i) = '0';
        if ((*(field+i) > 'a'-1)&&(*(field+i) < 'g')) *(field + i) += 'A'-'a';
    }
    // �����
    for (int i = 0; i < 8; i++) {
        puts(field + 11*i);
    }
    puts(""); // ������ ���� ������ � ��������.

    */


    


    


  
}