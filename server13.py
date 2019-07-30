
import os
import time
#import magic
import hashlib

from socket import *
serverName = 'servername'
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)

serverSocket2 = socket(AF_INET,SOCK_STREAM)
serverSocket2.bind(('',12345))
serverSocket2.listen(1)

serverSocket3 = socket(AF_INET, SOCK_DGRAM)
serverSocket3.bind(('', 12344))


print 'The server is ready to receive haha'
while 1:
	print 'starting'
	connectionSocket, addr = serverSocket.accept()
	sentence = connectionSocket.recv(1024)
	commands = sentence.split(' ')
	num = len(commands)
	command = commands[0]
	test = 0


	if command == "IndexGet":
		data = []
		test = 1
		if num == 2:
			filess = os.listdir('.')
			

			for name in filess:
				str1 = str(name)
				filename, file_extension = os.path.splitext("/home/mehthab/SOS/" + name)
				str1 = str1 + " " + str(os.stat(name).st_size) + " " + str(time.ctime(os.path.getatime(name)).split(" ")[3]) + " " + str(file_extension)
				data.append(str1)

			connectionSocket.send(str(data))

		if num == 4:

			
			

			if commands[1] == "shortlist":

				start = commands[2].split(':')
				end = commands[3].split(':')

				for name in os.listdir('.'):
					that = time.ctime(os.path.getatime(name)).split(" ")[3].split(':')

					b = int(that[0])*60*60 + int(that[1])*60 + int(that[2])

					a = int(start[0])*60*60 + int(start[1])*60 + int(start[2])

					

					if a <= b <= 0 :

						str1 = str(name)
						
						str1 = str1 + " " + str(os.stat(name).st_size) + " " + str(time.ctime(os.path.getatime(name)).split(" ")[3]) + " " + str(file_extension)
						data.append(str1)


				
				connectionSocket.send(str(data))



	if command == "FileHash":
		data = []
		if num == 2:

			if commands[1] == "checkall":
				filess = os.listdir('.')


    
				hasher = hashlib.md5()
				for name in filess:
					str1 = str(name)
					with open(name , 'rb') as afile:
						buf = afile.read()
						hasher.update(buf)
						checksum = hasher.hexdigest()

					

					data.append(str1)

				connectionSocket.send(str(data))	

		

		if num == 3:

			if commands[1] == "verify":
				name = commands[2]
				hasher = hashlib.md5()
				with open(name  , 'rb') as afile:
					buf = afile.read()
					hasher.update(buf)
					checksum = hasher.hexdigest()



				str1 = str(name) + " " +  + " " + time.ctime(os.path.getmtime(name)).split(" ")[3]

				data.append(str1)

				connectionSocket.send(str(data))	


	
	if command == "FileDownload":
		data = []

		if num == 3:
			name = commands[2]

			
					hasher = hashlib.md5()
					with open(name  , 'rb') as afile:
						buf = afile.read()
						hasher.update(buf)
						checksum = hasher.hexdigest()


					str1 = str(name) + " " + str(os.stat(name).st_size) + " " + str(time.ctime(os.path.getmtime(name)).split(" ")[3]) + " " 

					data.append(str1)  

					connectionSocket.send(str(data))
					
					if  commands[1] == "TCP" :


						flag = 0
						tax = 0

						t_end = time.time() + 60 * 2
						while time.time() < t_end :
							
							print 'hab'
							print tax
							if tax == 1:
								break
							conn, addr = serverSocket2.accept()     # Establish connection with client.
							print 'Got connection from', addr
							#data = conn.recv(1024)
							print('Server received', repr(data))

							
							print 'connection closed'	

							#if tax == 1:
							#	break


								


					if commands[1] == "UDP" :

						flag = 0
						tax = 0

						t_end = time.time() + 60*10

						while time.time() < t_end :


							print 'hab'
							print tax
							if tax == 1:
								break

							message, clientAddress = serverSocket3.recvfrom(2048)
							modifiedMessage = "ok"
							#buf = 1024

							serverSocket3.sendto(modifiedMessage, clientAddress)

							

							if flag == 0 :
								filename = name
								f = open(filename,'rb')
								l = f.read(1024)
								print 'haha'

								
								flag = 1
								
								tax = 1
								print 'sent'
								serverSocket3.sendto("on" , clientAddress)

									#connectionSocket.send("on")

								serverSocket3.sendto(l , clientAddress)
									##VVVVVVVVVVVVVVVV

	

								l = f.read(1024)
								endmsg = "END"	
							    serverSocket3.sendto("off" , clientAddress)	
								f.close()

	
	connectionSocket.close()









	

