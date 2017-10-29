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

	def test_fibonacci(self):
		self.execute(path='build/app.out',
			    		stdin='',
			    		stdout='220 284\n\
								1184 1210\n\
								2620 2924\n\
								5020 5564\n\
								6232 6368\n\
								10744 10856\n\
								12285 14595\n\
								17296 18416\n\
								63020 76084\n\
								66928 66992\n\
								67095 71145\n\
								69615 87633\n\
								79750 88730\n\
								100485 124155\n\
								122265 139815\n\
								122368 123152\n\
								141664 153176\n\
								142310 168730\n\
								171856 176336\n\
								176272 180848\n\
								185368 203432\n\
								196724 202444\n\
								280540 365084\n\
								308620 389924\n\
								319550 430402\n\
								356408 399592\n\
								437456 455344\n\
								469028 486178\n\
								503056 514736\n\
								522405 525915\n\
								600392 669688\n\
								609928 686072\n\
								624184 691256\n\
								635624 712216\n\
								643336 652664\n\
								667964 783556\n\
								726104 796696\n\
								802725 863835\n\
								879712 901424\n\
								898216 980984\n\
								947835 1125765\n\
								998104 1043096\n')


