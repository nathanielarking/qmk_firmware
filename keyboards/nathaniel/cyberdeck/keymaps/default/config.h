#define VENDOR_ID    0x4E4B  // "NK" - you can choose your own
#define PRODUCT_ID   0x5343  // "SC" for snakcyberdeck - you can choose your own
#define DEVICE_VER   0x0001  // Version 1
#define MANUFACTURER    "Nathaniel King"
#define PRODUCT         "snakcyberdeck"

#define MATRIX_ROWS 8   
#define MATRIX_COLS 5
#define MATRIX_ROW_PINS { GP16, GP15, GP14, GP13 }
#define MATRIX_COL_PINS { GP2, GP3, GP4, GP12, GP9 }
#define MATRIX_ROW_PINS_RIGHT { GP2, GP3, GP9, GP12 }
#define MATRIX_COL_PINS_RIGHT { GP7, GP13, GP4, GP16, GP12 }

#define SPLIT_HAND_PIN GP29
#define SLIT_USB_DETECT

//#define NO_DEBUG
//#define NO_PRINT

/**
 * This sets the pin to be used for serial communication.
 */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

/** */
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20


/**
 * If you're having issues with serial communication, you can change this value, 
 * as it controls the communication speed for serial. The default is 1, and the possible values are:
 *   0: about 189kbps (Experimental only)
 *   1: about 137kbps (default)
 *   2: about 75kbps
 *   3: about 39kbps
 *   4: about 26kbps
 *   5: about 20kbps
 */
#define SELECT_SOFT_SERIAL_SPEED 1

/**
 * How long before oneshot times out
 */
#define ONESHOT_TIMEOUT 300
/**
 * #define ONESHOT_TAP_TOGGLE 2
 */
#define ONESHOT_TAP_TOGGLE 2

/**
 * This enables transmitting the pointing device status to the master side of the split keyboard. 
 * The purpose of this feature is to enable use pointing devices on the slave side.
 */
/*
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define PMW33XX_CS_PIN GP21
#define ROTATIONAL_TRANSFORM_ANGLE  -25
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define PMW33XX_LIFTOFF_DISTANCE 0x02
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
*/