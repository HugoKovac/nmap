#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include "parsing.h"

void *send_thread(void *host)
{
    struct addrinfo hints = {0}; // Hints (rules) for resolving ip/host
    struct addrinfo *out = NULL;

    hints.ai_family = AF_INET;       // IPV4 only
    hints.ai_socktype = SOCK_STREAM; // TCP only

    int ping_result = getaddrinfo(host, NULL, &hints, &out); // resolve hostname of IPV4
    if (ping_result)
    {
        dprintf(2, "'%s' failed to be resolved: %s\n", (char*)host, gai_strerror(ping_result));
        return (void*)true;
    }

    if (out)
    {
        struct sockaddr_in *dest_addr = (struct sockaddr_in *)out->ai_addr; // cast to sockaddr_in to add port
        dest_addr->sin_port = htons(8030);
        int client_fd = socket(AF_INET, SOCK_STREAM, 0); // IPV4, TCP
        if (client_fd < 0)
        {
            perror("Fail to create socket");
            freeaddrinfo(out);
            return (void*)true;
        }
        connect(client_fd, (const struct sockaddr *)dest_addr, out->ai_addrlen);

        // cast ai_addr to sockaddr_in to be sure to not have sockaddr_in6
        if (sendto(client_fd, NULL, 0, MSG_NOSIGNAL, out->ai_addr, out->ai_addrlen) == -1)
        {
            dprintf(2, "Send failed\n");
            freeaddrinfo(out);
            return (void*)true;
        }
        close(client_fd);
    }

    freeaddrinfo(out);
    return (void*)false;
}

bool ping(char *host)
{
    pthread_t thread_id;
    void *status;
    pthread_create(&thread_id, NULL, send_thread, host);
    pthread_join(thread_id, &status);
    return (bool)status;
}