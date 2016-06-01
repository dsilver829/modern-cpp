#ifndef Tweet_h
#define Tweet_h

#include <string>

	class Tweet
	{
		public:
		Tweet() {};
		Tweet(std::string, std::string user) {};
		

		Tweet duplicate(Tweet& tweet) 
		{
			return Tweet("","");
		};
	};
#endif
