#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <libsymbiot/bitops.h>

// bytes per kernel page
#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

// bit per char
#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

enum Media_Type_E{
    MT_BLANK_E,
    MT_NEW_E,
    MT_MAX_SIZE_E
};

struct Buffer_S {
	char *buf_p;
	int inc;
	char *start_p;
	char *end_p;
	char sentinel;
};
	
typedef struct Buffer_S Buffer_t;

// flexibility ans safety first
struct Libsymbiot_Conf{
    int conf_size;
    void *Parent_p;
    struct Libsymbiot_Data * Data_p;
    struct Libsymbiot_Data * Dot_p;	
    Buffer_t *Buffer_p;
    FILE *log_fp;
    FILE *conf_fp;
    FILE *dot_fp;
    struct Libsymbiot_Conf *Xup_p;
    struct Libsymbiot_Conf *Xdn_p;
    struct Libsymbiot_Conf *Yup_p;
    struct Libsymbiot_Conf *Ydn_p;
    struct Libsymbiot_Conf *Zup_p;
    struct Libsymbiot_Conf *Zdn_p;
    struct Libsymbiot_Conf *Tup_p;
    struct Libsymbiot_Conf *Tdn_p;
    struct Libsymbiot_Conf *Auth_p;
    int data_inc;
    int log_inc;
    int conf_inc;
	int x_lay;
	int y_lay;
	int z_iay;	
	int t_lay;	
    int x_inc;
    int y_inc;
    int z_inc;
    int t_inc;
};

// maximum speed first
struct Libsymbiot_Data{
   int data_size;
   struct Libsymbiot_Data *Next_p;
   struct Libsymbiot_Data *Prev_p;
   struct Libsymbiot_Data *Parent_p;
   struct Libsymbiot_Conf *Conf_p;
};

typedef struct Libsymbiot_Data Libsymbiot_Data_t;
typedef struct Libsymbiot_Conf Libsymbiot_Conf_t;

Libsymbiot_Conf_t *libsymbiot_conf_new(Libsymbiot_Conf_t *Parent_p);
Libsymbiot_Conf_t *libsymbiot_conf_free( Libsymbiot_Conf_t *Parent_p);

Libsymbiot_Data_t *libsymbiot_data_new(Libsymbiot_Data_t *Parent_p);
Libsymbiot_Data_t *libsymbiot_data_free( Libsymbiot_Data_t *Parent_p);
Libsymbiot_Data_t *libsymbiot_data_object_ins(Libsymbiot_Data_t *Parent_p);
Libsymbiot_Data_t *libsymbiot_data_object_del(Libsymbiot_Data_t *Parent_p);
Libsymbiot_Conf_t *libsymbiot_intelhex(Libsymbiot_Conf_t *Parent_p);