
#include "../Global/TomasuloSimulator.h"

int initialize_IF(IF_UNIT *IF_unit)
{
    IF_unit->n_instructions = 0;
    IF_unit->PC = instructionCacheBaseAddress;
}


int runClockCycle_IF(IF_UNIT *IF_unit){
    int i;
    for(i=0; i<configuration.NF; i++){
        if (IF_unit->PC >= (instructionCacheBaseAddress + (cacheLineSize * numberOfInstruction))) { //check whether PC exceeds last instruction in cache
            printf ("All instructions finished...\n");
            break;
        }


        DictionaryEntry *currentInstruction = getValueChainByDictionaryKey (instructionCache, &(IF_unit->PC));

        strncpy(IF_unit->instructions[i].instr, ((char*)currentInstruction -> value -> value), MAX_LINE);
        printf ("Fetched %d:%s\n", cpu -> PC, IF_unit->instructions[i].instr);

        IF_unit->PC = IF_unit->PC + 4;
        IF_unit->n_instructions = i+1;
    }
}
