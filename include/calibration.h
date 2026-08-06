#ifndef CALIBRATION
#define CALIBRATION

#define CHANNEL_1_LOW_EP 989
#define CHANNEL_1_HIGH_EP 2011

#define CHANNEL_2_LOW_EP 989
#define CHANNEL_2_HIGH_EP 2011

#define CHANNEL_3_LOW_EP 989
#define CHANNEL_3_HIGH_EP 2011

#define CHANNEL_4_LOW_EP 989
#define CHANNEL_4_HIGH_EP 2011

#define CHANNEL_5_LOW_EP 989
#define CHANNEL_5_HIGH_EP 2011

#define CHANNEL_6_LOW_EP 989
#define CHANNEL_6_HIGH_EP 2011

#define CHANNEL_7_LOW_EP 989
#define CHANNEL_7_HIGH_EP 2011

#define CHANNEL_8_LOW_EP 989
#define CHANNEL_8_HIGH_EP 2011

#define CHANNEL_10_LOW_EP 989
#define CHANNEL_10_HIGH_EP 2011

#define CHANNEL_AUX_SW_LOW 1000
#define CHANNEL_AUX_SW_MID 1510
#define CHANNEL_AUX_SW_HIGH 2011

// Midpoints between the 3 switch positions, used to bucket a raw channel
// value into down/mid/up (e.g. for hat output on a 3-way switch)
#define CHANNEL_AUX_SW_LOW_MID_THRESH ((CHANNEL_AUX_SW_LOW + CHANNEL_AUX_SW_MID) / 2)
#define CHANNEL_AUX_SW_MID_HIGH_THRESH ((CHANNEL_AUX_SW_MID + CHANNEL_AUX_SW_HIGH) / 2)

#define JOYSTICK_LOW (-32767)
#define JOYSTICK_HIGH 32767
#define CHANNEL_AUX_SW_LOW_MAP LOW
#define CHANNEL_AUX_SW_HIGH_MAP HIGH

// How long a momentary button reports pressed once triggered, regardless of
// how long the switch is physically held (ms)
#define BTN_PULSE_MS 200

// upper bound and lower bound constrain where button reports HIGH and is inclusive
// Typically use MID / HIGH
// momentary: true = fire a single BTN_PULSE_MS pulse per transition into
// range (for switches that don't already have a physical momentary action);
// false = report the raw channel state directly, HIGH for as long as held
typedef struct btn_config {
    byte channel;
    byte id;
    int lower_bound;
    int upper_bound;
    bool invert;
    bool momentary;
} btn_config;

#define NUM_BUTTONS 10
btn_config btn_map[NUM_BUTTONS] = {
    // Button 0 - SA (already a physical momentary button) - Channel 6
    {
    6,                                    // channel
    0,                                    // id
    CHANNEL_AUX_SW_MID,                   // lower bound
    CHANNEL_AUX_SW_HIGH,                  // upper bound
    false,                                // invert
    false                                 // momentary - physical switch is already momentary
    },

    // Button 1 - SD (already a physical momentary button) - Channel 9
    {
    9,                                    // channel
    1,                                    // id
    CHANNEL_AUX_SW_MID,                   // lower bound
    CHANNEL_AUX_SW_HIGH,                  // upper bound
    false,                                // invert
    false                                 // momentary - physical switch is already momentary
    },

    // Button 2 - SB down - Channel 7
    {
    7,                                    // channel
    2,                                    // id
    0,                                    // lower bound
    CHANNEL_AUX_SW_LOW_MID_THRESH - 1,    // upper bound
    false,                                // invert
    true                                  // momentary
    },

    // Button 3 - SB mid - Channel 7
    {
    7,                                    // channel
    3,                                    // id
    CHANNEL_AUX_SW_LOW_MID_THRESH,        // lower bound
    CHANNEL_AUX_SW_MID_HIGH_THRESH,       // upper bound
    false,                                // invert
    true                                  // momentary
    },

    // Button 4 - SB up - Channel 7
    {
    7,                                    // channel
    4,                                    // id
    CHANNEL_AUX_SW_MID_HIGH_THRESH + 1,   // lower bound
    CHANNEL_AUX_SW_HIGH,                  // upper bound
    false,                                // invert
    true                                  // momentary
    },

    // Button 5 - SC down - Channel 8
    {
    8,                                    // channel
    5,                                    // id
    0,                                    // lower bound
    CHANNEL_AUX_SW_LOW_MID_THRESH - 1,    // upper bound
    false,                                // invert
    true                                  // momentary
    },

    // Button 6 - SC mid - Channel 8
    {
    8,                                    // channel
    6,                                    // id
    CHANNEL_AUX_SW_LOW_MID_THRESH,        // lower bound
    CHANNEL_AUX_SW_MID_HIGH_THRESH,       // upper bound
    false,                                // invert
    true                                  // momentary
    },

    // Button 7 - SC up - Channel 8
    {
    8,                                    // channel
    7,                                    // id
    CHANNEL_AUX_SW_MID_HIGH_THRESH + 1,   // lower bound
    CHANNEL_AUX_SW_HIGH,                  // upper bound
    false,                                // invert
    true                                  // momentary
    },

    // Button 8 - ARM (SE) pushed/armed - Channel 5
    {
    5,                                    // channel
    8,                                    // id
    CHANNEL_AUX_SW_MID,                   // lower bound
    CHANNEL_AUX_SW_HIGH,                  // upper bound
    false,                                // invert
    false                                 // momentary
    },

    // Button 9 - ARM (SE) released/disarmed - Channel 5
    {
    5,                                    // channel
    9,                                    // id
    CHANNEL_AUX_SW_MID,                   // lower bound
    CHANNEL_AUX_SW_HIGH,                  // upper bound
    true,                                 // invert
    true                                  // momentary
    }
};

// Channel1 - A            - Roll  (Axis0 / X)
// Channel2 - E            - Pitch (Axis1 / Y)
// Channel3 - T            - Throttle (Axis2 / Z)
// Channel4 - R            - Yaw (Axis3 / Rx)
// Channel5 - Aux 1        - ARM / SE (Button 8 pushed, Button 9 released)
// Channel6 - Aux 2        - SA (Button 0)
// Channel7 - Aux 3        - SB (Button 2 down, Button 3 mid, Button 4 up)
// Channel8 - Aux 4        - SC (Button 5 down, Button 6 mid, Button 7 up)
// Channel9 - Aux 5        - SD (Button 1)
// Channel10 - Aux 6       - S1 / wheel (BTN_PINKIE) - Axis4 / Ry
// Channel11 - Aux 7       - unused, no physical switch
// Channel12 - Aux 8       - unused, no physical switch
// Channel13
// Channel14
// Channel15 - LQ
// Channel16 - RSSI

#endif
