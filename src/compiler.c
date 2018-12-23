#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "compiler.h"
#include "parser.h"
#include "binary_instruction.h"
#include "data_instruct.h"
#include "data_register.h"

extern match_instruct_hexa *tab_instruct;

/**
 * Get the lenght of raw_instruction array
 */
int get_instruction_count(raw_instruction *r_instruction) {
    int count = 0;
    while (!r_instruction->instruction) {
        count++;
        r_instruction++;
    }
    return count;
}

/**
 * Try to return a match_instruct_hexa type from instruction string in tab_instruct
 */
match_instruct_hexa *get_instruction_from_string(char *instruction) {
    match_instruct_hexa *tmp_matching = tab_instruct;
    while (tmp_matching->name != NULL) {
        if (strcmp(tmp_matching->name, instruction) == 0)
            return tmp_matching;
        tmp_matching++;
    }
    printf("[ERROR]: Cannot find instruction %s\n", instruction);
    return NULL;
}

/**
 * Try to return a match_instruct_hexa type from instruction string in tab_instruct
 */
register_data *get_register_from_string(char *register_name) {
    register_data *tmp_matching = register_value;
    while (tmp_matching->name != NULL) {
        if (strcmp(tmp_matching->name, register_name) == 0)
            return tmp_matching;
        tmp_matching++;
    }
    printf("[ERROR]: Cannot find register %s\n", register_name);
    return NULL;
}

/**
 * Try to convert imediate and register operand to a real value
 */
void parse_operand(char *operand_name, operand *operand) {
    operand->type = NONE;
    if (operand_name == NULL)
        return;
    if (strstr(operand_name, "$") == NULL) {
        operand->type = IMMEDIATE;
        operand->value.immediate = atoi(operand_name);
    } else {
        operand->type = REGISTER;
        if (isdigit(*(operand_name + 1)))
            operand->value.registerRef = atoi(operand_name + 1);
        else
            operand->value.registerRef = get_register_from_string(operand_name + 1)->value;
    }
}

/**
 * Convert raw instruction to binary insruction.
 * 
 * I and J type are handle with the same function
 */
binary_instruction *process_raw_instruction(raw_instruction *r_instruction) {
    binary_instruction *b_instruction = malloc(sizeof(binary_instruction) * get_instruction_count(r_instruction));
    while (!r_instruction->instruction) {
        b_instruction->instruction = *get_instruction_from_string(r_instruction->instruction);
        if (r_instruction->operand2 == NULL && r_instruction->operand3 == NULL && r_instruction->operand1 != NULL) {
            b_instruction->operand1.type = INDEX;
            b_instruction->operand1.value.index_offset = atoi(r_instruction->operand1);
        } else {
            parse_operand(r_instruction->operand1, &(b_instruction->operand1));
            parse_operand(r_instruction->operand2, &(b_instruction->operand2));
            parse_operand(r_instruction->operand3, &(b_instruction->operand3));
        }
        r_instruction++;
    }
}

/**
 * Main fonction of the compiler.
 * 
 */
void compileFile(char *file) {
    raw_instruction *r_instruction = parse(file);
    binary_instruction *b_instruction = process_raw_instruction(r_instruction);

    // Fonction antoine 

    free(r_instruction);
    free(b_instruction);
}