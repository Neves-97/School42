#include "../incs/validation.hpp"
#include "../incs/server.hpp"
#include "../incs/client.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./ircserv <port> <password>" << std::endl;
        return 1;
    }
    
    if (!validPort(argv[1])) return 1;

    if (!validPassword(argv[2])) return 1;

    Server server(argv[1], argv[2]);
    server.start();

    return 0;
}
