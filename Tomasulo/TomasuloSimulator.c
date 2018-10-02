/*
 * TomasuloSimulator.c
 *
 *  Created on: Oct 1, 2015
 *      Author: DebashisGanguly
 */

#include "./Global/TomasuloSimulator.h"

int numberOfIntRegisters = 32; //NIR
int numberOfFPRegisters = 32; //NFPR

int instructionCacheBaseAddress = 1000; //ICBA

int cacheLineSize = 4; //CLS
config configuration = {4,8,4,4};

int main(int argc, char** argv) {
	//Validate command line argument
	/*if (argc != 2) {
		printf ("USAGE: TomasuloSimulator <benchmark_file>\n");
		exit (EXIT_FAILURE);
	}*/

	fillInstructionAndDataCache ("Benchmarks/Test1.dat"/*argv[1]*/); //call loader to fill caches

	printInstructionCache (); //print instruction cache

	printDataCache ();

	printCodeLabels (); //print data cache

	initializeCPU (); //initialize CPU data structure

	IF_UNIT IF_unit;
	initialize_IF(&IF_unit);

	ID_UNIT ID_unit;
	initialize_ID(&ID_unit);

	FPadd_UNIT FPadd_unit;
	initialize_FPadd(&FPadd_unit);

	runClockCycle_IF(&IF_unit);


	while (runClockCycle()); //loop emulating simulator clock cycles

	printDataCache (); //print data cache


	printIntegerRegisters (); //print integer registers
	printFPRegisters (); //print floating point registers

	return 0;
}
