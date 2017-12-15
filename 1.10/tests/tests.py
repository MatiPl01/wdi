import unittest
import subprocess

class ExeTest(unittest.TestCase):
	def execute(self, path, stdin, stdout):
		proc = subprocess.Popen(
			path,
			stdout=subprocess.PIPE,
		    stdin=subprocess.PIPE)
		proc.stdin.write(bytes(stdin, 'ascii'))
		proc.stdin.close()
		result = proc.stdout.read()
		result = result.decode()
		result = result.strip(' \n')
		assert result == stdout, bytes(result, 'ascii')
		proc.wait()

	def test_nwd(self):
		self.execute(path='build/app.out',
			    		stdin='16 10 20',
			    		stdout='2')