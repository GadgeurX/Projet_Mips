#include "compiler.h"
#include "parser.h"
#include "binary_instruction.h"
#include "data_instruct.h"

int get_instruction_count(raw_instruction* r_instruction) {
    int count = 0;
    while (!r_instruction->instruc) {
        count++;
        r_instruction++;
    }
    return count;
}

match_instruct_hexa* get_instruction_from_string(char* instruction) {
    match_instruct_hexa* tmp_matching = tab_instruct;
    while (tmp_matching->instruc != NULL) {
        if (strcmp(tmp_matching->name, instruction) == 0)
            return tmp_matching;
        tmp_matching++;
    }
    return NULL;
}

binary_instruction* process_raw_instruction(raw_instruction* r_instruction) {
    binary_instruction* b_instruction = malloc(sizeof(binary_instruction) * get_instruction_count(r_instruction));
    while (!r_instruction->instruc) {
        b_instruction->instruction = *get_instruction_from_string(r_instruction->instruc);
        r_instruction++;
    }
}

void compileFile(char* file) {
    raw_instruction* r_instruction = parse(file);
    binary_instruction* b_instruction = process_raw_instruction(r_instruction);

    free(r_instruction);
    free(b_instruction);
}