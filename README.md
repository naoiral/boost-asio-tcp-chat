Boost.Asio TCP Echo Server & Client
A synchronous TCP echo server and client project built with Boost.Asio, supporting persistent and stable network communication.
Features
✅ Persistent server: supports loop connections for multiple clients
✅ Interactive client: send multiple messages and receive real-time echo responses
✅ IPv4/IPv6 dual-stack support
✅ Automatic connection handling and error processing
✅ Clean and modular C++ code structure
Prerequisites
C++11 or later
Boost.Asio library
Visual Studio 2022 (with .sln project file included)
How to Run
Open Sync_TCP.sln with Visual Studio 2022
Build and run Sync_Server first (TCP server)
Build and run Sync_Client (TCP client)
Input messages in the client console, and the server will echo back the data
Project Structure
Sync_Server/: Source code of the TCP echo server
Sync_Client/: Source code of the TCP client
.gitignore: Git ignore configuration for build files
Sync_TCP.sln: Visual Studio solution file
