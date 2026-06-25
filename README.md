# Security-toolsZ
# C++ Cryptography & Security Tools

A collection of lightweight, terminal-based C++ applications designed to demonstrate fundamental concepts in cryptography, hashing, and system file manipulation. 

---

##Tools Included

| Tool | Description | Key Concepts |
| :--- | :--- | :--- |
| Caesar Cipher | Encrypts and decrypts standard text inputs using a classic shift key mechanism. | Character manipulation. |
| File Encryption | Secures and restores entire text files using an XOR bitwise cipher and a custom text key. | File handling. |
| Hash Generator | Generates non-cryptographic hashes (djb2 algorithm) for text strings and tracks session history. | Data structures, algorithms. |

---

## Project Details

### 1. Caesar Cipher Encryption/Decryption
A simple text processor that shifts alphabetical characters by a user-defined integer key. It wraps around the alphabet (e.g., shifting 'Z' by 1 becomes 'A') while leaving numbers and special characters untouched. 
* Use Case: Basic string obfuscation and learning historical ciphers.

### 2. XOR File Encryption Tool
A robust utility that reads an input file byte-by-byte and applies an XOR bitwise operation against a user-provided string key. Because XOR is a symmetric operation, passing the encrypted file back through the tool with the *same key* will perfectly decrypt it.
* Use Case: Lightweight file security and learning how to safely read/write binary data streams.

### 3. Hash Generator
A session-based tool that digests variable-length string inputs into fixed-size numeric values (hashes) using the djb2 algorithm. It stores a history of the current session's inputs and their corresponding hexadecimal/decimal hashes.
* Use Case: Understanding data integrity, algorithmic transformations, and memory structures.

---

## Getting Started

### Prerequisites
You will need a C++ compiler installed on your system (e.g., g++ for Linux/macOS or MinGW for Windows).

### Compilation
Navigate to the repository folder in your terminal and compile the files individually. For example:

`bash
# Compile the Caesar Cipher
g++ -o caesar_cipher caesar_cipher.cpp

# Compile the XOR File Tool
g++ -o file_encrypt file_encrypt.cpp

# Compile the Hash Generator
g++ -o hash_generator hash_generator.cpp
