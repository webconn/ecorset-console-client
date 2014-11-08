#ifndef INCLUDE_ACCELS_LIS331DL_H
#define INCLUDE_ACCELS_LIS331DL_H

void lis331dl_init(int channel);
struct acc_cfg *lis331dl_getcfg(void);

/** Definition of register addresses of
 * LIS331DL series accelerometers (WHO_AM_I == 0x3B)
 */


#define LIS331DL_ID             0x3B
#define IS_LIS331DL(x)          ((x) == LIS331DL_ID)

#ifdef GET_REGS

#define WHO_AM_I                0x0F

#define CTRL_REG1               0x20
#define CTRL_REG2               0x21
#define CTRL_REG3               0x22

#define HP_FILTER_RESET         0x23

#define STATUS_REG              0x27

#define OUT_X                   0x29

#define OUT_Y                   0x2B

#define OUT_Z                   0x2D

#define FF_WU_CFG_1             0x30
#define FF_WU_SRC_1             0x31
#define FF_WU_THS_1             0x32
#define FF_WU_DURATION_1        0x33

#define FF_WU_CFG_2             0x34
#define FF_WU_SRC_2             0x35
#define FF_WU_THS_2             0x36
#define FF_WU_DURATION_2        0x37

#define CLICK_CFG               0x38
#define CLICK_SRC               0x39
#define CLICK_THSY_X            0x3B
#define CLICK_THSZ              0x3C
#define CLICK_TIMELIMIT         0x3D
#define CLICK_LATENCY           0x3E
#define CLICK_WINDOW            0x3F

#endif

#endif
