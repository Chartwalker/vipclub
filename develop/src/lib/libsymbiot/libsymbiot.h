#include <stdio.h>
#include <stdlib.h>

// maximum speed first
struct Libsymbiot_Data{
    int data_size;
    char *data_p;
    char *next_p;
    char *prev_p;
    char *conf_p;
};
typedef struct Libsymbiot_Data Libsymbiot_Data_t;

// flexibility ans safety first
struct Libsymbiot_Conf{
    int conf_size;
    FILE *log_fp;
    FILE *conf_fp;
    char *xup_p;
    char *xdn_p;
    char *yup_p;
    char *ydn_p;
    char *zup_p;
    char *zdn_p;
    char *tup_p;
    char *tdn_p;
    char *log_p;
    char *auth_p;
    int data_inc;
    int log_inc;
    int conf_inc;
    int x_inc;
    int y_inc;
    int z_inc;
    int t_inc;
};


typedef struct Libsymbiot_Conf Libsymbiot_Conf_t;

int tb_libsymbiot (Libsymbiot_Data_t *);