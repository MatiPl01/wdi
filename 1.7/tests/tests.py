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

	def test_2(self):
		self.execute(path='build/default.out',
			    		stdin='2',
			    		stdout='TAK')

	def test_3(self):
		self.execute(path='build/default.out',
			    		stdin='3',
			    		stdout='TAK')

	def test_5(self):
		self.execute(path='build/default.out',
			    		stdin='5',
			    		stdout='TAK')

	def test_7(self):
		self.execute(path='build/default.out',
			    		stdin='7',
			    		stdout='TAK')

	def test_11(self):
		self.execute(path='build/default.out',
			    		stdin='11',
			    		stdout='TAK')

	def test_13(self):
		self.execute(path='build/default.out',
			    		stdin='13',
			    		stdout='TAK')

	def test_17(self):
		self.execute(path='build/default.out',
			    		stdin='17',
			    		stdout='TAK')

	def test_19(self):
		self.execute(path='build/default.out',
			    		stdin='19',
			    		stdout='TAK')

	def test_4(self):
		self.execute(path='build/default.out',
			    		stdin='4',
			    		stdout='NIE')

	def test_6(self):
		self.execute(path='build/default.out',
			    		stdin='6',
			    		stdout='NIE')

	def test_8(self):
		self.execute(path='build/default.out',
			    		stdin='8',
			    		stdout='NIE')

	def test_12(self):
		self.execute(path='build/default.out',
			    		stdin='12',
			    		stdout='NIE')

	def test_100(self):
		self.execute(path='build/default.out',
			    		stdin='100',
			    		stdout='NIE')

	def test_128(self):
		self.execute(path='build/default.out',
			    		stdin='128',
			    		stdout='NIE')

	def test_99(self):
		self.execute(path='build/default.out',
			    		stdin='99',
			    		stdout='NIE')

	def test_14(self):
		self.execute(path='build/default.out',
			    		stdin='14',
			    		stdout='NIE')

	def test_22(self):
		self.execute(path='build/default.out',
			    		stdin='22',
			    		stdout='NIE')

	def test_36(self):
		self.execute(path='build/default.out',
			    		stdin='36',
			    		stdout='NIE')

	def test_20(self):
		self.execute(path='build/default.out',
			    		stdin='20',
			    		stdout='NIE')

	def test_1(self):
		self.execute(path='build/default.out',
			    		stdin='1',
			    		stdout='NIE')