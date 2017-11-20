/*
    C socket server example
*/

#include <arpa/inet.h> //inet_addr
#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <unistd.h> //write

int main(int argc, char *argv[]) {
  int socket_desc, client_sock, c, read_size;
  struct sockaddr_in server, client;
  char client_message[2000];

  // Create socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }
  puts("Server created");

  // Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8888);

  // Bind
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    // print the error message
    perror("bind failed. Error");
    return 1;
  }
  puts("bind done");

  // Listen
  listen(socket_desc, 3);

  // Accept an incoming connection
  puts("Waiting for incoming connections...");
  c = sizeof(struct sockaddr_in);

  // accept connection from an incoming client
  client_sock =
      accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
  if (client_sock < 0) {
    perror("accept failed!!");
    return 1;
  }
  puts("Connection success");

  // Receive a message from client
  while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
    if (read_size == 18) // What_is_your_name?
    {
      write(client_sock, "My name is server almighty..", 100);
    } else if (read_size == 16) // Who_created_you?
    {
      write(client_sock, "Master Justin...", 100);
    } else if (read_size == 5) // Hello
    {
      write(client_sock, "Hello, from the other side", 100);
    } else if (read_size == 2) // Hi
    {
      write(client_sock, "You are boring", 100);
    } else if (read_size == 14) // Is_emacs_good?
    {
      write(client_sock, "Yes!!!!.", 100);
    } else {
      write(client_sock, "I don't know how to answer that,.", 100);
    }
    printf("%d", read_size);
  }
  printf("%d", read_size);

  if (read_size == 0) {
    puts("Client disconnected");
    fflush(stdout);
  } else if (read_size == -1) {
    perror("recv failed");
  }

  return 0;
}
