#ifndef READER_INCLUDE_USB_H
#define READER_INCLUDE_USB_H

#include <usb.h>
#include <libusb.h>

/* Define request types */
#define VENDOR_RQ_WRITE_8B 0
#define VENDOR_RQ_READ_8B 1
#define VENDOR_RQ_WRITE_16B 2
#define VENDOR_RQ_READ_16B 3
#define VENDOR_RQ_READ_FULL 4

usb_dev_handle *nc_usb_open(int vendor, int product, char *vendor_name, char *product_name, char *serial);

#endif
