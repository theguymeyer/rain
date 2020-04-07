# Rain Bash Alias

To run the script first you need to generate the run the makefile: `make rain`

You can now invoke the object file `rain.o` created by [g++](https://linux.die.net/man/1/g++).

## Function Arguments

The object file must be invoked with a couple of mandatory arguments:
1. The number of rows
2. The number of columns
⋅⋅* The size of the screen in ASCII sizing. The `stty size` terminal command can invoked to retrieve the data (see aliasing command section).
3. The time delay between timesteps (in microseconds)

## Aliasing to a command

You can also create an alias for your new command by embeding the following in your **~/.bash_aliases** for Debian or **~/.zshrc** for OSx users

`alias rain="/your_path_here/rain.o $(stty size) 50000"`
