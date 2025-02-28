#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        io_context context;
        tcp::acceptor acceptor(context, tcp::endpoint(tcp::v4(), 8080));

        std::cout << "Server is running on port 8080..." << std::endl;

        while (true) {
            tcp::socket socket(context);
            acceptor.accept(socket);

            boost::asio::streambuf requestBuffer;
            boost::asio::read_until(socket, requestBuffer, "\r\n\r\n");

            std::istream requestStream(&requestBuffer);
            std::string request((std::istreambuf_iterator<char>(requestStream)), std::istreambuf_iterator<char>());

            std::cout << "Received request:\n" << request << std::endl;

            std::ostringstream responseStream;
            responseStream << "HTTP/1.1 200 OK\r\n"
                           << "Content-Type: text/plain\r\n"
                           << "Content-Length: " << request.size() << "\r\n"
                           << "Connection: close\r\n"
                           << "\r\n"
                           << request;

            std::string response = responseStream.str();
            boost::asio::write(socket, boost::asio::buffer(response));
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}