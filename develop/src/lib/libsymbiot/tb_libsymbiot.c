// 13.2.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

int tb_libsymbiot_data( Libsymbiot_Data_t *Data_p){
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

}


int main(int argc, char **arv){

FILE *test_fp;

const char *TBLOG = "tb_libsymbiot.log";

Libsymbiot_Data_t *tb_Data_p;
Libsymbiot_Conf_t *tb_Conf_p;
	
    Libsymbiot_Data_t Tb_Data;
	Libsymbiot_Conf_t Tb_Conf;
    tb_Data_p=&Tb_Data;
    tb_Conf_p=&Tb_Conf;
	
    if ((test_fp=fopen(TBLOG,"w+"))==NULL){
	fprintf(stderr,"unable to open %s",TBLOG);
    }
    else {
	tb_Conf_p->log_fp=test_fp;
	tb_Data_p->conf_p=(Libsymbiot_Conf_t *)&tb_Conf_p;
	tb_libsymbiot_data(tb_Data_p);
	fclose(tb_Conf_p->log_fp);
    }	
    return 0;
}
