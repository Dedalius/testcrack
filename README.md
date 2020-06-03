THE PROGRAM IS DESIGNED FOR THE WINDOWS OPERATING SYSTEM

Often, during contests, my friend faced the problem of finding an erroneous test.
Of course, you can write a program in the bash language that can cope with this problem, but this is just not suitable for novice coders, and the windows 1909 build changed the way to run .bat. This is what prompted me to write this code

---------------------------------------------------Now about the installation method--------------------------------------------------

Since the program works by passing arguments, it is ideal for cmd, so you need to write it in PATH in the windows environment variables section

To do this, write a new argument in PATH and specify the path to the file bin/Release/testcrack.exe
We should get the following:

![Image alt](https://sun9-59.userapi.com/c857232/v857232827/1af639/_GYSnKHRjPs.jpg)


----------------------------------------------------How to work with this---------------------------------------------------------------

Let's get acquainted with the principle of operation. By entering testcrack in cmd, we should also pass 3 more mandatory and 2 optional arguments there. First, you should pass the path to the test generator in .exe format(since everything will be executed in the same directory as the files themselves, you just need to specify their name), and then the path to 2 programs, the difference in the execution of which we want to find. It is also worth noting that the test generator must provide for transmitting input data directly to the programs themselves, as for the programs, they must transmit output information to any files(by default, output1 and output2), this path or name can be changed by passing an optional orgument-o1 (or o2) PATH\TO\FILE, this is the file testcrack will search for

For example I created 2 simple programs and a test generator for them

![Image alt](https://sun9-53.userapi.com/c858016/v858016702/2052f4/e4TS59g5l7M.jpg)


Then I compiled them and put them in a folder of this type:
![Image alt](https://sun9-17.userapi.com/c858016/v858016702/2052b5/Kw7D0uIc-T8.jpg)
As you can see the input output folders contain input and output data respectively



And now to the most interesting, to the work of the software
![Image alt](https://sun9-37.userapi.com/c858016/v858016702/205307/oq2CS3pr8J4.jpg)

As you might have noticed 2.exe with a probability of 1/100, it could return not a + b, but a + b + 1, which is exactly what testcrack found


