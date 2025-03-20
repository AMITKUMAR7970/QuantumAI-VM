#ifndef INSTRUCTION_SET_HPP
#define INSTRUCTION_SET_HPP

enum class Instruction {
    NOP = 0x00,    
    LOAD = 0x01,   
    ADD = 0x02,    
    SUB = 0x03,    
    MUL = 0x04,    
    DIV = 0x05,    
    PRINT = 0x06,  
    PUSH = 0x07,   // Push value onto stack
    POP = 0x08,    // Pop value from stack
    JMP = 0x09,    // Unconditional jump
    JZ = 0x0A,     // Jump if zero
    HALT = 0xFF    
};

#endif // INSTRUCTION_SET_HPP
