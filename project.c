#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
//Read the registers addressed by r1 and r2 from Reg, and write the read values to data1 and data2
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
//Assign the sign-extended value of offset to extended_value.
void sign_extend(unsigned offset,unsigned *extended_value)
{
  //Checks if negative
    if((offset >> 15) == 1)
    {
      *extended_value = offset | 0xFFFF0000;
    }
    //Checks if positive
    else
    {
      *extended_value = offset & 0x0000ffff;
    }
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
//Update the program counter
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
  //Increment PC by 4 after each update
  *PC += 4;

  //Checks to see if Branch and Zero is in ALU
  if(Branch == 1 && Zero == 1)
  {
    //Extended value is added to PC
    *PC += (extended_value << 2);
  }
  //If Jump occurs, shift left two times
  if(Jump == 1)
  {
    *PC =  (*PC & 0xf000000) | (jsec << 2);
  }
}
