import unittest
import subprocess

class ExeTest(unittest.TestCase):
    def execute(self, path, stdin, stdout):
        proc = subprocess.Popen(
            path,
            stdout=subprocess.PIPE,
            stdin=subprocess.PIPE)
        proc.stdin.write(bytes(stdin))
        proc.stdin.close()
        result = proc.stdout.read()
        result = result.decode()
        result = result.strip(' \n')
        result = ''.join(result.split())
        stdout = ''.join(stdout.split())
        assert result == stdout, bytes(result)
        proc.wait()

    def test_yes(self):
        self.execute(path='./test_me',
                     stdin='3',
                     stdout='TAK')

    def test_no(self):
        self.execute(path='./test_me',
                     stdin='14',
                     stdout='NIE')