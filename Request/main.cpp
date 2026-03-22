#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <fstream>
#include <sstream>
#include "Request.hpp"

int main()
{
    int server_fd;
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[4096];

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Configure address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind socket to port
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // 4. Start listening
    listen(server_fd, 10);

    printf("Server listening on port 8080...\n");

    // 5. Accept connection
	client_fd = accept(server_fd, NULL, NULL);

	// 6. Read request
	memset(buffer, 0, sizeof(buffer));
	read(client_fd, buffer, 4096);

	printf("\n%s", buffer);

	Request	request;
	parse_reques(buffer, request);

	std::ifstream file("index.html");
	std::stringstream buffer_file;

	buffer_file << file.rdbuf();

	std::string html = buffer_file.str();

	// 7. Send HTTP response
	std::string	response =
	"HTTP/1.1 200 OK\r\n"
	"Content-Type: text/html\r\n"
	"\r\n" + html;

	send(client_fd, response.c_str(), response.size(), 0);
	// Close sockets
	close(client_fd);
	close(server_fd);

    return 0;
}
