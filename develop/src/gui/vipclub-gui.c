#include "vipclub-gui.h"
#include <gtk/gtk.h>
#include <libsymbiot/libsymbiot.h>

static Main_Init_t Main_Init;
static  Main_Init_t *Main_Init_p;
static gboolean timeout_callback(gpointer data);
GTimer *Main_Timer;
GDate *Main_Date;
// modulo 1000000 !!

struct tm Main_Time;

gulong loops;
// gdouble g_main_timer_elapsed ();

GString *Dbg_I(Main_Init_t *Main_Init){
	static GString *Dbg_Temp;
	char *Dbg_s;
	Main_Init_p->Dbg_D = g_string_new((const char*) "  dbg(dbg_i): ");
	Dbg_s = Main_Init_p->Dbg_D->str;
	Dbg_Temp = Main_Init_p->Dbg_M;
	if (Dbg_Temp->str){ 
		if (Main_Init_p->dbg_i > 0){ 
			for (int j=0;j<Main_Init_p->dbg_i && j<78 ;j++){
				g_string_insert_c (Dbg_Temp,0,0x20);
			}	
		}	
		g_string_printf(Dbg_Temp,"%s%s",Dbg_s,Main_Init_p->Dbg_M->str);
		 
	}	
	return 	Dbg_Temp;
}	

int main_init(Main_Init_t *Main_Init_p){
	gint retval_i=0;
	// please use only theadsafe functions here - only use g_string_new instead g_string_sprintf
	// GString *Temp_gsp; 	// temp string-buffer
	// gint * temp_i;			// return value
	char *Dbg_s;
	Main_Init_p->Dbg_D = g_string_new((const char*) "  dbg(main_init): ");
	Dbg_s = Main_Init_p->Dbg_D->str;
	Main_Init_p->Asc_Time = g_string_new((const char*) "");

	g_string_append(Main_Init_p->Asc_Time,asctime(localtime (&(Main_Init_p->rawtime))));
	g_fprintf(Main_Init_p->dbg_fp,"\n%sapp-time=%s",Dbg_s,Main_Init_p->Asc_Time->str);
	Dbg_s = Main_Init_p->Dbg_D->str;
	// == directory config dir	
	// cwd at calling
	Main_Init_p->Dir_Cwd_gsp = g_string_new((const char*) get_current_dir_name());
	//
	// users config dir - init GString *Dir_Config_gsp;	
	Main_Init_p->Dir_Config_gsp = g_string_new((const char*) g_get_user_config_dir ());
	g_fprintf(Main_Init_p->dbg_fp,"\n%sconfig_dir=%s",Dbg_s,Main_Init_p->Dir_Config_gsp->str);
	//
	// users home dir - init GString *Dir_Home_gsp;
	Main_Init_p->Dir_Home_gsp=g_string_new((const char*) g_get_home_dir());
	g_fprintf(Main_Init_p->dbg_fp,"\n%shome_dir=%s",Dbg_s,Main_Init_p->Dir_Home_gsp->str);
	//
	// == runtime config
	// logical app - init GString *App_Name_gsp;
	//
	g_set_application_name(TSC_PRJG_VERSION_S);
	//
	Main_Init_p->App_Name_gsp=g_string_new((const char*) g_get_application_name());
	g_fprintf(Main_Init_p->dbg_fp,"\n%sApp_Name=%s",Dbg_s,Main_Init_p->App_Name_gsp->str);	
	//
	// physical app - init GString *App_Name_gsp;
	//
	g_set_prgname (TSC_PRJG_VERSION_S);
	//
	Main_Init_p->Prg_Name_gsp=g_string_new((const char*) g_get_prgname());
	g_fprintf(Main_Init_p->dbg_fp,"\n%sPrg_Name=%s",Dbg_s,Main_Init_p->Prg_Name_gsp->str);
	// user name - init GString *User_Name_gsp;
	Main_Init_p->User_Name_gsp=g_string_new((const char*) g_get_user_name());
	g_fprintf(Main_Init_p->dbg_fp,"\n%sUser_Name=%s",Dbg_s,Main_Init_p->User_Name_gsp->str);
	
	/*

	GString *Dir_Config_gsp;
	GString *Dir_Cwd_gsp;
	GString *Dir_Log_gsp;
	GString *Dir_Setup_gsp;
	*/
	// debug
	
	
	
	// open files
	// config-file
	// const gchar *conf_fn = "vipclub_gui.json";
	
	// const gchar *err_fn = "vipclub_gui.error";
	/*
	Temp_gsp=Main_Init_p->Dir_Config_gsp;
	g_string_append (Temp_gsp,"/");
	g_string_append (Temp_gsp,Main_Init_p->Prg_Name_gsp->str);
	g_string_append (Temp_gsp,"/");
	g_string_append (Temp_gsp,Main_Init_p->User_Name_gsp->str);
	g_string_append (Temp_gsp,"/");
	g_string_append (Temp_gsp,err_fn);
	g_printf("\n\terr_fn=%s",Temp_gsp->str);	
	*/
// FILE *libsymbiot_file_open(FILE *err_fp, FILE *log_fp, const char* file_fn, const char *file_fm);


	// redirect stderr
	// const gchar *err_gfn = "vipclub_gui.error";
	if ((Main_Init_p->err_fp=libsymbiot_file_open(Main_Init_p,err_fn,"w+")) != NULL) {
		g_fprintf(Main_Init_p->dbg_fp,"\n%sstart error loging - successfull",Dbg_s);
		// redirect stdout
		// dekl: const gchar *dbg_fn = "vipclub_gui_dbg.txt";
		if ((Main_Init_p->dbg_fp=libsymbiot_file_open(Main_Init_p,dbg_fn,"w+")) != NULL) {
			g_fprintf(Main_Init_p->dbg_fp,"\n%sstart debug loging - successfull",Dbg_s); 
		}
		else {fprintf(Main_Init_p->err_fp,"\n%sunable to start debug loging - Error!",Dbg_s);
		};
	}		
	else {fprintf(Main_Init_p->err_fp,"\n%sunable to start error loging - Error!",Dbg_s);
	};
	
    // Main_Init_p->conf_gfp=g_file_new_for_path(Temp_gsp->str);
	// test configfile
	// file output stream
	// Main_Init_p->conf_fos = g_file_replace(Main_Init_p->conf_gfp,0,0,G_FILE_CREATE_PRIVATE,0,0);
	// data output stream
	// Main_Init_p->conf_dos = g_data_output_stream_new (Main_Init_p->conf_fos);
	// retval_b=g_data_output_stream_put_string (Main_Init_p->conf_dos,"Hello world!\n",0,0);
	
	
	// err_gfp =  g_file_new_for_path
	//	const gchar *dbg_gfn = "vipclub_gui_dbg.txt";
	//	const gchar *dot_gfn = "vipclub_gui_log.txt";
	//	const gchar *dot_gfn = "vipclub_gui.dot";
	//	const gchar *html_gfn = "vipclub_gui.html";

	//GFile *dbg_gfp;		// debug-file
	//GFile *log_gfp;		// regular log
	//GFile *dot_gfp;		// dot-file
	//GFile *html_gfp;		// html-file
	//GFile *conf_gfp;		// config-file
	//err_gfp=g_file_new_for_path (vipclub_gui.error);
	// g_set_prgname(TSC_Proj);
	// g_set_application_name(TSC_PrettyProj);
    return retval_i;
}

