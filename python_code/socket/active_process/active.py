import os
import sys
import time
import socket
import threading

class Socket_Class:
    def __init__(self):
        self.host = '127.0.0.1'
        self.port = 9999

        self.process_type = 'active'

    def active_server_create( self ):
        try:
            print("Active Server Create...")

            active_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            active_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            active_socket.bind( (self.host, self.port) )

            active_socket.listen()

            standby_socket, addr = active_socket.accept()

            print(f"Connetion ADD: {addr}")

            while True:
                time.sleep(3)
                data = b'JJH'
                standby_socket.sendall(bytes(data))

                if standby_socket == "":
                    break

        except Exception as e:
            print(e)


    def standby_client_connect( self ):
        try:
            print("Standby Create..")
            
            standby_socket = socket.socket(socket.AF_INEF, socket.SOCK_STREAM)
            standby_socket.connect( (self.host, self.port) )

            while True:
                data = standby_socket.recv(1024)
                print(f"Recived : {repr(data.decode())}")

                if not data:
                    print("Connect Close...")

                    standby_socket.close()
                    self.__init__()
                    break

        except Exception as e:
            print(e)


if __name__=='__main__':
    print("hello")
    sc = Socket_Class()
    sc.active_server_create()

