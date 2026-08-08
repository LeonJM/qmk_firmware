// Compatibility shim for QMK trees predating the quantum/nvm abstraction.
//
// gwangyi/Split65's rgb_record.c calls nvm_eeconfig_{read,update}_user_datablock(),
// which take an offset and a length so a caller can touch part of the user
// datablock. This tree only has the older whole-block eeconfig_*_user_datablock(),
// so the partial accessors are reimplemented here exactly as upstream does:
// a plain offset into EECONFIG_USER_DATABLOCK.
//
// Delete this file and restore the "quantum/nvm/nvm_eeconfig.h" include in
// rgb_record.c once this fork is synced with an upstream QMK that has it.

#pragma once

#include <stdint.h>
#include "eeconfig.h"
#include "eeprom.h"

static inline void nvm_eeconfig_read_user_datablock(void *data, uint16_t offset, uint16_t length) {
    eeprom_read_block(data, EECONFIG_USER_DATABLOCK + offset, length);
}

static inline void nvm_eeconfig_update_user_datablock(const void *data, uint16_t offset, uint16_t length) {
    eeprom_update_block(data, EECONFIG_USER_DATABLOCK + offset, length);
}
