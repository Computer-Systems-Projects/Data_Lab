/* 
 * CS:APP Data Lab 
 * 
 * <Broderick Frankovich and userid here>
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
  2. Performs right shifts arithmetically and a negative shift value results in zero.
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


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x&~y); // uses De Morgans law, the inside parethesis results ina binary where only bits that are 0 in both x and y are 1
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  return !x; // standard use of not
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  
  return ~(1<<31); // puts a 1 in the first bit position
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    int mask = 0xAA | 0xAA << 8 | 0xAA << 16 | 0xAA << 24; // create mask in the form of 1010101...
    x = x&mask;
    return !!x; // two nots turn anything that isn't zero to a 1;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift_num = 32 + (~n+1); // (~n + 1) is a negative n, so it puts num shift to 32-n

  return !(x ^ ((x<<shift_num)>>shift_num)); //takes advantage of unpredicatable behavior when overflow happens while shifting
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  return x & (~x +1); // compares x to -x to find lowest bit
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int is_neg = x >> 31; // holds 1 if x is negative
  int is_less_30 = x + (~0x30 + 1); // x - 0x30
  int is_more_39 = 0x39 + (~x+1); // 0x39 - x
  return !((is_less_30 >> 31) | (is_more_39 >> 31)) & (!is_neg); // checks if less than 30 and more than 90 are signed negative| also returns 0 if x is negative
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int is_x_negative = x >> 31; // holds 1 if x is negative
  int is_y_negative = y >> 31; // holds 1 if y is negative
  int x_neg_y_pos = is_x_negative & (!is_y_negative); // holds 1 if x is - and y is +
  int same_sign = !(is_x_negative ^ is_y_negative); // holds 1 if x and y have same sign
  int overflow = (x^y) >> 31; // holds 1 if x and y have different signs
  int less_or_equal = (((x + (~y + 1)) >> 31)); // holds 1 if x < y by subtractingy from x and seeing if it overflows into the signed bit
  int equal = !(x ^ y); // holds 1 if x = y
  return x_neg_y_pos | (same_sign & (overflow | less_or_equal | equal)); //returns 1 if x is <= y

}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  //create masks to block off bytes. 0xff = 0000 0000 0000 1111
  int mask_byte_one = 0xff; 
  int mask_byte_two = mask_byte_one << 8;
  int mask_byte_three = mask_byte_one << 16;
  int mask_byte_four = mask_byte_one << 24;

  //isolate bytes, move to right position, then apply mask for that position to eliminate any remaing 1s from shifts
  int byte_one = ((x&mask_byte_one) << 24) & mask_byte_four;
  int byte_two = ((x&mask_byte_two) << 8) & mask_byte_three;
  int byte_three = ((x&mask_byte_three)>> 8) & mask_byte_two;
  int byte_four = ((x&mask_byte_four) >> 24) & mask_byte_one;

  //return the reveresed Bytes by combining them with OR's
  return ( byte_one | byte_two | byte_three | byte_four);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // construct masks over all 32 bits
    int mask55 = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24); // 0x55 == 01010101
    int mask33 = 0x33 | (0x33 << 8) | (0x33 << 16) | (0x33 << 24);// 0x33 == 00110011
    int mask0F = 0x0F | (0x0F << 8) | (0x0F << 16) | (0x0F << 24);// 0x0F == 00001111
    int mask01 = 0x01 | (0x01 << 8) | (0x01 << 16) | (0x01 << 24);// 0x01 == 00000001

    // create 2 bit groups
    x = (x & mask55) + ((x >> 1) & mask55); // adds each bit to the bit to the right, counts bits in each 2 bit set  

    // create 4 bit groups
    x = (x & mask33) + ((x >> 2) & mask33); // sums 2 bit sums to 4 bit counts.

    //create 8 bit(Byte) groups
    x = (x + (x >> 4)) & mask0F; // sums 4 bit pairs into 8 bit groups

    //sums all byte counts into the last byte of x
    x = (x + (x >> 8));
    x = (x + (x >> 16));

    // return last bit, which contains the sum of all bits
    return x & 0xFF;
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
  int negative_x = ~x + 1; // holds -x
  int sign = (x|negative_x) >> 31; // holds -1 in any case other than if x = 0, as x and negative x are the same
  return (sign & 1) ^ 1;
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
  int eights = x >> 3; // divide x by 8 done first to avoid overflow
  int rem = x & 7; // holds remainder of x/8 7 = 111, giving least signifacant 3 bits
  return eights + (eights << 2) + (rem + (rem << 2) + (x >> 31 & 7) >> 3);
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned opeartions incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
   //check if float is Nan(Not a number), first 9, exluding bit 1 are not all 1, and last 8 are not all 0's
    if (((uf >> 23) & 0xFF) == 0xFF && (uf & 0x7FFFFF) != 0) { // 0xFF == 11111111
        return uf; // return argument due to it being Nan
    }

    return uf ^ 0x80000000; // 0x80000000 has a 1 at bit 1, the rest are 0. Xoring this negates uf
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
  unsigned int exponent = (uf >> 23) & 0xFF; // pulls exponent of uf,( bits 2 - 9) 0xFF = 111111111
  unsigned int sign_bit = uf & 0x80000000; // pulls the sign bit, 1st bit

  //check if uf is Nan
  if(exponent == 0xFF && (uf & 0x7FFFFF) != 0){
    return uf; // return uf due to uf being Nan
  }

  //check if exponent is zero, so uf is de-normalized
  if(exponent == 0){
    uf = (uf & 0x007FFFFF) << 1 | sign_bit; // shift the right most section of bits by 1

    //check overflow by checking if sign bit has changed
    if(uf & 0x80000000 != 0){
      //set uf to Nan
      uf = uf & (~0x007FFFFF); // 0x007FFFFF 23 least significant bits are 1, rest are 0s
      uf = uf | 0x00800000;// 0x00800000 is a 1 at bit position 9, 0s elsewhere
    }
  }else{ // normalized, uf exponent is an integer
    uf = uf + 0x00800000; // incremement exponent, effectively multiplying by 2, 0x00800000 is a 1 at bit position 9, 0s elsewhere

    //set uf to Nan if overflow has occured
    if ((uf & 0x7F800000) == 0x7F800000) { // 0x7F800000 is a number with bits 2-9 being 1, and the rest being 0
            uf = sign_bit | 0x7F800000; // set uf to Nan, preserving the signed bit
        }
  }
  return uf; // return value
}
