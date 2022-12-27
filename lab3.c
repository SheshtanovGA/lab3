#include <stdio.h>
#include <stdlib.h>

char *hexidecimal(int sample[8]) {
    char *field = malloc(sizeof(char)*11*8);
    for (int i = 0; i < 8; i++) {
        sprintf((field + 11*i), "0x%8x", sample[i]);
    }
    // для красоты
    for (int i = 0; i < 11*8; i++) {
        if (*(field+i) == ' ') *(field+i) = '0';
        if ((*(field+i) > 'a'-1)&&(*(field+i) < 'g')) *(field + i) += 'A'-'a';
    }
    return field;
}



int abba(int sample[8]) {
    int count = 0;
    char *field = hexidecimal(sample);
    //for (int i = 0; i < 8; i++) printf("%s\n",field + i*11);
    for (int i = 0; i < 8; i++) {
        for (int j = 2; j < 11; j++) {
            if (*(field+j+i*11) == 'A') {
                if (*(field+(j+1)+(i)*11) == 'B') { //1 j+ 
                    if (*(field+(j+2)+(i)*11) == 'B') { //2 j+
                        if (*(field+(j+3)+(i)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j+2)+(i+1)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j+2)+(i-1)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                    if (*(field+(j+1)+(i+1)*11) == 'B') { //2 i+
                        if (*(field+(j+2)+(i+1)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j+1)+(i+2)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j)+(i+1)*11) == 'A') { //3 j-
                            count++;
                        }
                    }
                    if (*(field+(j+1)+(i-1)*11) == 'B') { //2 i-
                        if (*(field+(j+2)+(i-1)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j)+(i-1)*11) == 'A') { //3 j-
                            count++;
                        }
                        if (*(field+(j+1)+(i-2)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                }
                if (*(field+(j)+(i+1)*11) == 'B') { //1 i+
                    if (*(field+(j+1)+(i+1)*11) == 'B') { //2 j+
                        if (*(field+(j+2)+(i+1)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j+1)+(i+2)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j+1)+(i)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                    if (*(field+(j)+(i+2)*11) == 'B') { //2 i+
                        if (*(field+(j+1)+(i+2)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j)+(i+3)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j-1)+(i+2)*11) == 'A') { //3 j-
                            count++;
                        }
                    }
                    if (*(field+(j-1)+(i+1)*11) == 'B') { //2 j-
                        if (*(field+(j-1)+(i+2)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j-2)+(i+1)*11) == 'A') { //3 j-
                            count++;
                        }
                        if (*(field+(j-1)+(i)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                }
                if (*(field+(j-1)+(i)*11) == 'B') { //1 j-
                    if (*(field+(j-1)+(i+1)*11) == 'B') { //2 i+
                        if (*(field+(j)+(i+1)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j-1)+(i+2)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j-2)+(i+1)*11) == 'A') { //3 j-
                            count++;
                        }
                    }
                    if (*(field+(j-2)+(i)*11) == 'B') { //2 j-
                        if (*(field+(j-2)+(i+1)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j-3)+(i)*11) == 'A') { //3 j-
                            count++;
                        }
                        if (*(field+(j-2)+(i-1)*11) == 'B') { //i-
                            count++;
                        }
                    }
                    if (*(field+(j-1)+(i-1)*11) == 'B') { //2 i-
                        if (*(field+(j)+(i-1)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j-2)+(i-1)*11) == 'A') { //3 j-
                            count++;
                        }
                        if (*(field+(j-1)+(i-2)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                }
                if (*(field+(j)+(i-1)*11) == 'B') { //1 i-
                    if (*(field+(j+1)+(i-1)*11) == 'B') { //2 j+
                        if (*(field+(j+2)+(i-1)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j+1)+(i)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j+1)+(i-2)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                    if (*(field+(j-1)+(i-1)*11) == 'B') { //2 j-
                        if (*(field+(j-1)+(i)*11) == 'A') { //3 i+
                            count++;
                        }
                        if (*(field+(j-2)+(i-1)*11) == 'A') { //3 j-
                            count++;
                        }
                        if (*(field+(j-1)+(i-2)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                    if (*(field+(j)+(i-2)*11) == 'B') { //2 i-
                        if (*(field+(j+1)+(i-2)*11) == 'A') { //3 j+
                            count++;
                        }
                        if (*(field+(j-1)+(i-2)*11) == 'A') { //3 j-
                            count++;
                        }
                        if (*(field+(j)+(i-3)*11) == 'A') { //3 i-
                            count++;
                        }
                    }
                }
            }
        }
    }
    free(field);
    return (count % 2 == 0) ? count/2 : -99;
}

int main () {
    int sample1[8] = {-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    int sample2[8] = {-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};
    printf("ABBA 1: %d\nABBA 2: %d\n", abba(sample1), abba(sample2));

}