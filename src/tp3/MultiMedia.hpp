#ifndef TP3_MULTIMEDIA
#define TP3_MULTIMEDIA

#include "./Book.hpp"
#include "./Video.hpp"

class MultiMedia : public Book, public Video {
  public:
	using Book::show;
};

#endif
