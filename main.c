#include <stdio.h>
#include <stdbool.h>

bool running = true;
int instructionPointer = 0;
int stackPointer = -1;
int stack[256];

typedef enum 
{
    PSH,
    ADD,
    POP,
    HLT
} InstructionSet;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int fetch()
{
    return program[instructionPointer];
}

void eval(int instr)
{
    switch (instr)
    {
        case HLT:
        {
            running = false;
            printf("done\n");
            break;
        }
        case PSH:
        {
            stackPointer++;
            stack[stackPointer] = program[++instructionPointer];
            break;
        }
        case POP:
        {
            int val_popped = stack[stackPointer--];
            printf("popped %d\n", val_popped);
            break;
        }
        case ADD:
        {
            int a = stack[stackPointer--];
            int b = stack[stackPointer--];
            int result = b + a;
            stackPointer++;
            stack[stackPointer] = result;
            break;
        }
    }
}

int main(void)
{
    while (running)
    {
        eval(fetch());
        instructionPointer++;
    }
}