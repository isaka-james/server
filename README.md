# IsakaJames\1.0 Server

## Overview

This project provides a basic server implementation that handles incoming connections and serves a simple HTML response. Currently, the server returns a "Hello, World!" message when accessed. Future versions will include additional features and enhancements.

## Getting Started

Follow these steps to get the server up and running:

### Prerequisites

1. **Operating System:** Ensure you are using a Unix-based operating system (e.g., Linux, macOS).
2. **Development Tools:** Make sure you have the necessary build tools installed, such as `clang++` and `make`.

### Installation

1. **Clone the Repository**

   Open a terminal and run the following command to clone the project repository:

   ```bash
   git clone https://github.com/isaka-james/server.git
   ```

2. **Navigate to the Project Directory**

   Change to the project directory:

   ```bash
   cd server
   ```

### Building the Project

1. **Compile the Source Code**

   Use Makefile to compile the project. If a Makefile is provided, you can run:

   ```bash
   make
   ```

### Running the Server

1. **Start the Server**

   After successful compilation, run the server executable:

   ```bash
   ./server
   ```

   The server will start and listen on port 8080.
   If you want to run the server on your custom port then just run `./server <PORT NUMBER>`

2. **Access the Server**

   Open a web browser or use a tool like `curl` to access the server:

   ```bash
   curl http://localhost:8080
   ```

   You should see the "Hello, World!" message displayed.

### Stopping the Server

To stop the server, simply terminate the running process. This can usually be done by pressing `Ctrl + C` in the terminal where the server is running.

## Future Enhancements

The server will be improved with additional features and functionalities in future updates. These may include:

- Enhanced request handling
- Improved performance and scalability
- Advanced response types and content
- Integration with additional services and protocols

Stay tuned for more updates and features!

## Contributing

If you would like to contribute to the project, please follow these guidelines:

1. Fork the repository and create a new branch for your changes.
2. Make your modifications and test them thoroughly.
3. Submit a pull request with a clear description of the changes.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For any questions or further information, please contact [Isaka James](https://x.com/isakajamess).