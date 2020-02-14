#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char *tb_data_p;
    FILE *tb_fp;
} Libsymbiot_t;

int tb_libsymbiot (Libsymbiot_t *);
