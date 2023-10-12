import cmd

class HelloWorld(cmd.Cmd):
    """Simple command processor example"""

    # Disable raw_input module use
    use_rawinput = False

    # Do not show a prompt after each command
    prompt = ''

    def do_greet(self, line):
        print("hello, ", line)

    def do_EOF(self, line):
        return True

if __name__ == "__main__":
    import sys

    input_file = open(sys.argv[1], 'rt')
    try:
        HelloWorld(stdin=input_file).cmdloop()
    finally:
        input_file.close()

