#ifndef INCLUDE_ACCELS_LIS3DH_H
#define INCLUDE_ACCELS_LIS3DH_H

void lis3dh_init(int channel);
struct acc_cfg *lis3dh_getcfg(void);

/** Definition of register addresses of
 * LIS3DH series accelerometers (WHO_AM_I == 0x33)
 */

#define LIS3DH_ID               0x33
#define IS_LIS3DH(x)            ((x) == LIS3DH_ID)

#ifdef GET_REGS

#define STATUS_REG_AUX          0x07

#define OUT_ADC1_L              0x08
#define OUT_ADC1_H              0x09
#define OUT_ADC1                0x08

#define OUT_ADC2_L              0x0A
#define OUT_ADC2_H              0x0B
#define OUT_ADC2                0x0A

#define OUT_ADC3_L              0x0C
#define OUT_ADC3_H              0x0D
#define OUT_ADC3                0x0C

#define INT_COUNTER_REG         0x0E
#define WHO_AM_I                0x0F

#define TEMP_CFG_REG            0x1F
#define CTRL_REG1               0x20
#define CTRL_REG2               0x21
#define CTRL_REG3               0x22
#define CTRL_REG4               0x23
#define CTRL_REG5               0x24
#define CTRL_REG6               0x25

#define REFERENCE               0x26

#define STATUS_REG2             0x27

#define OUT_X_L                 0x28
#define OUT_X_H                 0x29
#define OUT_X                   0x28

#define OUT_Y_L                 0x2A
#define OUT_Y_H                 0x2B
#define OUT_Y                   0x2A

#define OUT_Z_L                 0x2C
#define OUT_Z_H                 0x2D
#define OUT_Z                   0x2C

#define FIFO_CTRL_REG           0x2E
#define FIFO_SRC_REG            0x2F

#define INT1_CFG                0x30
#define INT1_SOURCE             0x31
#define INT1_THS                0x32
#define INT1_DURATION           0x33

#define CLICK_CFG               0x38
#define CLICK_SRC               0x39
#define CLICK_THS               0x3A

#define TIME_LIMIT              0x3B
#define TIME_LATENCY            0x3C
#define TIME_WINDOW             0x3D

#endif

#endif
