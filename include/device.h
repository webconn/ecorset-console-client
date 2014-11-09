#ifndef READER_INCLUDE_DEVICE_H
#define READER_INCLUDE_DEVICE_H

#include <stdint.h>

#include "accels/lis3dh.h"
#include "accels/lis331dl.h"
#include "accels/lis331dlh.h"

struct acc_raw_data {
        int whoami;
        int x;
        int y;
        int z;
};

struct acc_cfg {
        int whoami;
        double calman;
};

void reader_init();
int reader_get_byte(int ch, int addr);
void reader_set_byte(int ch, int addr, int value);
int reader_get_word(int ch, int addr);
void reader_set_word(int ch, int addr, int value);
struct acc_raw_data reader_get_full(int ch);
char *reader_get_name(int whoami);

#endif
