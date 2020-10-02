// 13.2.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

// Main Constructor
Libsymbiot_Data_t *libsymbiot_data_new(void);
// Main Destruktor
int libsymbiot_data_free( Libsymbiot_Data_t *Data_p);
// insert object into the queue
Libsymbiot_Data_t *libsymbiot_data_object_ins(Libsymbiot_Data_t *Data_p);
// remove object from the queue
Libsymbiot_Data_t *libsymbiot_data_object_del(Libsymbiot_Data_t *Data_p);

// Conf Constructor
Libsymbiot_Conf_t *libsymbiot_conf_new(void);
// Conf Destruktor
int libsymbiot_conf_free( Libsymbiot_Conf_t *Conf_p);

int libsymbiot_data_free( Libsymbiot_Data_t *Data_p){

	Libsymbiot_Conf_t *Conf_p;

    if (Data_p) {
        Conf_p=(Libsymbiot_Conf_t *)Data_p->conf_p;
        if (Conf_p) {
	    fprintf(Conf_p->log_fp,"%%p=%p Conf_p sz=%i\n",Conf_p, sizeof(*Conf_p));
	    fprintf(Conf_p->log_fp,"%%p=%p Data_p sz=%i\n",Data_p, sizeof(*Data_p));
	}
	else
	{    
	    fprintf(stderr,"\nerror: Conf_p->=%p (invalid)",Conf_p);
	}
    } 
    else 
    {
	fprintf(stderr,"\nerror: Data_p p->=%p (invalig)",Data_p);
    };
    
    return 0;
}
