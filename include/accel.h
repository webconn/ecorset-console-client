#ifndef INCLUDE_ACCEL_H
#define INCLUDE_ACCEL_H

struct accel_access {
        int (*raw_x)(int);
        int (*raw_y)(int);
        int (*raw_z)(int);
};

void accel_init(int channel);


#endif
