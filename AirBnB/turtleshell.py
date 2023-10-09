import cmd, sys
from turtle import *

class TurtleShell(cmd.Cmd):
    intro = "Welcome to the turtle shell. Type help or ? to list comands.\n"
    prompt = "(turtle)"
    file = None

    #___basic turtle commands____
    def do_forward(self, arg):
        """Move the turtle forwad by the specified distance: FORWARD 10"""
        forward(*parse(arg))

    def do_right(self, arg):
        """Move the turtle right by given number of degrees: RIGHT 20"""
        right(*parse(arg))

    def do_left(self, arg):
        """Turn turtle left by given num of Degrees: LEFT 90"""
        left(*parse(arg))

    def do_goto(self, arg):
        """Move turtle to an absolute position with changing
        orientation: GOTO 100 200"""
        goto(*parse(arg))

    def do_home(self, arg):
        """Return turtle to the home position: HOME"""
        home()

    def do_circle(self, arg):
        """Draw a circle with given radius an ptions extent and steps
        CIRCLE 50"""
        circle(*parse(arg))

    def do_position(self, arg):
        """Print the current turtle position: POSITION"""
        print("Current heading is %d\n" % position())

    def do_heading(self, arg):
        """Print the current turtle heading in degrees: HEADING"""
        print("Current heading is %d\n" % (heading(),))

    def do_color(self, arg):
        """Set the color: COLOR BLUE"""
        color(arg.lower())

    def do_undo(self, arg):
        """Undo (repeatedly) the last turtle action: UNDO"""

    def do_reset(self, arg):
        """Clear the screen and return turtle to center: RESET"""
        reset()

    def do_bye(self, arg):
        """Stop recording, close the turtle window and exit: BYE"""
        print("Thank you for using Turtle")
        self.close()
        bye()
        return True

    #___record and playback
    def do_record(self, arg):
        """Save future commands to filename: RECORD rose.cmd"""
        self.file = open(arg, 'w')

    def do_playback(self, arg):
        """Playback commands from a file: PLAYBACK rose.cmd"""
        self.close()
        with open(arg) as f:
            self.cmdqueue.extend(f.read().splitlines())

    def precmd(self, line):
        line = line.lower()
        if self.file and 'playback' not in line:
            print(line, file = self.file)
        return line

    def close(self):
        if self.file:
            self.file.close()
            self.file = None

def parse(arg):
    """Convert a series of zero or more numbers to an arg tuple"""
    return tuple(map(int, spilt()))


if __name__ == '__main__':
    TurtleShell().cmdloop()
