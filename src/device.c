#include <stdlib.h>
#include <stdio.h>
#include <usb.h>
#include <libusb.h>

#include "device.h"
#include "config.h"
#include "inner_usb.h"

static usb_dev_handle *dev;

void reader_init(void)
{
	dev = nc_usb_open(I_VENDOR_NUM, I_PRODUCT_NUM, I_VENDOR_STRING, I_PRODUCT_STRING, NULL);
        if (!dev) {
                fprintf(stderr, "ERROR: No USB device found\n");
                exit(1);
        }
	
        usb_set_configuration(dev, 1);
	usb_claim_interface(dev, 0);
}

int reader_get_byte(int ch, int addr)
{
        int buffer = 0;
        int bytes = usb_control_msg(
                dev,                                                    // handle obtained with usb_open()
                USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN,   // bRequestType
                VENDOR_RQ_READ_8B,                                      // bRequest
                0,                                                      // wValue
                ((ch & 0xFF) << 8) | (addr & 0xFF),                     // wIndex -> channel in higher bit, address in lower
                (char *) &buffer,                                       // pointer to destination buffer
                1,                                                      // wLength
                5000                                                    // timeout
                );

        if (bytes == 1) {
                return buffer;
        } else {
                fprintf(stderr, "WARNING: Wrong report in reader_get_byte(%d, %d): size %d\n", ch, addr, bytes);
                return -1;
        }
}

void reader_set_byte(int ch, int addr, int value)
{
        int buffer = 0;
        int bytes = usb_control_msg(
                dev,                                                    // handle obtained with usb_open()
                USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN,   // bRequestType
                VENDOR_RQ_WRITE_8B,                                     // bRequest
                value & 0xFF,                                           // wValue
                ((ch & 0xFF) << 8) | (addr & 0xFF),                     // wIndex -> channel in higher bit, address in lower
                (char *) &buffer,                                       // pointer to destination buffer
                1,                                                      // wLength
                5000                                                    // timeout
                );

        if (bytes != 1 || buffer != value) {
                fprintf(stderr, "WARNING: Wrong report in reader_set_byte(%d, %d, %d): size %d, value %d\n", ch, addr, value, bytes, buffer);
        }
}

int reader_get_word(int ch, int addr)
{
        int buffer = 0;
        int bytes = usb_control_msg(
                dev,                                                    // handle obtained with usb_open()
                USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN,   // bRequestType
                VENDOR_RQ_READ_16B,                                     // bRequest
                0,                                                      // wValue
                ((ch & 0xFF) << 8) | (addr & 0xFF),                     // wIndex -> channel in higher bit, address in lower
                (char *) &buffer,                                       // pointer to destination buffer
                2,                                                      // wLength
                5000                                                    // timeout
                );

        if (bytes == 2) {
                return buffer;
        } else {
                fprintf(stderr, "WARNING: Wrong report in reader_get_word(%d, %d): size %d\n", ch, addr, bytes);
                return -1;
        }
}

void reader_set_word(int ch, int addr, int value)
{
        int buffer = 0;
        int bytes = usb_control_msg(
                dev,                                                    // handle obtained with usb_open()
                USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN,   // bRequestType
                VENDOR_RQ_WRITE_16B,                                    // bRequest
                value & 0xFFFF,                                         // wValue
                ((ch & 0xFF) << 8) | (addr & 0xFF),                     // wIndex -> channel in higher bit, address in lower
                (char *) &buffer,                                       // pointer to destination buffer
                2,                                                      // wLength
                5000                                                    // timeout
                );

        if (bytes != 2 || value != buffer) {
                fprintf(stderr, "WARNING: Wrong report in reader_set_word(%d, %d, %d): size %d, value %d \n", ch, addr, value, bytes, buffer);
        }
}

struct acc_raw_data reader_get_full(int ch)
{
        unsigned char buffer[7];
        struct acc_raw_data ret;

        int bytes = usb_control_msg(
                dev,                                                    // handle obtained with usb_open()
                USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_ENDPOINT_IN,   // bRequestType
                VENDOR_RQ_READ_FULL,                                    // bRequest
                0,                                                      // wValue
                ((ch & 0xFF) << 8),                                     // wIndex -> channel in higher bit, address in lower
                (char *) &buffer,                                       // pointer to destination buffer
                7,                                                      // wLength
                5000                                                    // timeout
                );
        
        if (bytes != 7) {
                fprintf(stderr, "WARNING: Wrong report in reader_get_full(%d): size %d\n", ch, bytes);
                ret.whoami = 0xff;
                return ret;
        } else {
                ret.whoami = (unsigned int) buffer[0];
                ret.x = (short) (buffer[1] | (buffer[2] << 8));
                ret.y = (short) (buffer[3] | (buffer[4] << 8));
                ret.z = (short) (buffer[5] | (buffer[6] << 8));
                return ret;
        }
}
