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

#include "devices.h"

device active_device = hub_device;
int current_state = 0;

// The states that our state machine will transistion through
const PROGMEM state states[] = {
	init,
	power_hub_ports,
	wait(15),
	connect_port(1, port1_device),
	wait(10),
	connect_port(2, port2_device),
	wait(15),
	connect_port(3, port3_device),
	wait(10),
	disconnect_port(2),
	wait(15),
	connect_port(4, port4_device),
	wait(20),
	connect_port(5, port5_device),
	receive_challange,
	wait(50),
	send_response,
	wait(15),
	disconnect_port(3),
	wait(45),
	disconnect_port(5),
	wait(20),
	disconnect_port(4),
	wait(20),
	disconnect_port(1),
	done,
};

void advance_state() {
	state = states[current_state++];
	switch(state.type) {
	case wait:
		set_timeout(state.length);
	case connect_port:
		hub_connect(state.port, state.device);
	case disconnect_port:
		hub_disconnect(state.port);
	case function:
		state.function();
	}
}
