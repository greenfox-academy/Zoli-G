# Final exam requirements

## Accomplishments

 -  Significant contribution to the team project

## Skills

The student, on their own, is able to:

 -  Use the command line:
     -  Traversing directories: `cd, cd ..`
     -  Moving, copying, creating, deleting files: `mv filename path | cp filename newfilename | touch newfile | rm filename`
     -  Passing command line arguments to commands: `git commit -m`
 -  Use git:
     -  Commit, add, push, pull: `save new state and name it | add files to track changes | upload | download`
     -  Resolving a simple merge conflict: `decide which version to keep between HEAD & TAIL`
     -  Creating a pull request: `ask permission to merge my codes into one level upper`
 -  Follow indentation and coding styleguides in their code


 -  Use the key elements of C language:
     -  Variables (local, global, const, static, extern): `int-uint, short, long, float, double, char, pointer, enum, type, struct, union` `in function | over main() | not changeable | keep its value | use var in other file functions`
     -  Expressions and control flow (operators, if/else, switch/case): `arithmetic: +-*/ assign: = logic: >= <= < > == != && || bitwise: | & < >, comma: , ternary: ? : macro: #`
     `if (logic exp) {do stuff} else if (logic exp2) {do stuff} else {do stuff}`
     `switch (num variable) {case X: ...; break; case Y: ...; break; default: ...;}`
     -  Loops (for, while, do/while)
     -  Functions: `Separating code, and helps preventing code duplication`
     -  Pointers and arrays: `Pointer: stores memory address, array: stores same type variables`
     -  Data structures (struct, enum, union): `Struct: object-var stores different, but logically depending vars | enum: naming numerical values to human readable word | union: special struct, only one var is usable at a time, size is the biggest`
     -  Preprocessor macros (include, ifdef, define, etc.): `include: link header files | ifdef: inside header file the contents do not gets included if already included | define: name constanat values`
 -  Use basic standard C libraries
     -  stdint.h types: `integer types: 8-16-32-64 bits + macros for max,min values etc.`
     -  string.h functions (memcpy, memset, strcat, strcmp, strcpy, strstr, strtok): `memcpy: copies given bytes from param2 to param1 | memset: sets the first x bytes to the given value of an array | strcat: copies to param1 the string in param2 | strcmp: compares two strings, 0 if identical | strcpy: copy a string to param1 from param2 | strstr: Returns a pointer to the first occurrence of str2 in str1 | strtok: slice up string by delimiters`
     -  stdio.h functions (fopen, fread, fwrite, fclose, gets, puts, scanf, printf): `fopen("myfile.txt","w") - opens file with the given access | fread(buffer,1,lSize,pFile) - reads given no of bytes from file to a buffer | fwrite(buffer, sizeof(char), sizeof(buffer), pFile) - write given buffer to file | gets(buffer) - get a string from input to buffer | puts(buffer) - writes buffer to output | scanf("%d",&i) - get data from input | printf - print data in format to output`     
 -  Use C++
     -  Class, inheritance: `class is a blueprint of the object, an object has various attributes/different types of variables` `Inheritence: base class -> derived class with overwriting functions`
     -  Vector, polymorphism: `advanced type of array, with built-in functions` `Polym: `
     -  Operator  
 -  Determine the output of expressions
 -  Handle errors: `try {} catch () {}`
 -  Explain their own code
 -  Separate functionalities to different files
 -  Include and call 3rd party libraries in their code


 -  Understand basic electronic schematics:
     -  Voltage divider (output voltage calculation)
     -  LED current limiting resistor calculation
 -  Explain how does open-loop and closed-loop control works
 -  Convert binary, decimal and hexadecimal numbers into each other
 -  Use a microcontroller:
     -  Know what are the differences between PC and uC: `PC is running an OS and capable to work universally, a uC is doing what the actual program does`
     -  Basic understanding of peripherals:
        - GPIO: `Pins for input, output and AF`
        - Timers (basic, input capture, output compare/pwm) `Generates clock signal divided from the CPU, IC: measure, OC: PWM`
     -  Serial communication (simplex `can receive or transmit`, half-duplex `both, both not the same time`, duplex `both at the same time`, synchronous `share same clock signal`, asynchronous `no clock signal`)
        - UART: `2 cable, slow, async, one-to-one`
        - I2C: `4 cable, higher, sync, master-slave`
        - SPI: `2 wire bus, highest, sync, master-slave`
  -  Explain what a hardware abstraction layer is
     -  For example on the STM32 Cube platform: `give a standard platform for different hardwares, connects software to HW`
     -  Why do we use it, what is it, how does it works `easier to use, not needed to code in assy and do works in registry level. Each HAL function represents a basic programmer element, containing lot of HW instructions`


 - Labview for extra points:
      - What is a virtual instrument
      - What is it used for
      - Error handling, file IO, programing structures, state machine

## *Technical preparation*

For the final exam, please prepare links to your GitHub repository for each of these topics:

  - Your impact on your project team [PWM](https://github.com/greenfox-academy/Static-DrawingRobot/blob/Development-Zoli/DrawingRobot/src/PWM.c), [Stepper](https://github.com/greenfox-academy/Static-DrawingRobot/blob/Development-Zoli/DrawingRobot/src/STEPPER.c), [GPIO](https://github.com/greenfox-academy/Static-DrawingRobot/blob/Development-Zoli/DrawingRobot/src/GPIO.c), [LCD GUI](https://github.com/greenfox-academy/Static-DrawingRobot/blob/Development-Zoli/DrawingRobot/src/LCD_GUI.c)
  - Something that contains multiple uC peripherals `see above`
   - Control loop project for example [PI fan control](https://github.com/greenfox-academy/Zoli-G/tree/master/week-09/day-4%265/PI_FAN_controller)
  - Something that contains custom struct definitions and command parsing `see below todo-app`
   - ToDo app for example [ToDo-App](https://github.com/greenfox-academy/Zoli-G/tree/master/week-04/day4%265%20-%20ToDoApp)

*Important:* No code example provided means ZERO point. (Oh, no...)
