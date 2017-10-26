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

	def test_1(self):
		self.execute(path='build/aliquots.out',
			    		stdin='1',
			    		stdout='1')

	def test_2(self):
		self.execute(path='build/aliquots.out',
			    		stdin='2',
			    		stdout='1 2')

	def test_3(self):
		self.execute(path='build/aliquots.out',
			    		stdin='3',
			    		stdout='1 3')

	def test_4(self):
		self.execute(path='build/aliquots.out',
			    		stdin='4',
			    		stdout='1 2 4')

	def test_32(self):
		self.execute(path='build/aliquots.out',
			    		stdin='32',
			    		stdout='1 2 4 8 16 32')