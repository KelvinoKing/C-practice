import cmd
import os

class HelloWorld(cmd.Cmd):
    """Simple command processor example
    """
    prompt = "(Njosh) "
    last_output = ' '

    def do_shell(self, line):
        """Run a shell command"""
        print("running shell command: ", line)
        output = os.popen(line).read()
        print(output)
        self.last_output = output

    def do_echo(self, line):
        """print the input, replacing '$out' with the output
        of the last shell command"""
        print(line.replace("$out", self.last_output))

    def do_greet(self, person):
        if person:
            print("Hello ", person)
        else:
            print("Hello")

    def help_greet(self):
        print("\n".join(['greet [person]',
                         'Greet the named person',]))

    def do_EOF(self, line):
        """Exits the console
        """
        return True

    def do_quit(self, line):
        """Quit the console
        """
        return True

if __name__ == '__main__':
    HelloWorld().cmdloop()
