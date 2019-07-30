from socket import *
serverName = 'servername'
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print 'The server is ready to receive haha'
while 1:
	connectionSocket, addr = serverSocket.accept()
	sentence = connectionSocket.recv(1024)
	commands = sentence.split(' ')
	num = len(commands)
	print(num)






	capitalizedSentence = sentence.upper()
	connectionSocket.send(num)
	connectionSocket.close()