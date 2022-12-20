#include <stdio.h>
#include <stdlib.h>

char *hexidecimal(int sample[8]) {
    char *field = malloc(sizeof(char)*11*8);
    for (int i = 0; i < 8; i++) {
        sprintf((field + 11*i), "0x%8x", sample[i]);
    }
    // дл€ красоты
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
        for (int j = 2; j < 11; j++) { // этот код не работает
            if ((*(field + j + 11 * i) == 'A')&& // если поле ј
            (*(adj_b(field + j + 11 * i)) == 'B')&& // и р€дом с ним Ѕ
            (*(adj_b(adj_b(field + j + 11 * i))) == 'B')&& // и р€дом с ним Ѕ
            (*(adj_a(adj_b(adj_b(field + j + 11 * i)))) == 'A')) k++; // и р€дом с ним ј  то к++
        }
    }
    free(field);
    return k/2;
}

int main () {

    /* TODO 
    
    не работает определение соседей.
    
    в остальном алгоритм пон€тен и работает
    
    */
    
    int sample1[8] = {-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    
    int sample2[8] = {-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};

    printf("%d\n", abba(sample1));
    printf("%d\n", abba(sample2));



    /* процесс написани€ первода в base16

    int sample1[8] ={-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    // были введены числа в дес€тичном формате
    for (int i = 0; i < 8; i++) {
        printf("%x\n",sample1[i]);
    } // вот так они должны выгл€деть в hex, только —и обрезал незначащие нули. –азберусь с этим потом.
    puts("");
    // создаю поле 11х8 и забиваю туда hex. явно указываю длину строки.
    char *field = malloc(sizeof(char)*11*8);
    for (int i = 0; i < 8; i++) {
        sprintf((field + (11*i)), "0x%8x", sample1[i]); // в конце автоматически добавл€етс€ \0, если бы € добвал€л
        // "0x%8x\0" вручную, то 12м битом добавл€лс€ бы еще один \0 который бы потом перезаписывалс€ началом следующей строки
    }
    // провер€ю вывод. Ќезначащие нули заменились на пробелы. 
    for (int i = 0; i < 8; i++) {
        puts(field + 11*i);
    }
    puts("");
    // можно пробежатьс€ с заменой и расставить нули, пускай даже мен€ интересуют только ј и ¬. «аодно буквы большие сделать.
    for (int i = 0; i < 11*8; i++) {
        if (*(field+i) == ' ') *(field+i) = '0';
        if ((*(field+i) > 'a'-1)&&(*(field+i) < 'g')) *(field + i) += 'A'-'a';
    }
    // вывод
    for (int i = 0; i < 8; i++) {
        puts(field + 11*i);
    }
    puts(""); // теперь поле готово к подсчету.

    */


    


    


  
}