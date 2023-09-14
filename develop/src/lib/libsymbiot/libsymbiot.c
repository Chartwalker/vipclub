// 3.10.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

FILE *libsymbiot_file_open(Main_Init_t *Main_Init_p, const char* file_fn, const char *file_fm){
  // create file_fp
	static FILE *temp_fp;
	char *Dbg_s;
	Main_Init_p->Dbg_D = g_string_new((const char*) "  symbiot: fopen(): ");
        Dbg_s=Main_Init_p->Dbg_D->str;
	if ((temp_fp=fopen(file_fn,file_fm))==NULL){
		if (Main_Init_p->err_fp) {fprintf(Main_Init_p->err_fp,"\n%sunable to fopen(%s,%s) - Error!\n",Dbg_s,file_fn, file_fm);}
    }
    else {
		if (Main_Init_p->log_fp) {fprintf(Main_Init_p->log_fp,"\n%sfopen(%s,%s) - successfull\n",Dbg_s,file_fn, file_fm);}
    }
	return temp_fp;
}

Libsymbiot_Conf_t *libsymbiot_intelhex(Libsymbiot_Conf_t *Parent_p){
	static char *malloc_p=NULL;
	static Buffer_t *Buffer_p;
	// const unsigned char colcount=0x10;
	// short *chr_sh;
	// const unsigned char startcode = 0x3A;
	// unsigned char bcount = 0x0;
	// unsigned short offset = 0x0;
	// unsigned char rtype = 0x0;
	// unsigned long csum;
	// int i,j;
	
	malloc_p=(char *)malloc(sizeof(PAGE_SIZE));
	
	if(malloc_p == NULL){
		fprintf(stderr,"iot_ihex: unable to get memory at %p\n",malloc_p);
		return NULL;
    } else {
			// make sure tile is really clean
			memset(malloc_p, 0, PAGE_SIZE);
			if (Parent_p){
				Buffer_p=(Buffer_t *)malloc_p;	// struct is a part of PAGE_SIZE
				Buffer_p->start_p= (char *) &Buffer_p->sentinel + 1;	
				Buffer_p->buf_p=Buffer_p->start_p;
				Buffer_p->end_p=(char *) Buffer_p + PAGE_SIZE - 1;
				Parent_p->Buffer_p=Buffer_p;
				fprintf(Parent_p->log_fp,"iot_ihex: creating %%p(Buf_p)=%p and linking to %%p(Parent_p)=%p\n",Parent_p->Buffer_p,Parent_p);	
				fprintf(Parent_p->log_fp,"iot_ihex: at %%p(Buf_p)=%p offset=%lu with start=%p end=%p size=%lu\n",Buffer_p->buf_p,(char *)Buffer_p->start_p-((char *)Parent_p->Buffer_p),Buffer_p->start_p,Buffer_p->end_p,Buffer_p->end_p-Buffer_p->start_p);	
			} else {
				fprintf(stderr,"iot_ihex: unable to linking %%p(Buf_p)=%p to Parent_p=%p\n",Buffer_p,Parent_p);
			}	
	}	
	// for(i=0;j<8;j++){[
	// for (i=0;i<sizeof(Libsymbiot_Conf_t);i++){
	
	/*  only for csum test	
	csum= 0x3+0x0+0x30+0x0+0x2+0x33+0x7A;
	csum = ~csum;
	csum = csum +1;
	csum &= 0xff;
	if (Parent_p){
		fprintf (stderr,"csum=%hx\n",csum);	
	}
	*/
	return Parent_p;
}

// Config Constructor
Libsymbiot_Conf_t *libsymbiot_conf_new(Libsymbiot_Conf_t *Parent_p){
   // if parent == NULL, then media offline oder Debug 
    static Libsymbiot_Conf_t *Child_p;
	static char *mem_p;
	// static char *out_p;
	// int i,j;
    mem_p=malloc(sizeof(Libsymbiot_Conf_t));
	if(mem_p == NULL){
		fprintf(stderr,"iot_conf_new: unable to get memory at %p",mem_p);
		return NULL;
    } else {
	    // out_p=mem_p;
		
		Child_p= (Libsymbiot_Conf_t *) mem_p;
		
		// only preinit - no deep copy
//		Child_p->conf_size=sizeof(Libsymbiot_Conf_t);
		Child_p->Parent_p = Parent_p;
		//		
//		BITSET(Child_p->Media_Type, MT_BLANK_E);
		
//		Child_p->log_fp = Parent_p->log_fp;
//		Child_p->conf_fp = Parent_p->conf_fp;
//		fprintf(Child_p->log_fp,"conf_new: %%p(Parent_p)=%p sz=%i\n",Parent_p, sizeof(*Parent_p));
//		fprintf(Child_p->log_fp,"conf_new: %%p(Child_p)=%p sz=%i\n",Child_p, sizeof(*Child_p));
//		BITSET(Child_p->Media_Type, MT_NEW_E);
        return (Libsymbiot_Conf_t *) Child_p;
    }
}

// Config Destructor
Libsymbiot_Conf_t *libsymbiot_conf_free( Libsymbiot_Conf_t *Child_p){
   // return value is parent's root-element, if NULL, then parent was offline oder debug media
	static Libsymbiot_Conf_t *Conf_p;
	static Libsymbiot_Conf_t *Parent_p;
	// copy before free
	Conf_p = Child_p;
	
    if (Conf_p) {
		if (Conf_p->log_fp){
			fprintf(Conf_p->log_fp,"iot_conf_free: %%p(Conf_p)=%p  sz=%lu\n",Conf_p, sizeof(*Conf_p));
	    }	
		else {
			fprintf(stderr,"iot_conf_free: unable to get log_fp at %p\n",Conf_p);
		}
		// step uo	
		Parent_p=(Libsymbiot_Conf_t *)Conf_p->Parent_p;
        if (Parent_p) {
			fprintf(Parent_p->log_fp,"iot_conf_free: %%p(Parent Conf_p)=%p  sz=%lu\n",Parent_p, sizeof(*Parent_p));
		}
		else
		{    
			fprintf(stderr,"iot_conf_free: error: %%p(Parent Conf_p)=%p (invalid)\n",Parent_p);
		}
    } 
    else 
    {
	fprintf(stderr,"iot_conf_free: error: %%P(Parent Conf_p)=%p (invalid)\n",Conf_p);
    };
    
    return Parent_p;
}
