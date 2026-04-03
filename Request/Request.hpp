# ifndef REQUEST_HPP
# define REQUEST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class	Request
{
	private:
		std::string	method;
		std::string	path;
		std::string	version;
	public:
		Request( void );
		Request( const Request &old );
		Request	&operator=( const Request &old );

		void	setMethod( std::string m );
		void	setPath( std::string p );
		void	setVersion( std::string v );

		std::string	getMethod( void ) const;
		std::string	getPath( void ) const;
		std::string	getVersion( void ) const;

		~Request( void );

};

void	parse_reques(std::string buffer, Request &request);

# endif