int main (int argc, char *argv[]){

	Main_Init_p=&Main_Init;
	// only for initial loging
	Main_Init_p->err_fp=stderr;
	Main_Init_p->dbg_fp=stdout;
	Main_Init_p->cb_fp = stdout;
	char *Dbg_s;
	Main_Timer = g_timer_new();
	g_timer_start(Main_Timer);
	Main_Date=g_date_new();
	Main_Init_p->uptime = time(NULL);
	
	Main_Init_p->Dbg_D = g_string_new((const char*) "  dbg(main): ");
	Dbg_s = Main_Init_p->Dbg_D->str;
	
	// store workdir before fopen()
	Main_Init_p->Dir_Prg_gsp = g_string_new((const char*) get_current_dir_name());
	g_fprintf(Main_Init_p->dbg_fp,"\n%sstarting gui at %s",Dbg_s,Main_Init_p->Dir_Prg_gsp->str);
	if 	(Main_Init_p == &Main_Init) {
		g_fprintf(Main_Init_p->dbg_fp,"\n%sMain_init_p(@%p)->&Main_init(@%p) initialized - successfull",Dbg_s,Main_Init_p,&Main_Init ); 
	}	else {
		g_fprintf(Main_Init_p->err_fp,"\n%spointer Main_init_p(@%p)->&Main_init(@%p) may uninitialized - Warning!",Dbg_s,Main_Init_p,&Main_Init ); 
	}	
	if 	(Main_Init_p->err_fp == stderr) {
		g_fprintf(Main_Init_p->dbg_fp,"\n%sdbg_fp(@%p)->stderr(@%p) at initial setup - successfull",Dbg_s,Main_Init_p->err_fp,stderr);
	} else {
		g_fprintf(Main_Init_p->err_fp,"\n%spointer err_fp(@%p)->stderr(@%p) may uninitialized! - Warning!",Dbg_s,Main_Init_p->err_fp,stderr);
	}	
	if 	(Main_Init_p->dbg_fp == stdout) {
		g_fprintf(Main_Init_p->dbg_fp,"\n%sdbg_fp(@%p)->stdout(@%p) at initial setup - successfull",Dbg_s,Main_Init_p->dbg_fp,stdout);
	} else {
		g_fprintf(Main_Init_p->err_fp,"\n%spointer dbg_fp(@%p)->stdout(@%p) may uninitialized! - Warning!",Dbg_s,Main_Init_p->dbg_fp,stdout);
	}	
	g_fprintf(Main_Init_p->dbg_fp,"\n%scalling main init at (@%p)",Dbg_s,Main_Init_p);
	main_init(Main_Init_p);
	g_printf("\n%scalling main_init - successfull",Dbg_s);
//    err_fp = stderr;
//    fprintf(stdout,"\ndir_home=%s dir_temp=%s dir_proj=%s",g_get_home,dir_temp,dir_proj);
  //  fprintf(stdout,"\nprgname=%s application=%s",g_get_prgname,g_get_application_name);
  //  fprintf(stdout,"\nuser_name=%s real_name=%s",g_get_user_name,g_get_real_name);
    
    /*
	if (err_fp(libsymbiot_file_open(stderr,NULL,GUI_ERR,"w+") != NULL) then {
		if (dbg_fp(libsymbiot_file_open(err_fp,err_fp,GUI_DBG,"w+") != NULL then {
			fprint(dbg_fp,"\nstart debug loging successfully"); };
		else {fprintf(err_fp,"\nunable to start debug loging");
		};			
	else {fprintf(err_fp,"\nunable to start error loging  ");
	
	}
	if (dbg_fp(libsymbiot_file_open(stderr,NULL,GUI_DBG,"w+"));}
	if (err_fp(libsymbiot_file_open(stderr,NULL,GUI_ERR,"w+"));}
    */
    
    gtk_init (&argc, &argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder,"vipclub-gui.xml", NULL);
	g_timeout_add (1000, (timeout_callback), Main_Init_p);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
 
    g_object_unref(builder);
    gtk_widget_show (window);
    gtk_main ();
    return 0;
}

