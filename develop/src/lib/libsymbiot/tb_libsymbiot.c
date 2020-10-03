// 13.2.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

int tb_libsymbiot_data( Libsymbiot_Data_t *Data_p){
	Libsymbiot_Conf_t *Conf_p;
	if (Data_p) {
        Conf_p=(Libsymbiot_Conf_t *)Data_p->Conf_p;
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

	FILE *debug_fp;
	const char *TBLOG = "tb_libsymbiot.log";
	// emulating the rest of the system
	static Libsymbiot_Data_t *Root_Data_p;
	static Libsymbiot_Conf_t *Root_Conf_p;
	static Libsymbiot_Data_t *Debug_Data_p;
	static Libsymbiot_Conf_t *Debug_Conf_p;
	// static reference
	static Libsymbiot_Data_t Root_Data;
	static Libsymbiot_Conf_t Root_Conf;
	// linking only the root structure
	Root_Data_p=&Root_Data;
	Root_Conf_p=&Root_Conf;
	
	 if ((debug_fp=fopen(TBLOG,"w+"))==NULL){
		fprintf(stderr,"main_tb: unable to open %s\n",TBLOG);
    }
    else {
		Root_Conf_p->log_fp=debug_fp;
		fprintf(Root_Conf_p->log_fp,"main_tb: env: %%p(Root_Conf_p)=%p  %%p(Debug_Conf_p)=%p\n",Root_Conf_p, Debug_Conf_p);	
		fprintf(Root_Conf_p->log_fp,"main_tb: env: PAGE_SIZE=%u, CHAR_BIT=%u\n",Root_Conf_p, PAGE_SIZE, CHAR_BIT);	
		fprintf(Root_Conf_p->log_fp,"main_tb: env: %%p(Root_p)=%p sz=%i\n",Root_Conf_p, sizeof(*Root_Conf_p));
	}	
	
    if ((Debug_Conf_p=libsymbiot_conf_new(Root_Conf_p)) == NULL) {
		fprintf(stderr,"main_tb: unable to create Debug_Conf_p at %p\n",Debug_Conf_p);	
	} else {
		Debug_Conf_p->log_fp=Root_Conf_p->log_fp;
		fprintf(stderr,"main_tb: create Debug_Conf_p at %p\n",Debug_Conf_p);	
	}			
	fclose (debug_fp);
    return 0;
}
