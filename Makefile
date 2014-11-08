OBJDIR = build
INCLUDEDIR = include
SRCDIR = src
TARGET = stool

OBJS = usb.o main.o device.o init.o init_lis3dh.o init_lis331dl.o init_lis331dlh.o calman.o

CFLAGS  := $(shell pkg-config --cflags libusb-1.0) -I$(INCLUDEDIR) -std=gnu99 
LDFLAGS := $(shell pkg-config --libs libusb-1.0) -lm -lusb

OBJS:=$(addprefix $(OBJDIR)/, $(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc -c -o $@ $^ $(CFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm stool $(OBJDIR) -rf