// main destroy callback
void on_window_main_destroy(void){
	char *Dbg_s ="  dbg(cb_mn_destroy): ";
	g_fprintf(Main_Init_p->cb_fp,"\n%s- bye\n",Dbg_s);
	fflush(Main_Init_p->cb_fp);
    gtk_main_quit();
}

// main destroy callback
void on_mnm_file_quit(void){
	char *Dbg_s = "  dbg(cb_mnm_file_quit): ";
	g_fprintf(Main_Init_p->cb_fp,"\n%s- bye\n",Dbg_s);
	fflush(Main_Init_p->cb_fp);
    gtk_main_quit();
}

// main menu file new callback
void on_mnm_file_new(void){
	char *Dbg_s = "  dbg(cb_mnm_file_new): ";
	g_fprintf(Main_Init_p->cb_fp,"\n%s",Dbg_s);
	fflush(Main_Init_p->cb_fp);
}

// main menu view config setup
void on_mnm_view_conf_setup(void){
	char *Dbg_s = "  dbg(cb_mnm_view_conf_setup): ";
	g_fprintf(Main_Init_p->cb_fp,"\n%s",Dbg_s);
	fflush(Main_Init_p->cb_fp);
}

// main menu file config save
void on_mnm_view_conf_save(void){
	char *Dbg_s = "  dbg(cb_mnm_view_conf_save): ";
	g_fprintf(Main_Init_p->cb_fp,"\n%s",Dbg_s);
	fflush(Main_Init_p->cb_fp);
}

int schedule_queue_in(int priority, int slot,int (cb_schedule)(int)){
    gint retval_i=0;
	// static int i,j;
	// int priority_max = 100;
	// int max_slot_max = 100;
	// for (if i >=priority_max i=0; ;if ii<priority_max then ;i++
    return retval_i;
}

int timeout_callback(gpointer data){
	GTimeZone *tz =g_time_zone_new_local ();
	GDateTime *dt=g_date_time_new_now(tz);
	g_time_zone_unref(tz);
	gchar* datetime_c =g_date_time_format (dt,"%c");
	g_date_time_unref (dt);
	g_fprintf(Main_Init_p->cb_fp,"\n%s",datetime_c);
	fflush(Main_Init_p->cb_fp);
	return TRUE;
}	