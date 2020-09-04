CONSOLE_ENABLE     = yes  # Console for debug
ENCODER_ENABLE     = yes  # ENables the use of one or more encoders
RGBLIGHT_ENABLE    = yes  # Enable keyboard RGB underglow
MOUSEKEY_ENABLE    = no   # Mouse keys
OLED_DRIVER_ENABLE = yes  # Enables the use of OLED displays

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled_utils.c
endif
