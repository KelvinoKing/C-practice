#!/usr/bin/python3

import cmd
import sys

class HBNBCommand(cmd.Cmd):
    """Simple command processor example"""

    prompt = "(hbnb) "

    if sys.stdin.isatty():
        pass
    else:
        def postloop(self):
            print()

    def emptyline(self):
        """Dont execute when empty line is entered
        followed by ENTER key
        """
        pass

    def do_EOF(self, line):
        """Exits the console
        """
        return True

    def do_quit(self, line):
        """Quit the console
        """
        return True

if __name__ == '__main__':
    HBNBCommand().cmdloop()
