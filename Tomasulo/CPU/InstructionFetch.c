# include "../Global/TomasuloSimulator.h"

int getHashCodeFromCacheAddress (void *address);
int compareBTBValues (void *btbvalue1, void *btbvalue2);


void initializeIF_Unit() {
    BTB = createDictionary(getHashCodeFromCacheAddress, compareInstructions);

}

void fetch_instruction() {

}

int getHashCodeFromCacheAddress (void *address) {
    int mask = 0b0000000011110000;
    int result = *((int*)address) & mask;
    result = result >> 4;
    result = result << 24;
    return result;
}


int compareBTBValues (void *btbvalue1, void *btbvalue2) {
    return *((BTB_value*)btbvalue1)  - *((BTB_value*)btbvalue2);
}