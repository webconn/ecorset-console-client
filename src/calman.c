#include "calman.h"
#include "init.h"

double calman_pass(struct calman_filter *c, double value)
{
        double ret = value * c->calman + c->old_value * (1 - c->calman);
        c->old_value = ret;
        return ret;
}
