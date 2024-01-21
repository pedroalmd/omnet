//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "contentO.h"
#include <omnetpp.h>


contentO::contentO() {
    // TODO Auto-generated constructor stub

}

contentO::~contentO() {
    // TODO Auto-generated destructor stub
}

void contentO::setName(char n) {
    name = n;
}

char contentO::getName() {
    return name;
}

void contentO::setChunk(int index, int value) {
    chunk[index] = value;
}

int contentO::getChunk(int index) {
    return chunk[index];
}

void contentO::setChunkTime(int index, omnetpp::simtime_t value) {
    chunk_arr_time[index] = value;
}

omnetpp::simtime_t contentO::getChunkTime(int index) {
    return chunk_arr_time[index];
}


