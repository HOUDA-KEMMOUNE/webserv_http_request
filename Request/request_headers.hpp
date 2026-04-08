#pragma once

#include "Request.hpp"

// typedef struct	s_headers
// {
// 	std::string			line
// 	struct s_headers	*next;
// }				t_headers;

void								parse_headers( std::string &buffer, Request &request );
std::string							skip_request_line( std::string &buffer );
void								fill_lines( std::vector<std::string> &lines, std::string &buffer );
std::map<std::string, std::string>	cut_header( std::vector<std::string> &lines );

