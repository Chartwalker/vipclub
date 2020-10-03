// 13.2.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

// Config Constructor
Libsymbiot_Conf_t *libsymbiot_conf_new(Libsymbiot_Conf_t *Parent_p){
   // if parent == NULL, then media offline oder Debug 
    static Libsymbiot_Conf_t *Child_p;
	static char *mem_p;
	
    mem_p=malloc(sizeof(Libsymbiot_Conf_t));
	if(mem_p == NULL){
		fprintf(stderr,"conf_new: unable to get memory at %p",mem_p);
		return NULL;
    } else {
		Child_p= (Libsymbiot_Conf_t *) mem_p;
		Child_p->Parent_p = (Libsymbiot_Conf_t *) Parent_p;
		Child_p->log_fp = (Libsymbiot_Conf_t *) Parent_p->log_fp;
		fprintf(Child_p->log_fp,"conf_new: %%p(Parent_p)=%p sz=%i\n",Parent_p, sizeof(*Parent_p));
		fprintf(Child_p->log_fp,"conf_new: %%p(Child_p)=%p sz=%i\n",Child_p, sizeof(*Child_p));
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
			fprintf(Conf_p->log_fp,"conf_free: %%p(Conf_p)=%p  sz=%i\n",Conf_p, sizeof(*Conf_p));
	    }	
		else {
			fprintf(stderr,"conf_free: unable to get log_fp at %p\n",Conf_p);
		}
		// step uo	
		Parent_p=(Libsymbiot_Conf_t *)Conf_p->Parent_p;
        if (Parent_p) {
			fprintf(Parent_p->log_fp,"conf_free: %%p(Parent Conf_p)=%p  sz=%i\n",Parent_p, sizeof(*Parent_p));
		}
		else
		{    
			fprintf(stderr,"conf_free: error: %%p(Parent Conf_p)=%p (invalid)\n",Parent_p);
		}
    } 
    else 
    {
	fprintf(stderr,"conf_free: error: %%P(Parent Conf_p)=%p (invalid)\n",Conf_p);
    };
    
    return Parent_p;
}
