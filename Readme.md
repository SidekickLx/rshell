# Rshell
By Weijia Xin & Xuezixiang Li





## install

```bash
$ git clone  https://github.com/SidekickLx/rshell.git
$ cd rshell
$ git checkout hw2
$ make
$ bin/rshell

```
## Usage
-  executing single commands

`$ executable [ argumentList ] [ connector cmd ]`

- executing multiple commands with logical symbols

The connector is an optional way you can run multiple commands at once. If a command is followed by ; , then the next command is always executed; if a command is followed by &&, then the next command is executed only if the first one succeeds; if a command is followed by ||, then the next command is executed only if the first one fails. 
For example:
```bash
$ ls -a
$ echo hello
$ mkdir test
	# is equivalent to:
$ ls -a; echo hello; mkdir test
```
