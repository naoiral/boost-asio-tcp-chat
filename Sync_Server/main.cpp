#include <iostream>
#include <boost/asio.hpp>
const int MAX_LEN = 1024;


boost::asio::ip::address ip_address = boost::asio::ip::address_v6::any();
unsigned short port_num = 3333;
void session(boost::asio::ip::tcp::socket& socket) {
    boost::system::error_code ec;
    while (1) {    // 1. 读取客户端数据
        char recv_buf[MAX_LEN] = { 0 };
        size_t recv_len = socket.read_some(boost::asio::buffer(recv_buf), ec);
        if (ec) {
            std::cout << "读取失败：" << ec.message() << std::endl;
            return;
        }
        std::cout << "客户端消息：" << recv_buf << std::endl;

        // 2. 回显数据给客户端（Echo逻辑）
        boost::asio::write(socket, boost::asio::buffer(recv_buf, recv_len), ec);
        if (ec) {
            std::cout << "发送失败：" << ec.message() << std::endl;
            return;
        }
        std::cout << "已回复客户端\n";
    }
  
}
int main() {
	try {
		boost::system::error_code ec;
		boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v6::any(), port_num);
        
            boost::asio::io_context ioc;
            

            boost::asio::ip::tcp::acceptor acceptor(ioc, ep);
            while (1) {
            boost::asio::ip::tcp::socket socket(ioc);
            acceptor.accept(socket);
            session(socket);
        }
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
