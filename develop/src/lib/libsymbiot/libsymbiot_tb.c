// 04.04.2021 MIT C. by Tarnsat (ukn)
#include <libsymbiot/libsymbiot.h>

int tb_libsymbiot_data(Libsymbiot_Data_t * Data_p)
{
	Libsymbiot_Conf_t *Conf_p;
	if (Data_p) {
		Conf_p = (Libsymbiot_Conf_t *) Data_p->Conf_p;
		if (Conf_p) {
			fprintf(Conf_p->log_fp, "%%p=%p Conf_p sz=%lu\n",
				Conf_p, sizeof(*Conf_p));
			fprintf(Conf_p->log_fp, "%%p=%p Data_p sz=%lu\n",
				Data_p, sizeof(*Data_p));
		} else {
			fprintf(stderr, "\nerror: Conf_p->=%p (invalid)",
				Conf_p);
		}
	} else {
		fprintf(stderr, "\nerror: Data_p p->=%p (invalig)", Data_p);
	};
	return 0;
}

int tb_libsymbiot_dot(Libsymbiot_Conf_t * Dot_p)
{
	FILE *dot_fp;
	if (Dot_p) {
		if (Dot_p->dot_fp) {
			dot_fp = Dot_p->dot_fp;
			fprintf(dot_fp, "digraph structs {\n");
			fprintf(dot_fp, "node [shape=record];\n");
			fprintf(dot_fp, "\tstruct1 [shape=record,label=\"");
			fprintf(dot_fp, "<f0>%%p(Root_p)=\\n%p|", Dot_p);
			fprintf(dot_fp, "<f1>%%p(Data_p)=\\n%p|",
				Dot_p->Data_p);
			fprintf(dot_fp, "<f2>%%p(Dot_p)=\\n%p|", Dot_p->Dot_p);
			fprintf(dot_fp, "\"];");

			fprintf(dot_fp, "\n}\n");
		} else {
			fprintf(stderr, "unable to open %%p(dot_fp)=%p",
				Dot_p->dot_fp);
		}
	} else {
		fprintf(stderr, "unable to open %%p(Dot_p)=%p", Dot_p);
	}
	return 0;
}

