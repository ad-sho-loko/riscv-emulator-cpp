#include <memory>
#include "common.h"
#include "memory.h"

enum RV32I {
    addi = 0b0010011
};

struct I {
    unsigned opcode: 7;
    unsigned rd: 5;
    unsigned funct3: 3;
    unsigned rs1: 5;
    unsigned imm: 12;
};

class Cpu {
private:
    std::unique_ptr<Memory> memory;

public:
    int pc;

    Cpu();
    dword fetch();
};

Cpu::Cpu() {
    memory = std::make_unique<Memory>();
}

class Emulator {
private:
    std::unique_ptr<Cpu> cpu;

public:
    Emulator();
    void tick();
};

Emulator::Emulator() {
    cpu = std::make_unique<Cpu>();
}

void Emulator::tick() {
    cpu->pc += 4;
}

int main() {
    auto emulator = Emulator();
    emulator.tick();
    return 0;
}
