#include "request_line.hpp"

// void	get_method( std::string &buffer, Request &request )
// {
// 	size_t		i = 0;

// 	std::string	token;

// 	while (i < buffer.size() && i + 1 < buffer.size() && buffer[i] != ' ')
// 	{
// 		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
// 			return ;
		
// 		token += buffer[i];
// 		i++;
// 	}
	
// 	request.setMethod(token);
// }

// void	get_path( std::string &buffer, Request &request )
// {
// 	size_t		i = 0;

// 	std::string	token;

// 	while (i < buffer.size() && i + 1 < buffer.size())
// 	{
// 		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
// 			return ;
		
// 		if (buffer[i] != '/')
// 			i++;
// 		else
// 		{
// 			token += buffer[i];

// 			if (buffer[i + 1] == ' ')
// 				break ;

// 			i++;
// 		}
// 	}
	
// 	request.setPath(token);
// }

// void	get_version( std::string &buffer, Request &request )
// {
// 	size_t		i = 0;
// 	int			count = 0;

// 	std::string	token;

// 	while (i < buffer.size() && i + 1 < buffer.size())
// 	{
// 		if (buffer[i] == ' ')
// 			count++;
// 		if (buffer[i] == '\r' && buffer[i + 1] == '\n')
// 			break ;
// 		if (count == 2 && buffer[i] == 'H')
// 		{
// 			while (i < buffer.size() && i + 1 < buffer.size())
// 			{	
// 				token += buffer[i];
				
// 				if (buffer[i] == '\r' && buffer[i + 1] == '\n')
// 					break ;
// 				i++;
// 			}
// 		}	
// 		else
// 			i++;
// 	}
// 	request.setVersion(token);
// }

std::vector<std::string>	split(std::string &s, char separator)
{
	std::vector<std::string>	tokens;
	std::string					token;
	std::istringstream			tokenStream(s);

	while(std::getline(tokenStream, token, separator))
		tokens.push_back(token);

	return (tokens);
}

int	parse_method( std::string &method, Request &request )
{
	if (method != "GET" || method != "POST" || method != "DELETE")
		return (400);
	else
	{
		request.setMethod(method);
		request.setStop(false);
		return (0);
	}
}

int	parse_path( std::string &path, Request &request )
{
	// /search?q=hello

	if (path[0] != '/')
		return (400);
	else if (path.find(".."))
		return (403);

	size_t	pos = path.find('?');
	if (pos != std::string::npos)
	{
		request.setQuery(path.substr(pos + 1));
		request.setPath(path.substr(0, pos));
		request.setStop(false);
		return (0);
	}
	
	request.setPath(path);
	request.setStop(false);
	return (0);
}

int	parse_version( std::string &version, Request &request )
{
	if (version == "HTTP/1.1" || version == "HTTP/1.2")
		return (405);
	else if (version != "HTTP/1.0")
		return (400);
	else
	{
		request.setVersion(version);
		request.setStop(false);
		return (0);
	}
}


void	parse_request( std::string &buffer, Request &request )
{
	std::string		first;
	int				i = 0;

	while (buffer[i] != '\r' && buffer[i + 1] != '\n')
	{
		first += buffer[i];
		i++;
	}

	std::vector<std::string>			request_line = split(first, ' ');
	std::vector<std::string>::iterator	it = request_line.begin();

	if (request_line.size() != 3)
	{
		std::cout << "400 Bad Request" << std::endl;
		request.setStop(true);
		return ;
	}

	if (parse_method(*it, request) == 400)
	{
		std::cout << "400 Bad Request" << std::endl;
		request.setStop(true);
		return ;
	}

	if (parse_version(*(it + 2), request) == 400)
	{
		std::cout << "400 Bad Request" << std::endl;
		request.setStop(true);
		return ;
	}
	else if (parse_version(*(it + 2), request) == 405)
	{
		std::cout << "405 Method Not Allowed" << std::endl;
		request.setStop(true);
		return ;
	}

	if (parse_version(*(it + 1), request) == 400)
	{
		std::cout << "400 Bad Request" << std::endl;
		request.setStop(true);
		return ;
	}
	else if (parse_version(*(it + 1), request) == 403)
	{
		std::cout << "403 Forbidden" << std::endl;
		request.setStop(true);
		return ;
	}

	// request.getMethod()
	// Lmouchkil 7it ma3andich ig l headers ?? Anyway i have some problems here !!

	// terminate called after throwing an instance of 'std::logic_error'
	// what():  basic_string: construction from null is not valid
	// make: *** [Makefile:8: all] Aborted (core dumped)
}
