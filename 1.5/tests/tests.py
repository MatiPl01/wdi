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
		result = result.strip('\n')
		assert result == stdout, bytes(result, 'ascii')
		proc.wait()

	def test_1(self):
		self.execute(path='build/int_sqrt.out',
			    		stdin='4',
			    		stdout='2')	
		self.execute(path='build/int_sqrt.out',
			    		stdin='16',
			    		stdout='4')
		self.execute(path='build/int_sqrt.out',
			    		stdin='64',
			    		stdout='8')
		self.execute(path='build/int_sqrt.out',
			    		stdin='9',
			    		stdout='3')
		self.execute(path='build/int_sqrt.out',
			    		stdin='100',
			    		stdout='10')
		self.execute(path='build/int_sqrt.out',
			    		stdin='2',
			    		stdout='1')
		self.execute(path='build/int_sqrt.out',
			    		stdin='10',
			    		stdout='3')
		self.execute(path='build/int_sqrt.out',
			    		stdin='17',
			    		stdout='4')
		self.execute(path='build/int_sqrt.out',
			    		stdin='24',
			    		stdout='4')
		self.execute(path='build/int_sqrt.out',
			    		stdin='101',
			    		stdout='10')
		self.execute(path='build/int_sqrt.out',
			    		stdin='99',
			    		stdout='9')