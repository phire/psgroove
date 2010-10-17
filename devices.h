/*
    PSGroove Exploit

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "descriptor.h"

typedef struct {
	uint8_t *device_descriptor;
        int8_t num_configs;
        /* pointers to the short configuration descriptors are interleaved
           with the full length configuration descriptors. */
        uint8_t *config_descriptor[];
} device;

const PROGMEM device hub_device = {
	PROGMEM HUB_Device_Descriptor,
	1,
	HUB_Config_Descriptor,
	HUB_Config_Descriptor,
};

const PROGMEM device port1_device = {
	port1_device_descriptor,
	-1, // Just repeat this configuration as many times as it is asked for.
	port1_short_config_descriptor,
	port1_config_descriptor,
};

const PROGMEM device port2_device = {
	port2_device_descriptor,
	1,
	port2_config_descriptor,
	port2_config_descriptor,
};

const PROGMEM device port3_device = {
	port3_device_descriptor,
	1,
	port3_config_descriptor,
	port3_config_descriptor,
};

const PROGMEM device port4_device = {
	port4_device_descriptor,
	3,
	port4_config_descriptor_1,
	port4_config_descriptor_1,
	port4_short_config_descriptor_2,
	port4_config_descriptor_2,
	port4_config_descriptor_3,
	port4_config_descriptor_3
};

const PROGMEM device port5_device = {
	port5_device_descriptor,
	1,
	port5_short_config_descriptor,
	port5_config_descriptor,
};


