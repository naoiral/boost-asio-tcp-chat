# Boost.Asio TCP Echo Server (Single Client)
A simple synchronous TCP echo server and client implemented with Boost.Asio.

## Project Introduction
This is a **basic network programming demo** for learning TCP communication and Boost.Asio.
The server can handle **one client at a time** and provides persistent echo communication.

## Features
- ✅ Persistent message interaction
- ✅ IPv4 & IPv6 dual-stack support
- ✅ Clean synchronous blocking model
- ✅ Complete error handling
- ✅ Simple and readable code structure

## Tech Stack
- C++11
- Boost.Asio
- TCP/IP Protocol

## How to Run
1. Open the solution file in Visual Studio
2. Run the **server** first
3. Run the **client**
4. Send messages in the client console, the server will echo back

## Note
This is a **single-client server** for learning purposes.
It processes one client connection and waits for a new one after disconnection.
