#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  uint64_t space = available_capacity();
  uint64_t toWrite = min(space, static_cast<uint64_t>(data.length()));
  bytespushed+=toWrite;
  for (uint64_t i = 0; i < toWrite; i++) {
      buffer.push(data[i]);
  }
}

void Writer::close()
{
  // Your code here.
    closed = true;

}

bool Writer::is_closed() const
{
  return {closed}; // Your code here.

}

uint64_t Writer::available_capacity() const
{
  return {capacity_ - buffer.size()}; // Your code here.

}

uint64_t Writer::bytes_pushed() const
{
  return {bytespushed}; // Your code here.
}

string_view Reader::peek() const
{
    if (buffer.empty()) {
        return {};
    }
    return string_view(&buffer.front(), 1);
  // asked ChatGpt about how string_view works because i have never used this before
}

void Reader::pop( uint64_t len )
{
  if (is_finished()){
    return;
  }
  uint64_t popSpace = 0 ;
  if(len < static_cast<uint64_t>(buffer.size())) popSpace = len;
  else popSpace = static_cast<uint64_t>(buffer.size());
  bytespopped+=popSpace;

    for(uint64_t i=0;i<popSpace;i++){
      buffer.pop();
    }
}


bool Reader::is_finished() const
{
  return {buffer.empty() && closed}; // Your code here.

}

uint64_t Reader::bytes_buffered() const
{
  return {buffer.size()}; // Your code here.

}

uint64_t Reader::bytes_popped() const
{
return {bytespopped}; // Your code here.

}
