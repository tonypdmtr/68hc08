# soft_sci
Software SCI driver for 68HC08/HC08/9S08/S08 MCUs.

Particularly useful for those smaller variants that do not have a built-in SCI module.

(Requires [ASM8](http://www.aspisys.com/asm8.htm) assembler)

It's possible to implement a 100% software UART (even having different baud rates for TX and RX, if you like). 

The whole concept is based on relatively accurate bit timing (there a small allowance of baud rate mismatch).

The idea is pretty much this:

For RX:
 

* You need a half-bit time delay, and a full bit time delay for the baud rate you need.
* You poll and wait for a start bit edge (a zero, normally -- unless your line is inverted).
* Once you get the start bit, you wait half bit to go to the center of the bit for sampling.
* Then you enter a loop starting with a full bit delay (this will bring you to the center of the first data bit).
* You read the RX line's state (you can even make multiple reads -- say, 3) to eliminate possible noise on the line.  You accept what the majority of the reads give you.
* You shift the bit into the most significant bit of your data byte (a rotate right in assembly)
* You repeat the loop for 8 bits and you're done.

For TX:

* You only need a full bit time delay routine.
* You do the start  bit (normally, a zero).
* You delay for a bit time.
* You shift out the next bit (rotate right).
* Depending on the shifted out bit being 0 or 1 you set the TX line accordinly.
* You repeat the loop for 9 bits (start plus 8 data) and you're done.
* Don't forget to leave the TX line high (and wait a bit time) for stop bit.
