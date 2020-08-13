//
// Created by Arakawa Shogo on 2020/08/10.
//

#include "common.h"

#ifndef RISCV_EMULATOR_MEMORY_H
#define RISCV_EMULATOR_MEMORY_H

// 128Mib
// const int MemorySize = 1024 * 1024 * 128;

class Memory {
private:
    byte dram[1024];
public:
    Memory();
    byte get8(dword addr);
    word get16(dword addr);
    dword get32(dword addr);
    qword get64(dword addr);
    void set8(dword addr, byte b);
    void set16(dword addr, word w);
    void set32(dword addr, dword dw);
    void set64(dword addr, qword qw);
};

#endif //RISCV_EMULATOR_MEMORY_H
