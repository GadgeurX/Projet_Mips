#include "compiler.h"
#include "parser.h"
#include "binary_instruction.h"

binary_instruction* process_raw_instruction(raw_instruction* r_instruction) {
    while (!r_instruction->instruc) {

        r_instruction++;
    }
}

void compileFile(char* file) {
    raw_instruction* r_instruction = parse(file);
    binary_instruction* b_instruction = process_raw_instruction(r_instruction);
}