MessageEncryption

## PURPOSE
This progam aims to protect confidential messages by an encryption-decryption process. If there are any private messages that needs to be passed from one entity to another, all that needs to be done is to encrypt the message using this program by providing an encryption keycode and the ID of the target encryption algorithm. Once sent, the receiver must know the keycode and the ID of algorithm used to be able to decrypt the message.

## REQUIREMENTS
1. GNU/Linux environment
    * Either:
        1. Full operating system
        2. Virtual machine (as a guest OS)
        3. Cygwin
        4. etc.
2. Git (optional if you just prefer to do a download and extract from GitHub)
    ~~~
    sudo apt install git
    ~~~
3. GNU Toolchain
    ~~~
    sudo apt install build-essential
    ~~~
4. CMake
    ~~~
    sudo apt install cmake
    ~~~
5. Boost
    ~~~
    sudo apt install libboost-all-dev
    ~~~

## BUILDING
~~~
git clone https://github.com/nponcian/MessageEncryption.git
cd MessageEncryption
mkdir -p build && cd build
cmake ..
~~~

## RUNNING
~~~
cd MessageEncryption/build
cmake ..
make
src/cipher_src --help

# Command format
# src/cipher_src [--encrypt|--decrypt] [../Path/To/File/Containing/Message] [keycode] [OPTIONAL: Algorithm ID to use [1]]

# This will write the encrypted message to <fileName>.output, which in this example would be to ../message.txt.output
src/cipher_src --encrypt ../message.txt somekeycode

# This will write the decrypted message to <fileName>.output, which in this example would be to ../message.txt.output.output
# The result would exactly be equal to the original message in ../message.txt
src/cipher_src --decrypt ../message.txt.output somekeycode
~~~

## TESTING
~~~
~~~

## EXAMPLE
* ../message.txt
~~~
I am,...

@Niel
Ponciano!

#3, #2, 1: ... *doing some ~programming! :)
Yes, the keycode might have those really elegant rings, but ain't no oxygen on that gas planet ^_^


sooooEarth is my favorite [%PLANET%]x99999!! Let us -reduce- OUR daily $production of ~~WASTE! :)
~~~

* Encrypt the message using keycode SaturnISc00L!
~~~
src/cipher_src --encrypt ../message.txt SaturnISc00L!
~~~

* ../message.txt.output
~~~
1cI!1tInI-I/I/I/IIIAIOIjIfImIIQIp1I10Ij1t1IIp1SIII$I4I-I!I$I3I-I!I2I;I!I/I/I/I!I+IeIpIj1IIhI!ItIpInIfI!IIq1nIpIh1n1tInInIj1IIh1SI!I;I*IIZIfItI-I!1uIiIfI!IlIfIz10IpIeIfI!InIjIhIi1uI!Ii1tIwIfI!1uIiIpItIfI!1nIf1tImImIzI!IfImIfIh1t1I1uI!1nIj1IIhItI-I!Ic1r1uI!1tIj1II(1uI!1IIpI!IpIyIzIhIf1II!Ip1II!1uIi1t1uI!Ih1tItI!IqIm1t1IIf1uI!I_I`I_IIIItIpIpIpIpIF1t1n1uIiI!IjItI!InIzI!Ig1tIwIp1nIj1uIfI!I\I&IQ1!IBIOIFIUI&I^IyI:I:I:I:I:1S1SI!1!If1uI!1rItI!I.1nIfIe1r10IfI.I!IPIVISI!Ie1tIjImIzI!I%Iq1nIpIe1r101uIjIp1II!IpIgI!IIIXIB1aIUIF1SI!I;I*
~~~

* Decrypt the message using keycode SaturnISc00L!
* Note: Decrypting it with a different keycode would of course produce incorrect results
~~~
src/cipher_src --decrypt ../message.txt.output SaturnISc00L!
~~~

* ../message.txt.output.output
~~~
I am,...

@Niel
Ponciano!

#3, #2, 1: ... *doing some ~programming! :)
Yes, the keycode might have those really elegant rings, but ain't no oxygen on that gas planet ^_^


sooooEarth is my favorite [%PLANET%]x99999!! Let us -reduce- OUR daily $production of ~~WASTE! :)
~~~

Now those messages having private content can fly through the air safely :)
