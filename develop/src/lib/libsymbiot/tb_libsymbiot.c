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
	return 0;
}

int tb_libsymbiot_dot( Libsymbiot_Conf_t *Dot_p){
	FILE *dot_fp;
	if (Dot_p) {
		if (Dot_p->dot_fp){
			dot_fp=Dot_p->dot_fp;
			fprintf(dot_fp,"digraph structs {\n");
			fprintf(dot_fp,"node [shape=record];\n");
			fprintf(dot_fp,"\tstruct1 [shape=record,label=\"");
			fprintf(dot_fp,"<f0>%%p(Root_p)=\\n%p|",Dot_p);
			fprintf(dot_fp,"<f1>%%p(Data_p)=\\n%p|",Dot_p->Data_p);
			fprintf(dot_fp,"<f2>%%p(Dot_p)=\\n%p|",Dot_p->Dot_p);
			fprintf(dot_fp,"\"];");
			
			fprintf(dot_fp,"\n}\n");
		}	
		else {
			fprintf(stderr,"unable to open %%p(dot_fp)=%p",Dot_p->dot_fp);
		}
	}
	else	{
		fprintf(stderr,"unable to open %%p(Dot_p)=%p",Dot_p);
	}	
	return 0;
}	

int main(int argc, char **arv){

	FILE *debug_fp;
	FILE *dot_fp;
	static int *retval_i;
	static char *retval_s;
	Buffer_t Buffer;
	char hexbuf[PAGE_SIZE];

	const char *TBLOG = "tb_libsymbiot.log";
	const char *TBDOT = "tb_libsymbiot1.dot";
	// emulating the root tree of the system
	static Libsymbiot_Data_t *Root_Data_p;
	static Libsymbiot_Conf_t *Root_Dot_p;
	static Libsymbiot_Conf_t *Root_Conf_p;
	// static reference
	static Libsymbiot_Data_t Root_Data;
	static Libsymbiot_Conf_t Root_Dot;
	static Libsymbiot_Conf_t Root_Conf;
	// emulating the debug tree of the system
	static Libsymbiot_Data_t *Debug_Data_p;
	static Libsymbiot_Conf_t *Debug_Dot_p;
	static Libsymbiot_Conf_t *Debug_Conf_p;
	// static reference
	static Libsymbiot_Data_t Debug_Data;
	static Libsymbiot_Conf_t Debug_Dot;
	static Libsymbiot_Conf_t Debug_Conf;

	// linking the structures
	Root_Data_p=&Root_Data;
	Root_Conf_p=&Root_Conf;
	Root_Conf_p=&Root_Dot;
	Debug_Data_p=&Debug_Data;
	Debug_Conf_p=&Debug_Conf;
	Debug_Conf_p=&Debug_Dot;
	Buffer.buf_p=hexbuf;
	
	 if ((debug_fp=fopen(TBLOG,"w+"))==NULL){
		fprintf(stderr,"main_tb: unable to open %s\n",TBLOG);
    }
    else {
		Root_Conf_p->log_fp=debug_fp;
		fprintf(Root_Conf_p->log_fp,"main_tb: env: %%p(Root_Conf_p)=%p  %%p(Debug_Conf_p)=%p\n",Root_Conf_p, Debug_Conf_p);	
		fprintf(Root_Conf_p->log_fp,"main_tb: env: PAGE_SIZE=%u, CHAR_BIT=%u\n", PAGE_SIZE, CHAR_BIT);	
		fprintf(Root_Conf_p->log_fp,"main_tb: env: %%p(Root_p)=%p sz=%i\n",Root_Conf_p, sizeof(*Root_Conf_p));
	}	
	// create dot for navigation
	 if ((dot_fp=fopen(TBDOT,"w+"))==NULL){
		fprintf(stderr,"main_tb: unable to open %s\n",TBDOT);
    }
    else {
		Root_Conf_p->dot_fp=dot_fp;
		fprintf(Root_Conf_p->log_fp,"main_tb: dot: dot_file=%s enabled",TBDOT);	
	}	
	// copy root für debugging
    if ((Debug_Conf_p=libsymbiot_conf_new(Root_Conf_p)) == NULL) {
		fprintf(stderr,"main_tb: unable to create Debug_Conf_p at %p\n",Debug_Conf_p);	
	} 
	else {
		Debug_Conf_p->log_fp=Root_Conf_p->log_fp;
		Debug_Conf_p->dot_fp=Root_Conf_p->dot_fp;
		fprintf(Debug_Conf_p->log_fp,"main_tb: logtest from Debug_Conf_p at %p\n",Debug_Conf_p);	
		tb_libsymbiot_dot( Debug_Conf_p);
//		fprintf(Debug_Conf_p->dot_fp,"\tstruct1 [share=record,label=\"<f0>| %%p(Root_p)=\n%p|<f1>%%p(Config_p)=\n%p | %%p(Dot_p)=\n%p\"];",);
	}			
	fprintf(Root_Conf_p->log_fp,"main_tb: try to create intelhex from %%p(Root_p)=%p\n",Root_Conf_p);
	libsymbiot_intelhex(Root_Conf_p);
	fclose (debug_fp);
	fclose (dot_fp);
    return 0;
}
