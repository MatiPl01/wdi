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

    def test_fibonacci2(self):
        self.execute(path='./test_me',
                      stdin='2',
                      stdout='TAK')

    def test_fibonacci3(self):
        self.execute(path='./test_me',
                      stdin='3',
                      stdout='NIE')

    def test_fibonacci4(self):
        self.execute(path='./test_me',
                      stdin='4',
                      stdout='NIE')

    def test_fibonacci6(self):
        self.execute(path='./test_me',
                      stdin='6',
                      stdout='TAK')