#ifndef MINECRAFT_SERVER_H
#define MINECRAFT_SERVER_H

class Server {
public:
    Server();           /* Local Servers */
    Server(int port);   /* Remote Servers */
    ~Server();
};

#endif