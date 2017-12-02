/* 
 * CS:APP Data Lab 
 * 
 * Peter Christakos pechristakos
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // DeMorgan's Law towards (~x & y) | (x & ~y)
    return ~(x & y) & ~(~x & ~y); 
   
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  // shift 0001 to the left 31 times to get the min (1000...)
  //  and use the not operator to get the max (0111...)
  return ~(1<<31);
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  /* apply xor to the x and y values
   * if they are the same the double negated result would be zero
   * if they are different, the logical not would make them a non-zero 
   * decimal and the second logical not would make it 1
   */ 
  return (!(!(x^y)));
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  // take the byte value of n and shift it to the left by 3
  int shift = n << 3;
  // take x, shift it to the right by the value of shift and use the operator
  // & with that as well as 0xff to copy over the byte that will be removed and then
  // shift it back
  int old_byte = ((x >> shift) & 0xff) << shift;
  // take out the byte we need to remove by doing 'x - old_byte'
  int new_byte = x + (~old_byte+ 1);
  // add in the new byte value shifted at the proper location
  return new_byte + (c << shift);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating : 2
 */
int fitsBits(int x, int n) {
  // shift x over 31 times, if x is positive, shift will be all 0's
  // if x is negative shift will be all 1's
  int shift = x >> 31;
  // n-1 because 2^0 is the first bit 
  int nbit = n+ ~1 + 1; // n-1
  // if x is positive, ~x will consist of many 0's and the last 4 bits will vary
  // if x is negative ~x will consist of many 1's and the last 4 bits will vary
  // using the & operator with ~x and shift will produce the same value as ~x if
  // x is negative and a different value otherwise  
  int value1 = (~x & shift);
  // if x is positive, ~shift will be all 1's, all 0's otherwise
  // using the & function on x and ~shift will carry over the x value
  int value2 = (x & ~shift);

  //if x is truly n-bit then at this point value 1 and value 2 should be the same
  // in the example fitsBits(-4,3), value1 and value2 would both be 1111...1100
  // and adding them together will create all 0's and the logical not will return
  // a 1. Otherwise logical not will return a 0.
  return !((value1 +  value2) >> nbit);  
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 250                     
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  // x_with_zero = take the input x and right shift it by the value of n
  // this will leave all 0's in place of where the rotation gets placed 
  int x_with_zero = (x << n);
  // produce zero's everywhere except where the new bytes will be rotated
  int rotation = (x >> (32 + ~n+1));
  // use this to prevent negative value input x's from affecting answer
  int neg_blocker = ~((~1+1) << n);
  return x_with_zero | (rotation & neg_blocker);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  // will return 0001 if number is a power of 2 and 0 otherwise
  int power = !(x & ~(~x + 1));
  // right shifts 31 spots and logical not which will produce 0001 unless
  // x is a negative number. Then use and function to compare with ~(!x) 
  // which will protect from x being 0
  // this int will only produce 1 if x is a positive nonzero
  int neg_checker = ((!(x >> 31)) & (~(!x)));
  // this will produce 1 if both a and b are 0001 (meaning x is positive nonzero
  // and power of 2), and will produce zero otherwise if either a or b is 0000
  return power & neg_checker;
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) { 
  // x = 15, n = 2
  // 1 << n = 0100
  //        + 1111
  //        = 0011
  int value1 = (1 << n) + ~0;
  // fills 32-bit zeros 0000...0000
  int zeros = x >> 31; 
  // 1111 & 0011 = 0011
  int value2 = x & value1;
  //  double logical not value2, if x is zero, it'll produce a zero, otherwise
  // a 1. This will change the value for negative x's
  int neg_checker = (((~((!!value2) << n)) + 1) & zeros);
  //   0011 + 0000 = 0011 = 3
  return value2 + neg_checker;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // sample input x=2, y=4, z=5
  // double locigal not to make x a boolean of 0 or 1
  int bool_x = !!x; 
  // bool_x - 1 for 2s complement
  int complement = ~bool_x + 1;
  // convert x into 2s complement (true = 1111 or false = 0000)
  // if complement is true  (complement & y)=y or (~complement & z) = 0
  // if complement is false (complement & y)=0 or (~complement & z) = z
  return (~complement & z) |(complement & y) ;
  
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

int bitParity(int x) {
 // check for even amounts of zeros
  x = x^ x >> 16;
  x = x^ x >> 8;
  x = x^ x >> 4;
  x = x^ x >> 2;
  x = x^ x >> 1;
  // if even will return 0
  return x & 0x01;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */

int greatestBitPos(int x) {
  // most significant stays the same and & operator leaves the significant
  x = x | x >> 1;
  x = x | x >> 2;
  x = x | x >> 4;
  x = x | x >> 8;
  x = x | x >> 16;
  return x & ((~x >> 1) ^ (1 << 31));
  }
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

int logicalNeg(int x) {
  // transform x=0 into all 1's and use & function with 1.
  // otherwise produce 0
  int minus1 = ~x+1;
  int shift = ((~x & (~minus1)) >> 31);
  return shift & 1;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  // lab 2 in-class
  //           exp =  uf >> 23 (mantissa) & 0000...11111111
  unsigned int exp = (uf >> 23) & 0xFF;
  // 0 00000000 11111111111111111111111
  // isolate the mantissa from the uf
  int mant = uf & ~((1 << 31) >> 8);
  // checks if exp = 111..1 & that mant > 0 (NaN check)
  if ((exp == 0xFF) && mant) {
  // in which case just returns the original uf value 
    return uf; 
  } else {
    // return uf ^ 10000...0000 (change sign bit)
    return (uf ^ 0x80000000);
  } 
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) { 
  int exponent = (uf >> 23) & 0xFF; // exponent of float & 0000...1111 1111
  int mant = uf & 0x7FFFFF; //0111 1111 1111 1111 1111 1111
  int e = exponent + (~127 + 1); // exponent + 1111...00000000 + 1
  mant = mant | 0x800000; // mant

  // NaN check
  if(exponent == 0x7F800000) {
    return 0x80000000;
  }
  // zero check
  else if(e > 30) {
    return 0x80000000;
  }
  // checks to see if exponent is 0
  else if((!exponent) == 1) {
    return 0;
  }
  // out of range checker
  else if(e < 0) {
    return 0;
  } 
  // exponent check
  else if (e >= 23) {
    mant = mant << (e+ (~23+1)); 
  }
  else {
    mant = mant >> (23 + (~e+1)); //right shift
  }
  if(( uf >> 31 ) & 1) {
    return ~mant + 1; // return neg value for 1 sign bit
  }
  return mant; // return changed mant */
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  // right shift 23 times to remove mant and & with 0000...1111 1111
  // to copy exponent
  int exponent = (uf >> 23) & 0xFF;
   //check if uf is NaN.
  if(exponent == 0xFF){
    return uf;
  } 
  // if exponent value is 0
  else if(exponent == 0) {
    return (uf & (1<<31)) | (uf<<1);
  }
  // check if uf is 0 or Tmin
  else if(uf == 0 || uf == 0x80000000) {
    return uf;
  }
  // if uf is normal float, add 1 to exp create 2*f expression
  return uf + (1<<23);
}