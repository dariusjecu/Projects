Challenge 2 - @at2-ispas & @d2-jecu
There are two separate files (one for receiving and one for sending)
Note that I worked closely with a friend (Andrei Ispas) on this project due to us both only having one Microbit each and both had to be connected together to properly test throughout.
Executing:

The user must first connect two micobits via cables, leading to a usb connection into the chosen workstation.
Next the user can communicate the sending cpp file (send.cpp) to the microbits which they want sending and the receive.cpp file to the microbit they want receiving.
After that you can Build the project as normal with the YT build command.

While the sending microbit has two functions (buttons A and B), the receiving microbit will have no functionality

<holding for <=0.25 Seconds will give you "dot">
0.25 seconds but <=0.5 seconds will give you "dash">
<By pressing button "B">
<For <=0.25 seconds if a valid morse code is entered, the char of this morsecode should be outputted on the microbit's screen and will add it to an array(to form a word up to 5 chars)>
0.25 seconds but <=0.5 seconds sending the times to the other microbit.>
When the other microbit receives the information, the two microbits will display the text which is initially sent.
