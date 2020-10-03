#include <stdio.h>
#include <stdlib.h>

typedef unsigned long Media_Type_t;

// flexibility ans safety first
struct Libsymbiot_Conf{
    int conf_size;
	void *Parent_p;
	Media_Type_t Media_Type;
	struct Libsymbiot_Data * Data_p;
    FILE *log_fp;
    FILE *conf_fp;
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

