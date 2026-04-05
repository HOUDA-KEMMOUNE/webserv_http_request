#pragma once

#include "Request.hpp"

void	parse_reques( std::string buffer, Request &request );

void	get_method( std::string buffer, Request &request );
void	get_path( std::string buffer, Request &request );
void	get_version( std::string buffer, Request &request );
