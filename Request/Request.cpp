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

// void	parse_reques(std::string buffer, Request &request)
// {
// 	long unsigned int	i = 0;
// 	long unsigned int	j = 0;

// 	std::vector<std::string>	request_line;

// 	// std::string			*tmp = new std::string;

// 	// while (i < buffer.size() && i + 1 < buffer.size())
// 	// {
// 	// 	j = 0;
// 	// 	while (i < buffer.size() && buffer[i] != ' ')	
// 	// 	{
// 	// 		// std::cout << "dhdhh\n";
// 	// 		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
// 	// 		{
// 	// 			std::cout << "ffff\n";
// 	// 			return ;
// 	// 		}

// 	// 		tmp[j] = buffer[i];
// 	// 		std::cout << "tmp --> " << tmp[j] << "\nbuffer --> " << buffer[i] << std::endl;
// 	// 		i++;
// 	// 		j++;
// 	// 	}
// 	// 	request.setMethod(*tmp); // It takes just the first character 
// 	// 	std::cout << "getMethod --> " << request.getMethod() << std::endl;

// 	// 	if (buffer[i] == '\r' && buffer[i + 1] == '\n')
// 	// 	{
// 	// 		std::cout << "GOUGGOOO GAGGAAA\n";
// 	// 		return ;
// 	// 	}
// 	// 	i++;
// 	// }
// }