int main(int argc, char **arv)
{

	FILE *dbg_fp;		// debug-file
	FILE *log_fp;		// regular log  
	FILE *dot_fp;		//      dot-file
	FILE *html_fp;		// html-file
	FILE *conf_fp;		// config-file

	// static int *retval_i;
	// static char *retval_s;
	// Buffer_t Buffer;
	// char hexbuf[PAGE_SIZE];

	const char *TBDBG = "tb_libsymbiot_dbg.txt";
	const char *TBLOG = "tb_libsymbiot_log.txt";
	const char *TBDOT = "tb_libsymbiot.dot";
	const char *TBHTML = "tb_libsymbiot.html";
	const char *TBCONF = "tb_libsymbiot.json";

	// emulating the root tree of the system
	// static Libsymbiot_Data_t *Root_Data_p;
	// static Libsymbiot_Conf_t *Root_Dot_p;
	static Libsymbiot_Conf_t *Root_Conf_p;

	// static reference
	// static Libsymbiot_Data_t Root_Data;
	// static Libsymbiot_Conf_t Root_Dot;
	static Libsymbiot_Conf_t Root_Conf;
	// emulating the debug tree of the system
	// static Libsymbiot_Data_t *Debug_Data_p;
	// static Libsymbiot_Conf_t *Debug_Dot_p;
	static Libsymbiot_Conf_t *Debug_Conf_p;
	// static reference
	// static Libsymbiot_Data_t Debug_Data;
	// static Libsymbiot_Conf_t Debug_Dot;
	static Libsymbiot_Conf_t Debug_Conf;

	// linking the structures
	// Root_Data_p= &Root_Data;
	Root_Conf_p = &Root_Conf;
	// Root_Dot_p= &Root_Dot;
	// Debug_Data_p= &Debug_Data;
	Debug_Conf_p = &Debug_Conf;
	// Debug_Dot_p= &Debug_Dot;
	// Buffer.buf_p=hexbuf;

	// make Root_p only - copy later

	// create first dbg-file to see early if something go wrong
	if ((dbg_fp = fopen(TBDBG, "w+")) == NULL) {
		fprintf(stderr, "tb_main: unable to open %s\n", TBDBG);
	}
	// failed
	else {
		Root_Conf_p->dbg_fp = dbg_fp;
		debug_print("dbg_file=%s enabled\n", TBDBG);
	}
	// create log-file for regular purpose
	if ((log_fp = fopen(TBLOG, "w+")) == NULL) {
		debug_print("unable to open %s\n", TBLOG);
	} else {
		Root_Conf_p->log_fp = log_fp;
		debug_print("log_file=%s enabled\n", TBLOG);
	}
	// create dot-file for html use
	if ((dot_fp = fopen(TBDOT, "w+")) == NULL) {
		debug_print("unable to open %s\n", TBDOT);
	} else {
		Root_Conf_p->dot_fp = dot_fp;
		debug_print("dot_file=%s enabled\n", TBDOT);
	}
	// create html-file for html browsing
	if ((html_fp = fopen(TBHTML, "w+")) == NULL) {
		debug_print("unable to open %s\n", TBHTML);
	} else {
		Root_Conf_p->html_fp = html_fp;
		debug_print("html_file=%s enabled\n", TBHTML);
	}
	// create conf-file for json browsing
	if ((conf_fp = fopen(TBCONF, "w+")) == NULL) {
		debug_print("unable to open %s\n", TBCONF);
	} else {
		Root_Conf_p->conf_fp = conf_fp;
		debug_print("conf_file=%s enabled\n", TBCONF);
	}

	//      fprintf(Root_Conf_p->log_fp, "tb_main: log(root)  %%p(Root_Conf_p)=%p sz=%i\n",Root_Conf_p,sizeof(*Root_Conf_p)); 
	//      fprintf(Root_Conf_p->log_fp,"tb_main: env: PAGE_SIZE=%u, CHAR_BIT=%u\n", PAGE_SIZE, CHAR_BIT);  
	//}     

	// create dot-grafic for html-use
	if ((dot_fp = fopen(TBDOT, "w+")) == NULL) {
		fprintf(stderr, "tb_main: unable to open %s\n", TBDOT);
	} else {
		Root_Conf_p->dot_fp = dot_fp;
		Debug_Conf_p->dot_fp = dot_fp;
		fprintf(Root_Conf_p->log_fp, "tb_main: dot_file=%s enabled\n",
			TBDOT);
	}
	// copy root for debugging
	if ((Debug_Conf_p = libsymbiot_conf_new(Root_Conf_p)) == NULL) {
		fprintf(stderr,
			"tb_main: unable to create Debug_Conf_p at %p\n",
			Debug_Conf_p);
	} else {
		Debug_Conf_p->log_fp = Root_Conf_p->log_fp;
		Debug_Conf_p->dot_fp = Root_Conf_p->dot_fp;
		fprintf(Debug_Conf_p->log_fp,
			"\ntb_main: try new(Debug_Conf_p) at %p\n",
			Debug_Conf_p);
		tb_libsymbiot_dot(Debug_Conf_p);
		fprintf(Debug_Conf_p->dot_fp,
			"\tstruct1 [share=record,label=\"<f0>| %%p(Root_p)=\n%p|<f1>%%p(Config_p)=\n%p];",
			Root_Conf_p, Debug_Conf_p);
	}

	fprintf(Root_Conf_p->log_fp,
		"\ntb_main: try intelhex(Root_Conf_p)=%p\n", Root_Conf_p);
	libsymbiot_intelhex(Root_Conf_p);
	fclose(log_fp);
	fclose(dot_fp);
	fclose(dbg_fp);
//      fclose (html_fp);
	return 0;
}
