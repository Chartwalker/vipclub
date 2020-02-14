// 13.2.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

// Main Constructor
Libsymbiot_t *libsymbiot_new(void);
// Main Destruktor
int libsymbiot_free( Libsymbiot_t *data_p);

// insert object into the queue
Libsymbiot_t *libsymbiot_object_ins(Libsymbiot_t *Data_p);
// remove object from the queue
Libsymbiot_t *libsymbiot_object_del(Libsymbiot_t *Data_p);

int libsymbiot_free( Libsymbiot_t *data_p);


    if (data_p) {
	fprintf(data_p->tb_fp,"sizeof(data_p->=%p)=%i\n",data_p, sizeof(data_p));
	fprintf(data_p->tb_fp,"sizeof(data_p.tb_fp->=%p)=%i\n",data_p->tb_fp, sizeof(data_p->tb_fp));
	fprintf(data_p->tb_fp,"sizeof(&data_p=%p)=%i\n",&data_p->tb_fp,sizeof(&data_p->tb_fp));
    } 
    else 
    {
	fprintf(stderr,"\nerror: p->=%p (nil)");
    };
    
    return 0;
}
