// 13.2.2020 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

int tb_libsymbiot( Libsymbiot_t *data_p){
    if (data_p) {
<------>fprintf(data_p->tb_fp,"sizeof(data_p->=%p)=%i\n",data_p, sizeof(data_p));
<------>fprintf(data_p->tb_fp,"sizeof(data_p.tb_fp->=%p)=%i\n",data_p->tb_fp, sizeof(data_p->tb_fp));
<------>fprintf(data_p->tb_fp,"sizeof(&data_p=%p)=%i\n",&data_p->tb_fp,sizeof(&data_p->tb_fp));
    }.
    else.
    {
<------>fprintf(stderr,"\nerror: p->=%p (nil)");
    };
....
    return 0;
}


int main(int argc, char **arv){

FILE *test_fp;

const char *TBLOG = "tb_libsymbiot.log";

Libsymbiot_t *tb_Data_p;

    Libsymbiot_t Tb_Data;
    tb_Data_p=&Tb_Data;

    if ((test_fp=fopen(TBLOG,"w+"))==NULL){
	fprintf(stderr,"unable to open %s",TBLOG);
    }
    else {
	tb_Data_p->tb_fp=test_fp;
        tb_libsymbiot(tb_Data_p);
	fclose(tb_Data_p->tb_fp);
    }	
    return 0;
}
