//
// Server.h for zia in /home/candan_c/cu/rendu/zia/renewal/src
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Wed Sep 10 17:25:17 2008 caner candan
// Last update Sat Sep 13 16:04:17 2008 caner candan
//

#ifndef __SERVER_H__
# define __SERVER_H__

# include <list>
# include <string>
# include "Logger.h"
# include "ServerSocket.h"

class	Server
{
public:
  void	start();
  void	loop();
  void	stop();
private:
  Logger	_logger;
  ServerSocket	_server;
};

#endif //! __SERVER_H__
