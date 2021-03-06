#ifndef __IMODULE_H__
# define __IMODULE_H__

# include "IRoot.h"

# ifdef WIN32
#  define EXPORT	__declspec(dllexport)
# else
#  define EXPORT	;
# endif

namespace	ziApi
{
  class	IRequest;
  class	IResponse;

  //! IModule
  class	IModule : public IRoot
  {
  public:
    enum	State	{CONTINUE, NOPROCESS,
			 BREAK, STOP, S_ERROR};
    enum	Event	{PRE = 1, POST, END, E_ERROR};

    virtual ~IModule(){}

    //! undef
    virtual State	affect(const Event&,
			       IRequest* request) = 0;
    //! undef
    virtual State	affect(const Event&,
			       IResponse* response) = 0;
  };
};

#endif // !__IMODULE_H__
