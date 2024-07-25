#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>  // For exit()
#include <ctime>    // For generating Date header
#include "strings_int_play.h"

#define DEFAULT_PORT 8080
#define MAX_PORT 65535

std::string getCurrentTime() {
    char buffer[100];
    std::time_t now = std::time(0);
    std::tm *gmtm = std::gmtime(&now);
    std::strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S GMT", gmtm);
    return std::string(buffer);
}

int main(int argc, char *argv[]) {
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int port = DEFAULT_PORT;

    // Check if a port number was provided as an argument
    if (argc > 1) {
        try {
            port = stringToInt(argv[1]);  // Convert argument to integer
            if (port < 1 || port > MAX_PORT) {
                throw std::out_of_range("Port out of range");
            }
        } catch (...) {
            std::cerr << "Invalid port number. Using default port " << DEFAULT_PORT << std::endl;
            port = DEFAULT_PORT;
        }
    }

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Setting up the address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << port << std::endl;

    while (true) {
        // Accepting an incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            std::cerr << "Accept failed" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Reading the request
        char buffer[30000] = {0};
        valread = read(new_socket, buffer, 30000);
        std::cout << buffer << std::endl;

        // Preparing the response
        std::string html = "<html><body><h1>Hello, World!</h1></body></html>";
        std::string currentTime = getCurrentTime();
        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: " +intToString(getStringLength(html)) + "\r\n"
            "Vary: Accept-Encoding\r\n"
            "X-Content-Type-Options: nosniff\r\n"
            "Strict-Transport-Security: max-age=31536000; includeSubDomains\r\n"
            "Server: IsakaJames\r\n"
            "Date: " + currentTime + "\r\n"
            "Pragma: no-cache\r\n"
            "Cache-Control: no-cache, no-store, must-revalidate\r\n"
            "\r\n" + html;

        // Sending the response
        write(new_socket, response.c_str(), response.length());

        // Closing the socket
        close(new_socket);
    }

    return 0;
}
