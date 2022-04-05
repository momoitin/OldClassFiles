/* instruction-level simulator for LC3100 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bitset>

using namespace std;

#define NUMMEMORY 65536 /* maximum number of words in memory */
#define NUMREGS 8       /* number of machine registers */
#define MAXLINELENGTH 1000

typedef struct stateStruct
{
    int pc;
    int mem[NUMMEMORY];
    int reg[NUMREGS];
    int numMemory;
} stateType;

void printState(stateType *);
void addState(stateType *, int regA, int regB, int destReg);
void haltState(stateType *);

int main(int argc, char *argv[])
{
    char line[MAXLINELENGTH];
    stateType state;
    FILE *filePtr;

    if (argc != 2)
    {
        printf("error: usage: %s <machine-code file>\n", argv[0]);
        return 1;
    }

    filePtr = fopen(argv[1], "r");
    if (filePtr == NULL)
    {
        printf("error: can't open file %s", argv[1]);
        perror("fopen");
        return 1;
    }

    /* read in the entire machine-code file into memory */
    for (state.numMemory = 0; fgets(line, MAXLINELENGTH, filePtr) != NULL; state.numMemory++)
    {
        if (sscanf(line, "%d", state.mem + state.numMemory) != 1)
        {
            printf("error in reading address %d\n", state.numMemory);
            return 1;
        }
        printf("memory[%d]=%d\n", state.numMemory, state.mem[state.numMemory]);
    }

    // set default register state
    for (int i = 0; i < NUMREGS; i++)
    {
        state.reg[i] = 0;
    }

    int opcode = 0;
    for (int i = 1; opcode != 6; i++)
    {
        // fetch the opcode
        opcode = (state.mem[state.pc] >> 22);

        int regA = (state.mem[state.pc] - (opcode << 22) >> 19),
            regB = (state.mem[state.pc] - (regA << 19) - (opcode << 22) >> 16),
            regDest = (state.mem[state.pc] - (regB << 16) - (regA << 19) - (opcode << 22)),
            //calculate the offset which is the same as an R-type destination
            offset = (((~regDest >> 15) + 1) << 15) | regDest;

        // cout << "Opcode:  " << opcode << "    bits: " << bitset<25>(opcode) << endl;
        // cout << "regA:    " << regA << "      bits: " << bitset<25>(regA) << endl
        //      << "regB:    " << regB << "      bits: " << bitset<25>(regB) << endl
        //      << "destReg: " << regDest << "   bits: " << bitset<25>(regDest) << endl
        //      << "offset:  " << offset << "    bits: " << bitset<64>(offset) << "\n\n";

        printState(&state);
        switch (opcode)
        {
        // add (R-type format)
        case 0:
            addState(&state, regA, regB, regDest);
            state.pc += 1;
            break;

        // nand (R-type format)
        case 1:

            state.reg[regDest] = ~(state.reg[regA] & state.reg[regB]);
            state.pc += 1;
            break;

        // lw (I-type format)
        case 2:
            state.reg[regB] = state.mem[state.reg[regA] + regDest];
            state.pc += 1;
            break;

        // sw (I-type format)
        case 3:
            state.pc += 1;
            break;

        // beq (I-type format)
        case 4:
            if (state.reg[regA] == state.reg[regB])
            {
                state.pc = state.pc + 1 + offset;
            }
            else
            {
                state.pc += 1;
            }
            break;

        // xxx (O-type format) unused
        case 5:
            break;

        // halt (O-type format)
        case 6:
            state.pc += 1;
            cout << "machine halted\n";
            cout << "total of " << i << " instructions executed\n";
            cout << "final state of machine:\n";
            printState(&state);
            return 0;

        // noop (O-type format)
        case 7:
            break;
        }
    }
    return 0;
}

void addState(stateType *statePtr, int regA, int regB, int destReg)
{
    statePtr->reg[destReg] = statePtr->reg[regA] + statePtr->reg[regB];
}

void printState(stateType *statePtr)
{
    int i;
    printf("\n@@@\nstate:\n");
    printf("\tpc %d\n", statePtr->pc);
    printf("\tmemory:\n");
    for (i = 0; i < statePtr->numMemory; i++)
    {
        printf("\t\tmem[ %d ] %d\n", i, statePtr->mem[i]);
    }
    printf("\tregisters:\n");
    for (i = 0; i < NUMREGS; i++)
    {
        printf("\t\treg[ %d ] %d\n", i, statePtr->reg[i]);
    }
    printf("end state\n");
}