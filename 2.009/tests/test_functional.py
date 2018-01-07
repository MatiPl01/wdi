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

    def test_palindrome1(self):
        self.execute(path='./test_me',
                      stdin='1',
                      stdout='TAK TAK')

    def test_palindrome2(self):
        self.execute(path='./test_me',
                      stdin='2',
                      stdout='TAK NIE')

    def test_palindrome3(self):
        self.execute(path='./test_me',
                      stdin='3',
                      stdout='TAK TAK')

    def test_palindrome4(self):
        self.execute(path='./test_me',
                      stdin='999',
                      stdout='TAK NIE')

    def test_palindrome5(self):
        self.execute(path='./test_me',
                      stdin='919',
                      stdout='TAK NIE')