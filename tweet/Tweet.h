#ifndef Tweet_h
#define Tweet_h

#include <string>

	class InvalidUserException : public std::invalid_argument {
		public:
		InvalidUserException(): invalid_argument("") {}
	};

	class Tweet
	{
		public:
		static const std::string NULL_USER;
		Tweet() {};
		Tweet(const std::string& message="", const std::string& user=Tweet::NULL_USER) : message_(message), user_(user) {
			if(!isValid(user_)) throw InvalidUserException();
		};

		bool isValid(const std::string& user) const {
			return '@' == user[0];
		}
		

		Tweet duplicate(Tweet& tweet) 
		{
			return Tweet("","");
		};

		private:
		std::string message_;
		std::string user_;
	};
#endif
