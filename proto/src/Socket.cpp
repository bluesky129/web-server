//
// Socket.cpp for zia in /home/armand_m/zia/proto/src
// 
// Made by morgan armand
// Login   <armand_m@epitech.net>
// 
// Started on  Wed Jul 30 11:45:23 2008 morgan armand
// Last update Wed Jul 30 12:21:05 2008 morgan armand
//

#include <iostream>
#include "Socket.h"

Socket::Socket()
  : _sck(INVALID_SOCKET), _sin()
{
}

Socket::Socket(const SOCKET sck, const struct sockaddr_in& sin)
  : _sck(sck), _sin(sin)
{
}

bool	Socket::create()
{
#ifdef WIN32
  int		err;
  WSADATA	wsaData;

  if ((err = WSAStartup(MAKEWORD(2, ,2), &wsaData)) != 0)
    {
      std::cerr << "WSAStartup failed with error " << err << std::endl;
      return (false);
    }

  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
      std::cerr << "Could not find a useable version of winsock.dll" << std::endl;
      WSACleanup();
      return (false);
    }
#endif

  if ((this->_sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
      std::cerr << "socket() failed" << std::endl;
#ifdef WIN32
      WSACleanup();
#endif
      return (false);
    }
  return (true);
}

bool	Socket::bind(const int port)
{
  if (!this->isValid())
    return (false);

  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(port);
  this->_sin.sin_addr.s_addr = INADDR_ANY;

  if (::bind(this->_sck, (struct sockaddr *)&this->_sin, sizeof(this->_sin)) == SOCKET_ERROR)
    {
      std::cerr << "bind() failed" << std::endl;
#ifdef WIN32
      WSACleanup();
#endif
      return (false);
    }
  return (true);
}

bool	Socket::listen(const int backlog)
{
  if (!this->isValid())
    return (false);

  if (::listen(this->_sck, 42) == SOCKET_ERROR)
    {
      std::cerr << "listen() failed" << std::endl;
#ifdef WIN32
      WSACleanup();
#endif
      return (false);
    }
  return (true);
}

Socket*	Socket::accept()
{
  SOCKET		sck;
  struct sockaddr_in	sin;
  socklen_t		len;

  if (!this->isValid())
    return (false);

  len = sizeof(sin);

  if ((sck = ::accept(this->_sck, (struct sockaddr *)&sin, &len)) == INVALID_SOCKET)
    {
      std::cerr << "accept() failed" << std::endl;
      return (NULL);
    }

  return (new Socket(sck, sin));
}

void	Socket::close()
{
  if (this->isValid())
    ::close(this->_sck);
}

bool	Socket::isValid()
{
  return (this->_sck != INVALID_SOCKET);
}
