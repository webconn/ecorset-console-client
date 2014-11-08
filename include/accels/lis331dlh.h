#ifndef INCLUDE_ACCELS_LIS331DLH_H
#define INCLUDE_ACCELS_LIS331DLH_H

void lis331dlh_init(int channel);
struct acc_cfg *lis331dlh_getcfg(void);

/** Definition of register addresses of
 * LIS331DLH series accelerometers (WHO_AM_I == 0x32)
 */

#define LIS331DLH_ID            0x32
#define IS_LIS331DLH(x)         ((x) == LIS331DLH_ID)

#ifdef GET_REGS

#define WHO_AM_I                0x0F

#define CTRL_REG1               0x20
#define CTRL_REG2               0x21
#define CTRL_REG3               0x22
#define CTRL_REG4               0x23
#define CTRL_REG5               0x24

#define HP_FILTER_RESET         0x25
#define REFERENCE               0x26

#define STATUS_REG              0x27

#define OUT_X_L                 0x28
#define OUT_X_H                 0x29
#define OUT_X                   0x28

#define OUT_Y_L                 0x2A
#define OUT_Y_H                 0x2B
#define OUT_Y                   0x2A

#define OUT_Z_L                 0x2C
#define OUT_Z_H                 0x2D
#define OUT_Z                   0x2C

#define INT1_CFG                0x30
#define INT1_SOURCE             0x31
#define INT1_THS                0x32
#define INT1_DURATION           0x33

#define INT2_CFG                0x34
#define INT2_SOURCE             0x35
#define INT2_THS                0x36
#define INT2_DURATION           0x37

#endif

#endif
