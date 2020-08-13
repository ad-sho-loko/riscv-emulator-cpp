//
// Created by Arakawa Shogo on 2020/08/10.
//

#include "memory.h"

Memory::Memory(){}

byte Memory::get8(dword addr) {
    return dram[addr];
}

word Memory::get16(dword addr) {
    return dram[addr+1] << 8 | dram[addr];
}

dword Memory::get32(dword addr) {
    return dram[addr+3] << 24 |
           dram[addr+2] << 16 |
           dram[addr+1] << 8 |
           dram[addr];
}

qword Memory::get64(dword addr) {
    return dram[addr+7] << 56 |
           dram[addr+6] << 48 |
           dram[addr+5] << 40 |
           dram[addr+4] << 32 |
           dram[addr+3] << 24 |
           dram[addr+2] << 16 |
           dram[addr+1] << 8 |
           dram[addr];
}

void Memory::set8(dword addr, byte b) {
    dram[addr] = b;
}

void Memory::set16(dword addr, word w) {
    dram[addr] = w & 0xFF;
    dram[addr+1] = (w >> 8) & 0xFF;
}

void Memory::set32(dword addr, dword dw) {
    dram[addr] =  (dw >> 24) & 0xFF;
    dram[addr+1] = (dw >> 16) & 0xFF;
    dram[addr+2] = (dw >> 8) & 0xFF;
    dram[addr+3] = dw & 0xFF;
}

void Memory::set64(dword addr, qword qw) {
    dram[addr] = (qw >> 56) & 0xFF;
    dram[addr+1] = (qw >> 48) & 0xFF;
    dram[addr+2] = (qw >> 40) & 0xFF;
    dram[addr+3] = (qw >> 32) & 0xFF;
    dram[addr+4] = (qw >> 24) & 0xFF;
    dram[addr+5] = (qw >> 16) & 0xFF;
    dram[addr+6] = (qw >> 8) & 0xFF;
    dram[addr+7] = qw & 0xFF;
}

//[submodule "third_party/googletest"]
//	path = third_party/googletest
//	url = git@github.com:google/googletest.git