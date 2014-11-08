#ifndef INCLUDE_CALMAN_H
#define INCLUDE_CALMAN_H

struct calman_filter {
        double calman;
        double old_value;
};

double calman_pass(struct calman_filter *c, double value);

#endif
