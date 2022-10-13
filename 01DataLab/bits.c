/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //return (!(!(x))) & !(~(x ^ (x + 1))) & !(!(x + 1));
  return !(~(x ^ (x + 1))) & !(!(x + 1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  return !((x & (x >> 8) & (x >> 16) & (x >> 24) & 0xAA) ^ 0xAA);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
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
  int low = x & 0xF;
  int y = low + 6;
  return (!(((x >> 4) & 0xF) ^ 0x3)) & !(x >> 8) & !(y >> 4);
  //return ((!(((x >> 4) & 0xF) ^ 0x3)) & ((!((x & 0xF) ^ 0x9)) | (!((x & 0xF) ^ 0x8)) | (!((x & 0xF) & 0x8)))) & !(x >> 8);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*int m = !x;
  int k = ((m << 1) + m);
  int j = ((k << 2) + k);
  int l = ((j << 4) + j);
  int i = ((l << 8) + l);
  int p = ((i << 16) + i);
  return  ((~p) & y) | ((p) & z);*/
  x = !!x;
  x = ~x + 1;
  return (x & y) | (~x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*unsigned x_bak = x;           //获取符号位，先将数转化为无符号数，在进行算术右移（此时其实为逻辑右移）
  int x_opera = (x_bak >> 31);  
  unsigned y_bak = y;
  int y_opera = (y_bak >> 31);
  int ans = ~x + 1 + y;
  unsigned res = ans;
  return (!((x_opera ^ 1) & (y_opera ^ 0))) & (((x_opera ^ y_opera) & x_opera) | ((res >> 31) ^ 1));*/
  int x_neg = ~x + 1;
  int ans = x_neg + y;
  int checkSign = ans >> 31 & 0x1;
  int leftBit = 1 << 31;
  int x_left = x & leftBit;
  int y_left = y & leftBit;
  int bitXor = x_left ^ y_left;
  bitXor = bitXor >> 31 & 0x1;
  return ((!bitXor) & (!checkSign)) | ((bitXor)&(x_left >> 31));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*int var = (~x + 1);       //0取反加1还是本身
  int res = (var & x);      //一个数与相反数相与得到第一个非0位
  unsigned ans = (~res + 1);
  ans = ans >> 31;
  return (ans ^ 1);*/
  return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int sign = x >> 31;
  x = (~sign & x) | (sign & ~x);

  int b16, b8, b4, b2, b1, b0;
  b16 = !!(x >> 16) << 4;
  x = x >> b16;
  b8 = !!(x >> 8) << 3;
  x = x >> b8;
  b4 = !!(x >> 4) << 2;
  x = x >> b4;
  b2 = !!(x >> 2) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  x = x >> b1;
  b0 = !!(x);

  return b0 + b1 + b2 + b4 + b8 + b16 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /*
  int sign = uf >> 31;
  int exp = uf >> 23;
  exp = (exp & 0xFF);
  int tail = (uf & 0xFF) + (((uf >> 8) & 0xFF) << 8) + (((uf >> 16) & 0x7F) << 16);
  if(exp == 0)
    return (tail * 2) + (sign << 31);
  else if(exp == 0xFF)
    return uf;
  else
    return ((exp + 1) << 23) + tail + (sign << 31); //未考虑*2后，指数位变为255的情况
  */
    //(tail * 2) + (sign << 31) + 
  //return ((exp ^ 0xFF) + 1) * uf;

  int exp = (uf & 0x7f800000) >> 23;
  int sign = uf & (1 << 31);
  if(exp == 0)
    return uf << 1 | sign;
  if(exp == 255)
    return uf;
  exp++;
  if(exp == 255)
    return 0x7f800000 | sign;
  return (exp << 23) | (uf & 0x807fffff);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
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
int floatFloat2Int(unsigned uf) {
  /*
  int sign = uf >> 31;
  if(sign == 0)
    sign = 1;
  else
    sign = -1;
  int exp = (uf & 0x7f800000) >> 23;
  //exp = (exp & 0xFF);
  float tail = (uf & 0xFF) + (((uf >> 8) & 0xFF) << 8) + (((uf >> 16) & 0x7F) << 16);
  tail = tail * (1 >> 23);
  if(exp == 0)
    return 0;
  else if(exp == 0xFF)
    return 0x80000000;
  else
    if(exp -127 < 0)
      return 0;
    if(exp - 127 > 31)
      return 0x80000000;
    return sign * (1 << (exp - 127)) * (1 + tail);  //未考虑正整数移动31位溢出情况
  */
  int sign_ = uf >> 31;
  int exp_ = ((uf & 0x7f800000) >> 23) - 127;
  int frac_ = (uf & 0x007fffff) | 0x800000;
  if(exp_ > 31) return 0x80000000;
  if(exp_ < 0) return 0;

  if(exp_ > 23) frac_ <<= (exp_ - 23);
  else frac_ >>= (23 - exp_);

  if(!(frac_ >> 31) ^ sign_) return frac_;
  else if(frac_ >> 31) return 0x80000000;
  else return ~frac_ + 1;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  /*
  if(x < -149)
    return 0;
  else if(x <= 0)
    return 127 << 23;
  else if(x > 127)
    return 0x7F800000;
  else
    return (x + 127) << 23;
    */
  if(x < -149)
    return 0;
  if(-149 <= x && x < -126)
    return 0x1 << (x + 149);
  if(-126 <= x && x <= 128)
    return (x + 127) << 23;
  else
    return 0x7F800000;
}
