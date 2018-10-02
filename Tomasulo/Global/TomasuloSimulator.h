/*
 * TomasuloSimulator.h
 *
 *  Created on: Oct 1, 2015
 *      Author: DebashisGanguly
 */

#ifndef GLOBAL_TOMASULOSIMULATOR_H_
#define GLOBAL_TOMASULOSIMULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./DataTypes.h"
#include "./ADT/CircularQueue.h"
#include "./ADT/Dictionary.h"

//macros for parsing and tokenizing
#define DATA_LABEL "DATA"
#define WHITE_SPACE " \t\n"
#define LINE_TERMINATOR "\n"
#define LABEL_TERMINATOR ":"
#define LABEL_TERMINATOR_CHAR ':'
#define MEMORY_LABEL "Mem"
#define MEMORY_SEPARATOR " )(=\n"



//global variables populated from configuration
int numberOfIntRegisters; //NIR
int numberOfFPRegisters; //NFPR

int instructionCacheBaseAddress; //ICBA

int cacheLineSize; //CLS

int numberOfInstruction;

config configuration;

Dictionary *instructionCache;
Dictionary *dataCache;
Dictionary *codeLabels;


CPU *cpu;

void fillInstructionAndDataCache (char *fileName);

void initializeCPU ();

int runClockCycle ();

int initialize_IF(IF_UNIT *IF_unit);
int runClockCycle_IF(IF_UNIT *IF_unit);

int initialize_ID(ID_UNIT *ID_unit);
int runClockCycle_ID(ID_UNIT *ID_unit, IF_UNIT *IF_unit);

int initialize_FPadd(FPadd_UNIT *FPadd_unit);
int runClockCycle_FPadd(FPadd_UNIT *FPadd_unit, ID_UNIT *ID_unit);


void printInstructionCache ();
void printCodeLabels ();
void printDataCache ();
void printIntegerRegisters ();
void printFPRegisters ();

#endif /* GLOBAL_TOMASULOSIMULATOR_H_ */
