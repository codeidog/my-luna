#ifdef OLED_ENABLE
#    include QMK_KEYBOARD_H

/* bread logo timers */
uint32_t bread_timer = 0;
uint8_t  bread_index = 0;
/* 32x50 logo animations */
static const char PROGMEM bread_logo[4][224] = {
    /* toast 1 curly */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xbf, 0x88, 0x80, 0xbe, 0x99,
     0x80, 0x84, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x6c, 0xed, 0xec, 0x6c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x6c, 0xec, 0xec, 0x6c, 0x3f, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    /* toast 2 peaking */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xe0, 0x90, 0x88, 0x8c, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84,
     0x84, 0x8c, 0x9c, 0xb4, 0xc4, 0x8c, 0xc8, 0x90, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x6c, 0xed, 0xec, 0x6c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x6c, 0xec, 0xec, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    /* toast 3 jumping */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0xf1, 0x00, 0x00, 0x20, 0xb0, 0xc0, 0x60, 0x30, 0x90, 0x00, 0x00, 0xf1, 0x1b, 0xc4, 0x30, 0x1c, 0xf1, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x07, 0x00, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xbe, 0x80, 0x80, 0x80, 0xbe, 0x80,
     0x80, 0x80, 0xbe, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x6c, 0xed, 0xec, 0x6c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x6c, 0xec, 0xec, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    /* toast 4 coming down */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x9c, 0xe2, 0x81, 0x81, 0xc0, 0xe0, 0x80, 0xc0, 0xe0, 0xa0,
     0x80, 0x81, 0xe3, 0xb6, 0x88, 0xe1, 0xb9, 0xe2, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x70, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x6c, 0xed, 0xec, 0x6c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x6c, 0xec, 0xec, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
/* 32 * 32 logo */
static void render_logo(void) {
    if (timer_elapsed32(bread_timer) > 400) {
        uint8_t bread_array_length = sizeof(bread_logo) / sizeof(bread_logo[0]);
        bread_timer                = timer_read32();
        bread_index                = (bread_index + 1 >= bread_array_length) ? 0 : bread_index + 1;
        oled_write_raw_P(bread_logo[bread_index], sizeof(bread_logo[bread_index]));
    }
}

/* 32 * 14 os logos */
static const char PROGMEM docker_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0x00, 0xf0, 0xc0, 0xe0, 0x80, 0x00, 0x02, 0x0c, 0x2e, 0xfc, 0xfc, 0xfc, 0xfc, 0x78, 0x78, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x3f, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xf8, 0xf1, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xf0, 0xb0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x7b, 0xdf, 0x1f, 0x3f, 0x3f, 0x1f, 0x1f, 0x3f, 0x5f, 0x9f, 0x8f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x06, 0x07, 0x0f, 0x1c, 0x74, 0x0c, 0x0d, 0x09, 0x09, 0x11, 0x01, 0x03, 0x03, 0x07, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00};

static void print_top_layer(void) {
    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write("QWRTY", false);
            break;
        case 1:
            oled_write("COLMK", false);
            break;
        case 2:
            oled_write("FUNCTION", false);
            break;
        default:
            oled_write("UNDEF", false);
    }
}

static void print_highest_layer(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write("Base ", false);
            break;
        case 1:
            oled_write("Base ", false);
            break;
        case 2:
            oled_write("FN   ", false);
            break;
        case 3:
            oled_write("SYMBL", false);
            break;
        case 4:
            oled_write("Raise", false);
            break;
        case 5:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }
}

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    // uint8_t n = get_current_wpm();
    //  char    wpm_str[4];
    oled_set_cursor(0, 7);
    print_top_layer();

    oled_set_cursor(0, 9);
    print_highest_layer();

    oled_set_cursor(0, 11);
    oled_write("CPSLK", host_keyboard_led_state().caps_lock);

    /* wpm counter */
    uint8_t wpm_count = get_current_wpm();
    char    wpm_str[5];

    /* convert counter to string */
    itoa(wpm_count, wpm_str, 10);

    oled_set_cursor(0, 14);
    oled_write_ln(wpm_str, false);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print Logo */
    oled_set_cursor(0, 0);
    oled_write_raw_P(docker_logo, sizeof(docker_logo));

    /* Print top layer */
    oled_set_cursor(0, 3);
    print_top_layer();
    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);
    oled_set_cursor(0, 6);
    print_highest_layer();

    /* Print caps lock status */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", host_keyboard_led_state().caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif