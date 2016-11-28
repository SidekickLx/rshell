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
### Build-in function
#### cd
The usage of cd is the same as another shells. The symbol "~" means user's main directory.
`cd ~/project`
More over the if the 2nd parameter is blank, it should back to the up level.
#### test
This function was built to check whether a file or directory exist.
The usage of test function has been shown bellow.
```bash
$test [-option] [dir_path or file_path]
#[options]
#	-e checks if the file/directory exists
#	-f checks if the file/directory exists and is a regular file
#	-d checks if the file/directory exists and is a directory
```
If a user does not specify a flag, then the -e functionality will be used by default.
If the command test -e /test/file/path evaluates to True, then rshell will print display the following.
(True)
And likewise, if the above command evaluates to False, then rshell will print False in the same manner.
(False)