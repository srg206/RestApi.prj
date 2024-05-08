#ifndef Server_21_04_2024
#define Server_21_04_2024

#include<boost/beast.hpp>
#include<boost/asio.hpp>
#include<string>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <routes/All_routes.hpp>
#include<string_view>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using net::ip::tcp;
using namespace std::string_literals;




//std::map<std::string, std::string> jsonToMap(const std::string& jsonString);
class Server{
private:
    boost::asio::ip::tcp::endpoint endpnt = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8000);
    void handleConnection(boost::asio::ip::tcp::socket& socket);
    void handleRequest(boost::asio::ip::tcp::socket& socket, const http::request<http::string_body>& req);

public:
    Server();
    Server(std::string ip_adr, int port);
    Server(std::filesystem::path path_to_configs);
    Server(const Server& another_serv)=delete;
    Server(Server && another_serv)=delete;
    ~Server()=default;

    Server& operator=(const Server& another_serv)=delete;
    Server& operator=(Server&& another_serv)=delete;

    bool Init(std::filesystem::path path_to_configs);
    void Work();
};

#endif