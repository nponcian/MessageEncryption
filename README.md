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
# src/cipher_src [--encrypt|--decrypt] [../Path/To/File/Containing/Message] [keycode] [OPTIONAL: Algorithm ID to use {1}]

# This will write the encrypted message to <fileName>.output -> ../message.txt.output
src/cipher_src --encrypt ../message.txt somekeycode

# This will write the decrypted message to <fileName>.output -> ../message.txt.output.output
# The result would exactly be equal to the original message in ../message.txt
src/cipher_src --decrypt ../message.txt.output somekeycode
~~~

## TESTING
~~~
~~~
