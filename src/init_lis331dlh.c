#define GET_REGS
#include "accels/lis331dlh.h"
#undef GET_REGS

#include "device.h"

static struct acc_cfg cfg = {
        .whoami = LIS331DLH_ID,
        .calman = 0.5
};

void lis331dlh_init(int channel)
{
        /* 1. check if it is really LIS3DH */
        if (!IS_LIS331DLH(reader_get_byte(channel, WHO_AM_I)))
                return;

        /* load default configuration */
        reader_set_byte(channel, CTRL_REG1, 0x2F); /* 100 Hz, normal power, XYZ enabled */
}

struct acc_cfg *lis331dlh_getcfg(void)
{
        return &cfg;
}
