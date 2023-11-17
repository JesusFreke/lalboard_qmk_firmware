/* Copyright 2023 Ben Gruver <jesusfreke@jesusfreke.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>

#include "lalboard.h"
#include "config.h"

#include "action.h"
#include "gpio.h"
#include "keyboard.h"
#include "matrix.h"
#include "print.h"

static const pin_t row_pins[MATRIX_ROWS/2] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
static const uint8_t col_pushed_states[MATRIX_COLS] = MATRIX_COL_PUSHED_STATES;

static inline void setPinOutput_writeHigh(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinHigh(pin);
    }
}

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

void matrix_init_custom(void) {
    for (int row = 0; row < MATRIX_ROWS/2; row++) {
        setPinOutput_writeHigh(row_pins[row]);
    }

    for (int col = 0; col < MATRIX_COLS; col++) {
        setPinInput(col_pins[col]);
    }
}

matrix_row_t read_row(void) {
    matrix_row_t row = 0;

    for (int col = 0; col < MATRIX_COLS; col++) {
        int col_pin = col_pins[col];

        if (readPin(col_pin) == col_pushed_states[col]) {
            row |= 1 << col;
        }
    }

    return row;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (int row = 0; row < MATRIX_ROWS/2; row++) {
        pin_t row_pin = row_pins[row];
        setPinOutput_writeLow(row_pin);
        wait_us(15);

        matrix_row_t new_row = read_row();
        changed |= new_row != current_matrix[row];
        current_matrix[row] = new_row;
        setPinOutput_writeHigh(row_pin);

        wait_us(100);
    }

    return changed;
}

void matrix_power_down(void) {
    for (int row = 0; row < MATRIX_ROWS/2; row++) {
        setPinOutput_writeHigh(row_pins[row]);
    }
}
