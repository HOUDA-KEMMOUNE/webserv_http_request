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

void	get_method( std::string buffer, Request &request )
{
	size_t		i = 0;

	std::string	token;

	while (i < buffer.size() && i + 1 < buffer.size() && buffer[i] != ' ')
	{
		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
			return ;
		
		token += buffer[i];
		i++;
	}
	
	// std::cout << "token -> " << token << std::endl;
	request.setMethod(token);
}

void	get_path( std::string buffer, Request &request )
{
	size_t		i = 0;

	std::string	token;

	while (i < buffer.size() && i + 1 < buffer.size())
	{
		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
			return ;

		// std::cout << "{" << buffer[i] << "}\n"; 
		
		if (buffer[i] != '/')
			i++;
		else
		{
			token += buffer[i];

			if (buffer[i + 1] == ' ')
				break ;

			i++;
		}
	}
	
	// std::cout << "token -> " << token << std::endl;
	request.setPath(token);
}

void	get_version( std::string buffer, Request &request )
{
	size_t		i = 0;
	int			count = 0;

	std::string	token;

	while (i < buffer.size() && i + 1 < buffer.size())
	{
		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
			return ;

		if (buffer[i] == ' ')
			count++;

		
		// std::cout << "{" << buffer[i] << "}\n"; 
		// std::cout << "count --> " <<  count << "\n"; 
		
		if (count == 2 && buffer[i] == 'H')
		{
			while (buffer[i] == '\r' && buffer[i + 1] == '\n')
			{
				std::cout << "{" << buffer[i] << "}\n"; 
	
				token += buffer[i];
	
				if (buffer[i] == '\r' && buffer[i + 1] == '\n')
					return ;
				i++;
			}
		}	
		else
			i++;
	}
	
	// std::cout << "token -> " << token << std::endl;
	request.setVersion(token);
}

void	parse_reques( std::string buffer, Request &request )
{
	get_method(buffer, request);
	get_path(buffer, request);		
	get_version(buffer, request);		
	
	std::cout << "Method ----> " << request.getMethod() << std::endl;
	std::cout << "Path ----> " << request.getPath() << std::endl;
	std::cout << "Version ----> " << request.getVersion() << std::endl;
}