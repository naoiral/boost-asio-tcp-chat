#include <iostream>
#include <cstring>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio::ip;

std::string raw_ip_address = "127.0.0.1";
unsigned short port_num = 3333;

int main() {
	try {
		boost::system::error_code ec;
		address ip_address = make_address(raw_ip_address, ec);
		if (ec) {
			std::cout
				<< "Failed to parse IP address. Error code="
				<< ec.value() << ". Message: " << ec.message() << std::endl;
			return ec.value();
		}
		// Create a TCP endpoint using the IP address and port number
		tcp::endpoint ep(ip_address, port_num);
		// Create an io_context object to perform asynchronous operations
		boost::asio::io_context ioc;
		// Create a TCP socket and connect it to the server
		tcp::socket socket(ioc);
		// Connect to the server
		socket.connect(ep, ec);
		if (ec) {
			std::cout
				<< "Failed to connect to the server. Error code="
				<< ec.value() << ". Message: " << ec.message() << std::endl;
			return ec.value();
		}
		while (1) {
		// write a message to the server and read a response
		std::cout << "Enter a message to send to the server: ";
		char message[1024];
		
			std::cin.getline(message, sizeof(message));
			size_t message_length = std::strlen(message);

			// 注意使用 boost::asio::buffer（双冒号）
			boost::asio::write(socket, boost::asio::buffer(message, message_length));

			char response[1024];
			size_t response_length = boost::asio::read(socket, boost::asio::buffer(response, message_length));
			std::cout << "Response is:", cout.write(response, response_length) << std::endl;

		}
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}