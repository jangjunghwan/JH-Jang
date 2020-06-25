import string
import os.path
import os
import glob
import re

myPath = '경로'
mtExt = '*.txt'
z = 0 #문장 번호
z1 = 1 #첫번째 줄 문장
z2 = 2 #두번째 줄 문장
t = 0

def pathRead():
	for a in glob.glob(mtExt):  #경로안에있는 *.txt파일
		folder = os.getcwd() #현재 위치경로
		fullPath = (folder+"/"+ a) #*.txt 파일 경로
		# myfile = open(fullPath,'r') #*.txt파일 열람
		return fullPath

def readFile(fullPath):

	arr = []
	#파일 줄, 문장번호 확인 	
	with open(fullPath) as f:
		lines = f.readlines()
		# print(lines)
		# lines = re.sub('[^가-힝0-9a-zA-Z\\s]', '', lines)
	for i in range(len(lines)):
		arr.append(lines[i])
	return arr

def writeFile(arr):

	f = open("write.scp", "w")

	for i in range(len(arr)):
		if (len(a[i]) > 3):
			# print(arr[i])
			f.write(arr[i])

	# for i in range(len(arr)):
	# 	with open("write.txt",'w') as tt:
	# 		tt.write(arr[i])

		



if __name__ == '__main__':
	a = []

	path = pathRead()
	a = readFile(path)
	writeFile(a)	

	# for i in range(len(a)):
	# 	# print(a[i])
	# 	if ( len(a[i]) > 2):
	# 		print(a[i])
	# 	# fd = open("")




