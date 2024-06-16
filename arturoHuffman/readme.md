# Huffman coding

- A Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression. The process of finding or using such a code is **Huffman coding**, an algorithm developed by **David A. Huffman** while he was a Sc.D. student at MIT, and published in the **1952 paper "A Method for the Construction of Minimum-Redundancy Codes"**.

- [1952 paper "A Method for the Construction of Minimum-Redundancy Codes"](https://www.ias.ac.in/article/fulltext/reso/011/02/0091-0099)

# Notes

- the time for transmission of the message *(length)* of a message is proportinal to the number of symbols asscociated with it
- The entire number of messages that might be transmitted is called the "message ensemble"
- The meaning of the code for each message in the ensemble is called the "ensemble code"

## Math 
- If there are D different types of symbols to be used for coding, they will be represented by the digits {0,D-1}.
- The number of messages in the ensemble is *N* Let *P(i)* be the probability of the *ith* message
- The length of a message , *L(i)*, is the number of coding digits assigned to it, the average message length is:

$L_{av} = \sum\limits_{i=1}^{N} P(i) L(i)$

## Rules
1. No two messages will consist of identical arrangements of coding digits
2. The message codes will be constructed in a way such that no additional indication is needed to specify where a message code begins and ends once the starting point of a sequence of messages is known.

## Requirements 
- It should be assumed that the messages in the ensemble have been ordered in such a way that:

    $P(1) \geqq P(2) \geqq \cdots \geqq P(N-1) \geqq P(N)$

    And

    $L(1) \leq L(2) \leq \cdots \leq L(N-1) \leq L(N)$

- For an optimum code it is required that:
    $L(N) = L(N-1)$

- At least two but no mare thatn $D$ of the messages with code length $L(N)$ have codes which are alike except for their final digits.
- Each possible sequence of $L(N)-1$ digits must be used either as a messages code or must have one of its prefixes used as a message code


## Optimum Binary Code


- Just read the [wiki](https://en.wikipedia.org/wiki/Huffman_coding), couldnt get the paper as well as the wiki
https://upload.wikimedia.org/wikipedia/commons/thumb/a/a0/Huffman_coding_visualisation.svg/2880px-Huffman_coding_visualisation.svg.png![image](https://github.com/arturovilla/GTAVcompression/assets/60208172/a3bf9afe-7e75-4078-be46-588607addd09)
