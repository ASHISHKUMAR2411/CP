factsAboutOperator
//NOTE : factsAboutOperator
Operator precedence determines which operator is performed first in an expression with more than one operators with different precedence.

Operators Associativity is used when two operators of same precedence appear in an expression. Associativity can be either Left to Right or Right to Left.

Operators Precedence and Associativity are two characteristics of operators that determine the evaluation order of sub-expressions in absence of brackets 

2) All operators with the same precedence have same associativity
This is necessary, otherwise, there won’t be any way for the compiler to decide evaluation order of expressions which have two operators of same precedence and different associativity. For example + and – have the same associativity.

3) Precedence and associativity of postfix ++ and prefix ++ are different
Precedence of postfix ++ is more than prefix ++, their associativity is also different. Associativity of postfix ++ is left to right and associativity of prefix ++ is right to left.
4) Comma has the least precedence among all operators and should be used carefully

Operator

Description	 Associativity

( )          Parentheses (function call) (see Note 1)
[ ]          Brackets (array subscript)
.            Member selection via pointer
->           Postfix increment/decrement (see Note 2)	


                left-to-right
                
++ —         sizeof	Prefix increment/decrement
+ –          Unary plus/minus
! ~          Logical negation/bitwise complement
(type)       Cast (convert value to temporary value of type)
*            Dereference
&            Address (of operand)






Determine size in bytes on this implementation	right-to-left
*  /  %	    Multiplication/division/modulus	left-to-right
+  –	    Addition/subtraction	left-to-right
<<  >>	    Bitwise shift left, Bitwise shift right	left-to-right
<  <=       Relational less than/less than or equal to
>  >=	    Relational greater than/greater  than or equal to	left-to-right
==  !=	    Relational is equal to/is not equal to	left-to-right
&	        Bitwise AND	left-to-right
^	        Bitwise exclusive OR	left-to-right
|	        Bitwise inclusive OR	left-to-right
&&	        Logical AND	left-to-right
| |	        Logical OR	left-to-right
? :	        Ternary conditional	right-to-left
=	        Assignment
+=  -=      Addition/subtraction assignment
*=  /=      Multiplication/division assignment
%=  &=      Modulus/bitwise AND assignment
^=  |=      Bitwise exclusive/inclusive OR assignment
<<=  >>=    Bitwise shift left/right assignment	right-to-left

,           Comma (separate expressions)	left-to-right


