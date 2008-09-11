#include "ConnectionInfos.h"

using namespace ZenZiAPI;

ConnectionInfos::ConnectionInfos(SOCKET sck)
  : _sck(sck)
{
}

const SOCKET		ConnectionInfos::getSocket() const
{
  return (this->_sck);
}

const ConnectionInfos::connectionType	ConnectionInfos::getConnectType(void) const
{
  return (this->_connectionType);
}

ConnectionInfos::Extension*		ConnectionInfos::getExtension(void) const
{
  return (this->_extension);
}

void			ConnectionInfos::setExtension(void *ptr)
{
  this->_extension = ptr;
}
