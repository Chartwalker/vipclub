include ../src/config.mk

all: vipclub-gui

vipclub-gui: vipclub-gui.h vipclub-gui.c
	$(CC) vipclub-gui.c -o vipclub-gui $(CFLAGS) $(GLIBFLAGS) $(GTKFLAGS)

clean:
	rm -f vipclub-gui