/*
 * Arquivo: stddef.h 
 *
 * About:
 *     Header for standard defines. C99.
 *
 */
 
 
/* 
    @todo:
Macros:
   NULL
   offsetof(,);

Variables:
    typedef ptrdiff_t
    typedef wchar_t
    typedef size_t
*/


/*
 * NULL HANDLE. 
 *
 * Obs: 
 *     This define is also in types.h.
 */ 
#define NULL ((void *)0)


/*
 * Signed integral type of the result of subtracting two pointers.
 */
typedef int ptrdiff_t;

  
/*
 * Integral type whose range of values can represent distinct 
 * wide-character codes for all members of the largest character set 
 * specified among the locales supported by the compilation environment:
 * the null character has the code value 0 and 
 * each member of the Portable Character 
 * Set has a code value equal to its value when used as 
 * the lone character in an integer character constant.
 */ 
typedef int wchar_t;


/* 
 * which is the unsigned integer type of the result of the sizeof operator;   
 */
//typedef unsigned int size_t;
typedef int size_t;


/*
 * offset_of - "Deslocamento dentro de uma estrutura"
 */
#define offset_of(tp, member) (((char*) &((tp*)0)->member) - (char*)0)


//
//fim.
//

