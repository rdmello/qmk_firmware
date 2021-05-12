
# RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = WS2812
EXTRAKEY_ENABLE = yes
# BOOTMAGIC_ENABLE = full
# KEY_LOCK_ENABLE = yes # Approx. 1500 bytes :(

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
