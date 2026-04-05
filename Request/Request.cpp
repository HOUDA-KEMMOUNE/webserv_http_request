#include "Request.hpp"

Request::Request( void ) {}

Request::Request( const Request &old ) : method(old.method), path(old.path), version(old.version)
{}

Request	&Request::operator=( const Request &old )
{
	if (this != &old)
	{
		method = old.method;
		path = old.path;
		version = old.version;
	}
	return (*this);
}

void	Request::setMethod( std::string m )
{
	method = m;
}

void	Request::setPath( std::string p )
{
	path = p;
}

void	Request::setVersion( std::string v )
{
	version = v;
}

std::string	Request::getMethod( void ) const
{
	return (method);
}

std::string	Request::getPath( void ) const
{
	return (path);
}

std::string	Request::getVersion( void ) const
{
	return (version);
}

Request::~Request( void ) {}
