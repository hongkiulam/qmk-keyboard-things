/*
Copyright 2023 Hong-Kiu Lam
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KB_H
#define KB_H

#pragma once

#include "quantum.h"

/*
* Physical Layout followed by Wiring Matrix
*/

#define LAYOUT( \
	K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, \
	K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,      K1b, \
	K20,      K22, K23, K24, K25, K26, K27, K28, K29, K2a, K2b, \
	K30, K31, K32, K33,      K35,      K37, K38, K39, K3a, K3b \
) { \
	{ K00,  K01,   K02, K03,  K04,   K05,  K06,   K07, K08, K09,  K0a,   K0b }, \
	{ K10,  K11,   K12, K13,  K14,   K15,  K16,   K17, K18, K19, KC_NO,  K1b }, \
	{ K20, KC_NO,  K22, K23,  K24,   K25,  K26,   K27, K28, K29,  K2a,   K2b }, \
	{ K30,  K31,   K32, K33, KC_NO,  K35, KC_NO,  K37, K38, K39,  K3a,   K3b }  \
}

#endif
