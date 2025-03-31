// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_COLS 7
#define MATRIX_ROWS 12

#define MCP23018_TIMEOUT 10

#define IS31FL3731_I2C_ADDRESS_1 IS31FL3731_I2C_ADDRESS_GND
#define IS31FL3731_I2C_ADDRESS_2 IS31FL3731_I2C_ADDRESS_VCC

#define IS31FL3731_I2C_TIMEOUT 5

// #define MOUSEKEY_WHEEL_INTERVAL MOUSEKEY_INTERVAL
// #define MOUSEKEY_WHEEL_MAX_SPEED MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_WHEEL_TIME_TO_MAX MOUSEKEY_TIME_TO_MAX

#define MOUSEKEY_WHEEL_DELAY	10	// Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL	80	// Time between wheel movements
#define MOUSEKEY_WHEEL_DELTA	1	// Wheel movement step size
#define MOUSEKEY_WHEEL_MAX_SPEED	8	// Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX	40 // Time until maximum scroll speed is reached

#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_TIME_TO_MAX 64
#define MOUSEKEY_MAX_SPEED 40
#define MOUSEKEY_FRICTION  1
#define MOUSEKEY_MOVE_DELTA 1

#define DEBOUNCE 10
