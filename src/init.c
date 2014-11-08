#include "device.h"

static int devs[4];

static void init_spec(int channel)
{
        if (channel >= 4)
                return; /* no such channel in system */

        int whoami = reader_get_byte(channel, 0x0F);

        switch (whoami) {
                case LIS3DH_ID:
                        lis3dh_init(channel);
                        break;
                case LIS331DL_ID:
                        lis331dl_init(channel);
                        break;
                case LIS331DLH_ID:
                        lis331dlh_init(channel);
                        break;
        }

        devs[channel] = whoami;
}

void accs_init(void)
{
        for (int i=0; i<4; i++) {
                init_spec(i);                      
        }
}

struct acc_cfg *acc_getcfg(int channel)
{
        switch (devs[channel]) {
                case LIS3DH_ID:
                        return lis3dh_getcfg();
                case LIS331DL_ID:
                        return lis331dl_getcfg();
                case LIS331DLH_ID:
                        return lis331dlh_getcfg();
        }
}
