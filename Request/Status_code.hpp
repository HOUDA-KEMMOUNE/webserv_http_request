#pragma once

// 200 OK
// 201 Created
// 204 No Content

// 400 Bad Request
// 403 Forbidden
// 404 Not Found
// 405 Method Not Allowed
// 413 Payload Too Large

// 500 Internal Server Error
// 501 Not Implemented
// 505 HTTP Version Not Supported

// class	Status_code
// {
// 	private:
// 		enum	status
// 		{
// 			OK = 200,
// 			CREATED = 201,
// 			NO_CONTENT = 204,

// 			BAD_REQUEST = 400,
// 			FORBIDDEN = 403,
// 			NOT_FOUND = 404,
// 			METHOD_NOT_ALLOWED = 405,
// 			PAYLOAD_TOO_LARGE = 413,

// 			INTERNAL_SERVER_ERROR = 500,
// 			NOT_IMPLEMENTED = 501,
// 			HTTP_VERSION_NOT_SUPPORTED = 505
// 		};

// 	public:
		


// };

struct	Status_code
{
	enum	status
	{
		OK = 200,
		CREATED = 201,
		NO_CONTENT = 204,

		BAD_REQUEST = 400,
		FORBIDDEN = 403,
		NOT_FOUND = 404,
		METHOD_NOT_ALLOWED = 405,
		PAYLOAD_TOO_LARGE = 413,
		
		INTERNAL_SERVER_ERROR = 500,
		NOT_IMPLEMENTED = 501,
		HTTP_VERSION_NOT_SUPPORTED = 505
	};
};