#include <iostream>
#include <vector>

class Client
{
private:
    int             _fd;
    std::string     _IPadd;
public:
    Client():_fd(-1){};
    ~Client(){};
    void    setFD(int fd){_fd = fd;};
    int     getFD() {return _fd;};
    void    setAdd(std::string add){_IPadd = add;};
};

class Server
{
private:
    int                         port;
    int                         serSocketFd;
    static bool                 signal;
    std::vector<Client>         clients;
    std::vector<struct pollfd>  fds;
public:
    Server():serSocketFd(-1){};
    ~Server(){};
    void    serverInit();
    void    serSocket();
    void    acceptNewClient();
    void    receiveNewData(int fd);
    static void     signalHandler(int signum);
    void            closeFds();
    void            clearClients(int fds);
};


int main()
{

    return 0;
}