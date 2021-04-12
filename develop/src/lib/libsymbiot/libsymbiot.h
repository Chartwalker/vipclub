#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libsymbiot/bitops.h>

#include <glib/gstdio.h>
#include <glib/gprintf.h>
#include <gio/gio.h>
#include <gtk/gtk.h>

#ifdef TSC_DEBUG
#define debug_print(fmt, ...) \
			do { if (TSC_DEBUG) fprintf(dbg_fp, "%s:%d:%s(): " fmt, __FILE__, \
			__LINE__, __func__, __VA_ARGS__); } while (0)
#else
#define debug_print(fmt, ...) do {} while (0)
#endif

// bytes per kernel page
#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

// bit per char
#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#ifndef LIBSYMBIOT_H
#define LIBSYMBIOT_H

enum Media_Type_E{
    MT_BLANK_E,
    MT_NEW_E,
    MT_MAX_SIZE_E
};

struct Buffer_S {
	char *buf_p;
	int inc;
	char *start_p;
	char *end_p;
	char sentinel;
};
	


typedef struct Buffer_S Buffer_t;

// flexibility ans safety first
struct Libsymbiot_Conf{
    int conf_size;
    void *Parent_p;
    struct Libsymbiot_Data * Data_p;
    struct Libsymbiot_Data * Dot_p;	
    Buffer_t *Buffer_p;
	FILE *dbg_fp;	// debug
    FILE *log_fp;		// loging normal purpose
    FILE *dot_fp;	// dot-File for html
	FILE *html_fp;	// html-file for browsing
	FILE *conf_fp;	// serialize config to have persistence on shutdown
    struct Libsymbiot_Conf *Xup_p;
    struct Libsymbiot_Conf *Xdn_p;
    struct Libsymbiot_Conf *Yup_p;
    struct Libsymbiot_Conf *Ydn_p;
    struct Libsymbiot_Conf *Zup_p;
    struct Libsymbiot_Conf *Zdn_p;
    struct Libsymbiot_Conf *Tup_p;
    struct Libsymbiot_Conf *Tdn_p;
    struct Libsymbiot_Conf *Auth_p;
    int data_inc;
    int log_inc;
    int conf_inc;
	int x_lay;
	int y_lay;
	int z_iay;	
	int t_lay;	
    int x_inc;
    int y_inc;
    int z_inc;
    int t_inc;
};

// maximum speed first
struct Libsymbiot_Data{
   int data_size;
   struct Libsymbiot_Data *Next_p;
   struct Libsymbiot_Data *Prev_p;
   struct Libsymbiot_Data *Parent_p;
   struct Libsymbiot_Conf *Conf_p;
};

typedef struct Libsymbiot_Data Libsymbiot_Data_t;
typedef struct Libsymbiot_Conf Libsymbiot_Conf_t;

Libsymbiot_Conf_t *libsymbiot_conf_new(Libsymbiot_Conf_t *Parent_p);
Libsymbiot_Conf_t *libsymbiot_conf_free( Libsymbiot_Conf_t *Parent_p);

Libsymbiot_Data_t *libsymbiot_data_new(Libsymbiot_Data_t *Parent_p);
Libsymbiot_Data_t *libsymbiot_data_free( Libsymbiot_Data_t *Parent_p);
Libsymbiot_Data_t *libsymbiot_data_object_ins(Libsymbiot_Data_t *Parent_p);
Libsymbiot_Data_t *libsymbiot_data_object_del(Libsymbiot_Data_t *Parent_p);
Libsymbiot_Conf_t *libsymbiot_intelhex(Libsymbiot_Conf_t *Parent_p);

typedef struct Main_Init{
	// the environment
	GString *Dir_Home_gsp;
	GString *Dir_Config_gsp;
	GString *Dir_Cwd_gsp;			// current working dir - do init before first calling !!
	GString *Dir_Prg_gsp;			// starting working dir - do init before first calling !!
	GString *Dir_Log_gsp;
	GString *Dir_Setup_gsp;

	GString *Dbg_D;					// Debug Domain
	GString *Dbg_M;					// Debug message
	// the logical app
	GString *App_Name_gsp;
	// the physical app
	GString *Prg_Pwd_gsp;
	GString *Prg_Name_gsp;
	// the current operator
	GString *User_Name_gsp;
	GString *Asc_Time; 
	time_t rawtime;
	struct tm *time_now;
	gulong uptime;
	//
	// int (*function)();
	
	GList *schedule_top;
	GList *schedule_bottom;
	GList *schedule_slot[6];
	GList *schedule_priorty[10];
	
	//
	// the stream handles
	FILE *err_fp;		// error-file		// do init before first calling !!
	FILE *dbg_fp;	// debug-file	// do init before first calling !!
	FILE *log_fp;		// regular log
	FILE *dot_fp;	// dot-file
	FILE *html_fp;	// html-file
	FILE *conf_fp;	// config-file
	FILE *cb_fp;		// callback-file
	gint dbg_i;								// Debug Indent
} Main_Init_t;

FILE *libsymbiot_file_open(Main_Init_t *Main_Init, const char* file_fn, const char *file_fm);

//ifndef LIBSYMBIOT_H
#endif

