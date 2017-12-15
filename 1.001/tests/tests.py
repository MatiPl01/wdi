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
		proc.wait(60)
		result = proc.stdout.read()
		result = result.decode()
		result = result.strip(' \n')
		assert result == stdout, bytes(result, 'ascii')
		proc.wait()

	def test_fibonacci(self):
		self.execute(path='build/app.out',
			    	 stdin='',
			    	 stdout='0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040')