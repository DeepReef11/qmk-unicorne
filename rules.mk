AUDIO_ENABLE = false
ENCODER_ENABLE = no

REPEAT_KEY_ENABLE = yes

# Prevent mouse moving alone because of absence of joystick
# POINTING_DEVICE_ENABLE = false
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom

TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes
LEADER_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
RGB_MATRIX_ENABLE = yes
ENCODER_MAP_ENABLE = yes
KEY_LOCK_ENABLE = yes
CONSOLE_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
SRC += features/achordion.c
SRC += keys/combos.c
SRC += keys/key_overrides.c
SRC += keys/mouse_control.c
SRC += features/rgb_indicators.c
