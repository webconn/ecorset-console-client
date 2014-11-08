#define GET_REGS
#include "accels/lis3dh.h"
#undef GET_REGS

#include "device.h"

static struct acc_cfg cfg = {
        .whoami = LIS3DH_ID,
        .calman = 0.5
};

void lis3dh_init(int channel)
{
        /* 1. check if it is really LIS3DH */
        if (!IS_LIS3DH(reader_get_byte(channel, WHO_AM_I)))
                return;

        /* load default configuration */
        reader_set_byte(channel, CTRL_REG1, 0x57); /* 100 Hz, normal power, XYZ enabled */
}

struct acc_cfg *lis3dh_getcfg(void)
{
        return &cfg;
}
