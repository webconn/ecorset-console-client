#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <usb.h>
#include <libusb.h>
#include <stdint.h>
#include <math.h>

#define _GNU_SOURCE
#include <getopt.h>

#include "inner_usb.h"
#include "config.h"
#include "init.h"
#include "device.h"

int main(int argc, char* argv[])
{
        reader_init(); /* connect to USB dongle */
        accs_init(); /* init accelerometers */

        printf("Scanning devices...\n");
        for (int i=0; i<4; i++) {
                printf("Address %d, type %s\n", i, reader_get_name(reader_get_byte(i, 0x0F)));
        }

        /*while (1) {
                for (int i=0; i < 4; i++) {
                        unsigned char buffer[128];
                        int bytes = usb_control_msg(
                                h,             // handle obtained with usb_open()
                                USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN, // bRequestType
                                i,      // bRequest -> index of acc channel
                                0,              // wValue
                                0,              // wIndex
                                buffer,             // pointer to destination buffer
                                128,  // wLength
                                6000
                                );

                        if (bytes != 7) {
                                printf("Strange report... %d\n", bytes);
                        } else {
                                static int flag_first = 1;
                                struct acc_data data, calmans;
                                calmans = data;

                                data.whoami = (unsigned int) buffer[0];
                                data.x = (short) (buffer[1] | (buffer[2] << 8));
                                data.y = (short) (buffer[3] | (buffer[4] << 8));
                                data.z = (short) (buffer[5] | (buffer[6] << 8));

                                if (flag_first) {
                                        data.x += calmans.x;
                                        data.x /= 2;
                                        data.y += calmans.y;
                                        data.y /= 2;
                                        data.z += calmans.z;
                                        data.z /= 2;
                                        flag_first = 0;
                                }

                                if (data.whoami != 0xff) {
                                        printf("Stats for %d: name %x, data (%.10g, %.10g, %.10g), total %.10g\n", i, data.whoami, (double) (data.x * 9.8 / 162 / 100), (double) (data.y * 9.8 / 162 / 100), (double) ((data.z / 100 + 23) * 9.8 / 162), (double) (sqrt((data.x / 100)*(data.x / 100) + (data.y/100)*(data.y/100) + (data.z/100 + 23)*(data.z/100 + 23)) * 9.8 / 162));
                                }
                        }
                }
                usleep(4000);

        }*/
        
        return 0;
}
