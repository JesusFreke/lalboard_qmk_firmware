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

#pragma once

#include "quantum.h"

#define LAYOUT( \
    l1d, l1n, l1e, l1s, l1w, \
    l2d, l2n, l2e, l2s, l2w, \
    l3d, l3n, l3e, l3s, l3w, \
    l4d, l4n, l4e, l4s, l4w, \
    r1d, r1n, r1e, r1s, r1w, \
    r2d, r2n, r2e, r2s, r2w, \
    r3d, r3n, r3e, r3s, r3w, \
    r4d, r4n, r4e, r4s, r4w, \
    ltd, lti, ltu, ltuo, ltlo, \
    rtd, rti, rtu, rtuo, rtlo) \
{ \
    {l1e, l1n, l1d, l1s, l1w}, \
    {l2e, l2n, l2d, l2s, l2w}, \
    {l3e, l3n, l3d, l3s, l3w}, \
    {l4e, l4n, l4d, l4s, l4w}, \
    {ltlo,ltuo,ltd, lti, ltu}, \
    {r1e, r1n, r1d, r1s, r1w}, \
    {r2e, r2n, r2d, r2s, r2w}, \
    {r3e, r3n, r3d, r3s, r3w}, \
    {r4e, r4n, r4d, r4s, r4w}, \
    {rtlo,rtuo,rtd, rti, rtu} \
}

#define KC_LSHIFT KC_LSFT
#define KC_LCTRL KC_LCTL
#define KC_RBRACKET KC_RBRC
#define KC_PSCREEN KC_PSCR
#define KC_BSLASH KC_BSLS
#define KC_BSPACE KC_BSPC
#define KC_SCOLON KC_SCLN
#define KC_LBRACKET KC_LBRC
#define KC_RIGHT_CURLY KC_RIGHT_CURLY_BRACE
#define KC_LEFT_CURLY KC_LEFT_CURLY_BRACE
