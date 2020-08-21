 This project is just a project for educational purposes, so I do not recommend you to use it, in serious projects (commercial, ...).
 The reason is not that I do not believe in the implementation but it is not a finished project (e.g. I consider the entry to be valid instead of checking).
 If you do it is at your own risk!

 A brief summary of what is done in the code is:
 I take a string of character I turn it into an reverse Polish notation and then I evaluate the returned expression.

 I put the links that helped me during the implementation and recommend consulting them in the following order.


 The wikipedia link is just to get a general idea of the reverse Polish notation you can pass this step if you want.


	https://en.wikipedia.org/wiki/Reverse_Polish_notation

	https://youtu.be/LQ-iW8jm6Mk

	https://youtu.be/zMDm2MbRG6w

	https://youtu.be/7ha78yWRDlE

	https://youtu.be/TrfcJCulsF4



 I assume you know a little bit C++ so I won't explain the compilation!
 In short, to use it for a playful purpose of course you just have to clone
 the repo and then include the file "parser.h" so you will have access to two very useful 
 functions like evaluate_string (std::string) and evaluate_postfix_expression (Expression&)
 that return the result of the evaluation (in radian).
 The result brought back is a result close to what your scientific calculator will return reason.
 I have made it extendable in such way that you just have to add character that will represent an 
 operation and describe the calculation in calculate function so enjoy it.
 

